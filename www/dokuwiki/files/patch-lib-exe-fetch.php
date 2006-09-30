--- lib/exe/fetch.php.bak	Fri Mar 10 04:32:34 2006
+++ lib/exe/fetch.php	Fri Sep 29 12:54:09 2006
@@ -21,8 +21,8 @@
   //get input
   $MEDIA  = getID('media',false); // no cleaning - maybe external
   $CACHE  = calc_cache($_REQUEST['cache']);
-  $WIDTH  = $_REQUEST['w'];
-  $HEIGHT = $_REQUEST['h'];
+  $WIDTH  = (int) $_REQUEST['w'];
+  $HEIGHT = (int) $_REQUEST['h'];
   list($EXT,$MIME) = mimetype($MEDIA);
   if($EXT === false){
     $EXT  = 'unknown';
@@ -198,6 +198,10 @@
   $info  = getimagesize($file);
   if(!$h) $h = round(($w * $info[1]) / $info[0]);
 
+  /*
+   * This is the fix for http://bugs.splitbrain.org/?do=details&id=924
+   */
+  if($w > 2000 || $h > 2000) return $file;
 
   //cache
   $local = getCacheName($file,'.media.'.$w.'x'.$h.'.'.$ext);
