--- ./lib/Sys/Filesystem/Freebsd.pm.orig	Mon Sep 18 11:07:46 2006
+++ ./lib/Sys/Filesystem/Freebsd.pm	Mon Sep 18 11:10:30 2006
@@ -26,20 +26,33 @@
 use FileHandle;
 use Carp qw(croak);
 
+# For access to the getfsstat system call
+require 'sys/syscall.ph';
+require 'sys/mount.ph';
+
 use vars qw($VERSION);
 $VERSION = '1.05' || sprintf('%d', q$Revision: 364 $ =~ /(\d+)/g);
 
+my $sizeof;
+if ( &STATFS_VERSION == 0x20030518 ) {
+	$sizeof = 472; # The size in bytes of the statfs structure
+} else {
+	croak "The statfs strucuture changed version (" . &STATFS_VERSION . ")\n";
+}
+# unpack format, we want the 3rd and the last 3 fields.
+my $format = 'x8L' . 'x268' . 'A' . &MFSNAMELEN . ('A' . &MNAMELEN ) x 2 ;
+  
 sub new {
 	ref(my $class = shift) && croak 'Class name required';
 	my %args = @_;
 	my $self = { };
 
 	$args{fstab} ||= '/etc/fstab';
-	$args{mtab} ||= '/etc/mtab';
-	$args{xtab} ||= '/etc/lib/nfs/xtab';
+	# $args{mtab} ||= '/etc/mtab';  # Does not exist on FreeBSD
+	$args{xtab} ||= '/var/db/mountdtab';
 
 	my @keys = qw(fs_spec fs_file fs_vfstype fs_mntops fs_freq fs_passno);
-	my @special_fs = qw(swap proc devpts tmpfs);
+	my @special_fs = qw(swap procfs devpts devfs tmpfs);
 
 	# Read the fstab
 	my $fstab = new FileHandle;
@@ -60,24 +73,42 @@
 		croak "Unable to open fstab file ($args{fstab})\n";
 	}
 
-	# Read the mtab
-	my $mtab = new FileHandle;
-	if ($mtab->open($args{mtab})) {
-		while (<$mtab>) {
-			next if (/^\s*#/ || /^\s*$/);
-			my @vals = split(/\s+/, $_);
-			delete $self->{$vals[1]}->{unmounted} if exists $self->{$vals[1]}->{unmounted};
-			$self->{$vals[1]}->{mounted} = 1;
-			$self->{$vals[1]}->{mount_point} = $vals[1];
-			$self->{$vals[1]}->{device} = $vals[0];
-			$self->{$vals[1]}->{special} = 1 if grep(/^$vals[2]$/,qw(swap proc devpts tmpfs));
-			for (my $i = 0; $i < @keys; $i++) {
-				$self->{$vals[1]}->{$keys[$i]} = $vals[$i];
-			}
+	# Get the number of mounted fileystems we have
+	my $buf = '';
+	my $cnt = syscall(&SYS_getfsstat, $buf, length $buf, &MNT_NOWAIT);
+
+	# Fix a bug on some 5.x systems, the previous syscall may return 0...
+	$cnt = 20 if ( ! $cnt );
+
+	# Preallocate the buffer memory per the syscall() requreiments
+	$buf = ' ' x ( $sizeof * $cnt );
+
+	if ( ($cnt=syscall(&SYS_getfsstat, $buf, length $buf, &MNT_NOWAIT)) ) {
+		for (my ($i) = 0; $i < $cnt; $i++) {
+
+			my $offset = ($i)? 'x' . ($i * $sizeof): '';
+			my @vals = unpack ( $offset . $format, $buf);
+
+			delete $self->{$vals[3]}->{unmounted} if exists $self->{$vals[3]}->{unmounted};
+			$self->{$vals[3]}->{mounted} = 1;
+			$self->{$vals[3]}->{mount_point} = $vals[3];
+			$self->{$vals[3]}->{device} = $vals[2];
+			$self->{$vals[3]}->{special} = 1 if grep(/^$vals[1]$/,@special_fs);
+
+			$self->{$vals[3]}->{fs_spec} = $vals[2];
+			$self->{$vals[3]}->{fs_file} = $vals[3];
+			$self->{$vals[3]}->{fs_vfstype} = $vals[1];
+			$self->{$vals[3]}->{fs_mntops} = 
+				($vals[0] & &MNT_RDONLY)? 'ro': 'rw';
+			$self->{$vals[3]}->{fs_mntops} .= ',noexec'
+				if ($vals[0] & &MNT_NOEXEC);
+			$self->{$vals[3]}->{fs_mntops} .= ',nosuid'
+				if ($vals[0] & &MNT_NOSUID);
+			$self->{$vals[3]}->{fs_mntops} .= ',nodev'
+				if ($vals[0] & &MNT_NODEV);
 		}
-		$mtab->close;
 	} else {
-		croak "Unable to open mtab file ($args{mtab})\n";
+		croak "Unable to retrieve mounted filesystem information\n";
 	}
 
 	# Bless and return
