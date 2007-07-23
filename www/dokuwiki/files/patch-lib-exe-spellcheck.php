--- lib/exe/spellcheck.php.orig	2007-07-23 14:40:45.000000000 +0800
+++ lib/exe/spellcheck.php	2007-07-23 14:39:30.000000000 +0800
@@ -272,7 +272,7 @@
  * Just send data back as received for UTF-8 testing
  */
 function spell_utf8test(){
-  print $_POST['data'];
+  print substr( $_POST['data'], 0, 3 );
 }
 
 /**
