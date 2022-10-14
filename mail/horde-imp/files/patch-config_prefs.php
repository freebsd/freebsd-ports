--- config/prefs.php.orig	2020-08-27 19:34:20 UTC
+++ config/prefs.php
@@ -930,7 +930,7 @@ $_prefs['sourceselect'] = array(
 // You can provide default values this way:
 //   'value' => json_encode(array('source_one', 'source_two'))
 $_prefs['search_sources'] = array(
-    'value' => ''
+    'value' => 'localsql',
 );
 
 // Field(s) to use when expanding addresses
