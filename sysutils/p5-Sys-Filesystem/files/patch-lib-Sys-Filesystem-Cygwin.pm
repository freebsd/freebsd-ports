--- ./lib/Sys/Filesystem/Cygwin.pm.orig	Thu Jun  1 14:10:48 2006
+++ ./lib/Sys/Filesystem/Cygwin.pm	Fri Nov 30 11:39:17 2007
@@ -36,7 +36,7 @@
 
 	local $/ = "\n";
 	my @keys = qw(fs_spec fs_file fs_vfstype fs_mntops);
-	my @special_fs = qw(swap proc devpts tmpfs);
+	push (@Sys::Filesystem::special_fs, qw(devpts));
 
 	my $mtab = new FileHandle;
 	if ($mtab->open('mount|')) {
@@ -44,7 +44,7 @@
 			next if (/^\s*#/ || /^\s*$/);
 			if (my @vals = $_ =~ /^\s*(.+?) on (\/.+?) type (\S+) \((\S+)\)\s*$/) {
 				$self->{$vals[1]}->{mounted} = 1;
-				$self->{$vals[1]}->{special} = 1 if grep(/^$vals[2]$/,@special_fs);
+				$self->{$vals[1]}->{special} = 1 if grep(/^$vals[2]$/,@Sys::Filesystem::special_fs);
 				for (my $i = 0; $i < @keys; $i++) {
 					$self->{$vals[1]}->{$keys[$i]} = $vals[$i];
 				}
