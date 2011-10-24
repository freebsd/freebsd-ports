--- ./lib/functions.php.orig	2011-05-11 05:40:18.000000000 -0400
+++ ./lib/functions.php	2011-10-24 09:00:11.000000000 -0400
@@ -1003,8 +1003,9 @@
 	if (defined('DEBUG_ENABLED') && DEBUG_ENABLED && (($fargs=func_get_args())||$fargs='NOARGS'))
 		debug_log('Entered (%%)',1,0,__FILE__,__LINE__,__METHOD__,$fargs);
 
-	# if the array to sort is null or empty
-	if (! $data) return;
+	# if the array to sort is null or empty, or if we have some nasty chars
+	if (! preg_match('/^[a-zA-Z0-9_]+(\([a-zA-Z0-9_,]*\))?$/',$sortby) || ! $data)
+		return;
 
 	static $CACHE = array();
 
