--- ./lib/Sys/Filesystem/Unix.pm.orig	Thu Jun  1 14:10:48 2006
+++ ./lib/Sys/Filesystem/Unix.pm	Fri Nov 30 11:39:17 2007
@@ -41,7 +41,6 @@
 
 	# Default fstab and mtab layout
 	my @keys = qw(fs_spec fs_file fs_vfstype fs_mntops fs_freq fs_passno);
-	my @special_fs = qw(swap proc);
 
 	# Read the fstab
 	my $fstab = new FileHandle;
@@ -54,7 +53,7 @@
 			$self->{$vals[1]}->{mount_point} = $vals[1];
 			$self->{$vals[1]}->{device} = $vals[0];
 			$self->{$vals[1]}->{unmounted} = 1;
-			$self->{$vals[1]}->{special} = 1 if grep(/^$vals[2]$/,@special_fs);
+			$self->{$vals[1]}->{special} = 1 if grep(/^$vals[2]$/,@Sys::Filesystem::special_fs);
 			for (my $i = 0; $i < @keys; $i++) {
 				$self->{$vals[1]}->{$keys[$i]} = $vals[$i];
 			}
