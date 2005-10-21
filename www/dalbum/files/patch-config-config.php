--- config/config.php.orig	Fri Oct 21 13:43:21 2005
+++ config/config.php	Fri Oct 21 13:44:15 2005
@@ -242,7 +242,7 @@
 $g_bGDSetMemoryLimit=true;
 
 // ImageMagick convert location and command lines (if $g_sResizeMethod="IM")
-$g_sConvertPath="/usr/X11R6/bin/convert";
+$g_sConvertPath="%%LOCALBASE%%/bin/convert";
 $g_sThumbnailImArg="$g_sConvertPath -filter Lanczos -quality {$g_sThumbnailQuality} "
                     . "-resize {$g_sThumbnailXSize}x{$g_sThumbnailYSize} "
                     . "-sharpen 2 +profile APP1 #src# #target#";
