--- implementation/management/configuration.php.orig	Tue Jul 11 22:45:21 2006
+++ implementation/management/configuration.php	Tue Jul 11 22:59:36 2006
@@ -47,7 +47,7 @@
 $Campsite['ADMIN_IMAGE_BASE_URL'] = $Campsite['WEBSITE_URL'].'/css';
 $Campsite['IMAGE_PREFIX'] = 'cms-image-';
 $Campsite['IMAGEMAGICK_INSTALLED'] = true;
-$Campsite['THUMBNAIL_COMMAND'] = 'convert -sample 64x64';
+$Campsite['THUMBNAIL_COMMAND'] = 'gm convert -sample 64x64';
 $Campsite['THUMBNAIL_DIRECTORY'] = $Campsite['IMAGE_DIRECTORY'].'/thumbnails/';
 $Campsite['THUMBNAIL_BASE_URL'] = $Campsite['WEBSITE_URL'].'/images/thumbnails/';
 $Campsite['THUMBNAIL_PREFIX'] = 'cms-thumb-';
