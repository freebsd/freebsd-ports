--- ./lib/Sys/Filesystem/Aix.pm.orig	Thu Jun  1 14:10:48 2006
+++ ./lib/Sys/Filesystem/Aix.pm	Fri Nov 30 11:39:17 2007
@@ -37,7 +37,7 @@
 	$args{fstab} ||= '/etc/filesystems';
 
 	my @fstab_keys = qw(account boot check dev free mount nodename size type vfs vol log);
-	my @special_fs = qw(swap procfs proc tmpfs nfs mntfs autofs);
+	push (@Sys::Filesystem::special_fs, qw(procfs mntfs));
 
 	# Read the fstab
 	my $fstab = new FileHandle;
@@ -53,18 +53,43 @@
 
 			# This matches a filesystem attribute
 			} elsif (my ($key,$value) = $_ =~ /^\s*([a-z]{3,8})\s+=\s+"?(.+)"?\s*$/) {
-				$self->{$current_filesystem}->{$key} = $value;
 				$self->{$current_filesystem}->{unmounted} = -1; # Unknown mount state?
 				if ($key eq 'vfs') {
-					if (grep(/^$value$/, @special_fs)) {
+					if (grep(/^$value$/, @Sys::Filesystem::special_fs)) {
 						$self->{$current_filesystem}->{special} = 1;
 					}
+					$self->{$current_filesystem}->{type} = $value;
+				} else {
+					$self->{$current_filesystem}->{$key} = $value
+						if ( $key ne 'type');
 				}
 			}
 		}
 		$fstab->close;
 	} else {
 		croak "Unable to open fstab file ($args{fstab})\n";
+	}
+
+	# /dev/hd4 / jfs Apr 02 13:45 rw,log=/dev/hd8
+	if ($fstab->open('/usr/sbin/mount -p|')) {
+		while (<$fstab>) {
+			my ($device, $mount_point, $fstype);
+			grep (m|^\s+(/\S+)\s+(/\S+)\s+(\S+)| 
+				&& ($device=$1, $mount_point=$2, $fstype=$3), $_);
+
+			if ( defined $mount_point ) {
+				$self->{$mount_point}->{mounted} = 1;
+				$self->{$mount_point}->{device} = $device;
+				$self->{$mount_point}->{mount_point} = $mount_point;
+				$self->{$mount_point}->{fs_vfstype} = $fstype;
+				if (grep(/^$fstype$/, @Sys::Filesystem::special_fs)) {
+						$self->{$mount_point}->{special} = 1;
+				}
+			}
+		}
+		$fstab->close;
+	} else {
+		croak "Unable to run mount command\n";
 	}
 
 	bless($self,$class);
