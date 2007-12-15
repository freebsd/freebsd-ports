--- ./lib/Sys/Filesystem/Solaris.pm.orig	Thu Jun  1 14:10:48 2006
+++ ./lib/Sys/Filesystem/Solaris.pm	Fri Nov 30 11:39:17 2007
@@ -42,7 +42,7 @@
 	my @fstab_keys = qw(device device_to_fsck mount_point fs_vfstype fs_freq mount_at_boot fs_mntops);
 	my @mtab_keys = qw(device mount_point fs_vfstype fs_mntops time);
 
-	my @special_fs = qw(swap proc procfs tmpfs nfs mntfs autofs lofs fd ctfs devfs objfs cachefs);
+	push (@Sys::Filesystem::special_fs, qw(mntfs lofs fd ctfs devfs objfs cachefs));
 	local $/ = "\n";
 
 	# Read the fstab
@@ -57,7 +57,7 @@
 				$vals[$i] = '' unless defined $vals[$i];
 			}
 			$self->{$vals[2]}->{unmounted} = 1;
-			$self->{$vals[2]}->{special} = 1 if grep(/^$vals[3]$/,@special_fs);
+			$self->{$vals[2]}->{special} = 1 if grep(/^$vals[3]$/,@Sys::Filesystem::special_fs);
 			for (my $i = 0; $i < @fstab_keys; $i++) {
 				$self->{$vals[2]}->{$fstab_keys[$i]} = $vals[$i];
 			}
@@ -77,7 +77,7 @@
 			my @vals = split(/\s+/, $_);
 			delete $self->{$vals[1]}->{unmounted} if exists $self->{$vals[1]}->{unmounted};
 			$self->{$vals[1]}->{mounted} = 1;
-			$self->{$vals[1]}->{special} = 1 if grep(/^$vals[2]$/,@special_fs);
+			$self->{$vals[1]}->{special} = 1 if grep(/^$vals[2]$/,@Sys::Filesystem::special_fs);
 			for (my $i = 0; $i < @mtab_keys; $i++) {
 				$self->{$vals[1]}->{$mtab_keys[$i]} = $vals[$i];
 			}
