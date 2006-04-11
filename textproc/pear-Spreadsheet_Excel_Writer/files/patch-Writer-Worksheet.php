--- Writer/Worksheet.php.orig	Sat Nov 19 14:47:01 2005
+++ Writer/Worksheet.php	Tue Apr 11 17:06:18 2006
@@ -1230,7 +1230,7 @@
     */
     function _XF(&$format)
     {
-        if ($format != 0) {
+        if (is_object($format)) {
             return($format->getXfIndex());
         } else {
             return(0x0F);
