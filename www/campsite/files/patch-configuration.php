--- implementation/management/configuration.php.orig	Sat Jan  6 20:28:51 2007
+++ implementation/management/configuration.php	Wed Jan 10 22:59:30 2007
@@ -46,7 +46,7 @@
 $Campsite['IMAGE_PREFIX'] = 'cms-image-';
 $Campsite['IMAGEMAGICK_INSTALLED'] = true;
 $Campsite['THUMBNAIL_MAX_SIZE'] = 64;
-$Campsite['THUMBNAIL_COMMAND'] = 'convert -sample '
+$Campsite['THUMBNAIL_COMMAND'] = 'gm convert -sample '
 		.$Campsite['THUMBNAIL_MAX_SIZE'].'x'.$Campsite['THUMBNAIL_MAX_SIZE'];
 $Campsite['THUMBNAIL_DIRECTORY'] = $Campsite['IMAGE_DIRECTORY'].'/thumbnails/';
 $Campsite['THUMBNAIL_BASE_URL'] = $Campsite['WEBSITE_URL'].'/images/thumbnails/';
