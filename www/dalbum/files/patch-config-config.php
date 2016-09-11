--- config/config.php.orig	2005-09-20 21:40:56 UTC
+++ config/config.php
@@ -242,7 +242,7 @@ $g_bGDVer2=(fixed_phpversion()>"4.3");
 $g_bGDSetMemoryLimit=true;
 
 // ImageMagick convert location and command lines (if $g_sResizeMethod="IM")
-$g_sConvertPath="/usr/X11R6/bin/convert";
+$g_sConvertPath="%%LOCALBASE%%/bin/convert";
 $g_sThumbnailImArg="$g_sConvertPath -filter Lanczos -quality {$g_sThumbnailQuality} "
                     . "-resize {$g_sThumbnailXSize}x{$g_sThumbnailYSize} "
                     . "-sharpen 2 +profile APP1 #src# #target#";
