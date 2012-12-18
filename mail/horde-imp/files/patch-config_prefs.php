--- config/prefs.php.orig	2011-05-03 06:27:23.000000000 -0800
+++ config/prefs.php	2011-05-07 10:06:10.000000000 -0800
@@ -1200,7 +1200,7 @@
 // You can provide default values this way:
 //   'value' => json_encode(array('source_one', 'source_two'))
 $_prefs['search_sources'] = array(
-    'value' => ''
+    'value' => 'localsql',
 );
 
 // Field(s) to use when expanding addresses
