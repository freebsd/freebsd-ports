--- lib/Video/DVDRip/Project.pm.orig	Fri Jan  3 15:22:00 2003
+++ lib/Video/DVDRip/Project.pm		Fri Jan  3 15:24:34 2003
@@ -272,7 +272,7 @@
 	my $dir;
 
 	if ( $mode eq 'rip' or $mode eq 'dvd' ) {
-		$dir = $self->config('dvd_mount_point');
+		$dir = $self->config('dvd_device');
 
 	} elsif ( $mode eq 'dvd_image' ) {
 		$dir = $self->dvd_image_dir;
@@ -445,7 +445,7 @@
 	
 	return 1 if $self->rip_mode eq 'dvd_image';
 	
-	my $dvd_mount_point = $self->config('dvd_mount_point');
+	my $dvd_mount_point = $self->config('dvd_device');
 
 	return 1 if -d "$dvd_mount_point/video_ts";
 	return 1 if -d "$dvd_mount_point/VIDEO_TS";
@@ -457,7 +457,7 @@
 	
 	return 1 if $self->rip_mode eq 'dvd_image';
 
-	my $dvd_mount_point = $self->config('dvd_mount_point');
+	my $dvd_mount_point = $self->config('dvd_device');
 
 	$self->log ("Mounting DVD at $dvd_mount_point");
 
@@ -476,7 +476,7 @@
 	
 	return 1 if $self->rip_mode eq 'dvd_image';
 
-	my $dvd_mount_point = $self->config('dvd_mount_point');
+	my $dvd_mount_point = $self->config('dvd_device');
 
 	my $mount = qx[ umount $dvd_mount_point 2>&1 ];
 
