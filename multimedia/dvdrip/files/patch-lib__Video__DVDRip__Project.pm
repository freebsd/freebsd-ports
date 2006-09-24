--- lib/Video/DVDRip/Project.pm.orig	Wed Aug 16 16:34:38 2006
+++ lib/Video/DVDRip/Project.pm	Sat Sep 23 15:32:16 2006
@@ -345,24 +345,27 @@
     return \%symlinks;
 }
 
-sub get_mount_dir_from_mtab {
+sub get_mount_dir_from_fstab {
     my $self = shift;
-    my ( $dvd_device, $mtab_file ) = @_;
+    my ( $dvd_device, $fstab_file ) = @_;
 
     my $symlinks_href = $self->resolve_symlinks($dvd_device);
 
-    open( my $fh, $mtab_file )
-        or die "can't read $mtab_file";
+    open(FSTABINPUT, $fstab_file )
+	or die "can't read $fstab_file";
 
     my $mount_dir;
-    while ( my $line = <$fh> ) {
-        my ( $device, $dir ) = split( /\s+/, $line );
-        if ( $symlinks_href->{$device} ) {
-            $mount_dir = $dir;
-            last;
-        }
+    while (<FSTABINPUT>) {
+	my ($dev, $mnt, $fstyp, $opt, $dump, $pass) = split;
+	next if $dev =~ /^#/;
+	if (( $dev eq $symlinks_href->{$dev} ) ||
+	   ( $mnt eq $symlinks_href->{$dev} )  ||
+	   ( $fstyp eq 'cd9660' )) {
+	    $mount_dir = $mnt;
+	    last;
+	}
     }
-    close $fh;
+    close (FSTABINPUT);
 
     return $mount_dir;
 }
@@ -373,8 +376,7 @@
     my $dvd_device = $self->dvd_device;
 
     my $dvd_mount_point
-        = $self->get_mount_dir_from_mtab( $dvd_device,  "/etc/mtab" )
-        || $self->get_mount_dir_from_mtab( $dvd_device, "/etc/fstab" );
+        = $self->get_mount_dir_from_fstab( $dvd_device, "/etc/fstab" );
 
     return $dvd_mount_point;
 }
