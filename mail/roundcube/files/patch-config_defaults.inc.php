--- config/defaults.inc.php.orig	2014-04-06 14:13:09.000000000 +0000
+++ config/defaults.inc.php	2014-04-10 09:08:58.242144399 +0000
@@ -596,8 +596,8 @@
 // connect to a Nox Spell Server when using 'googie' here. Therefore specify the 'spellcheck_uri'
 $config['spellcheck_engine'] = 'googie';
 
-// For locally installed Nox Spell Server or After the Deadline services,
-// please specify the URI to call it.
+// For a locally installed spellcheker, specify the URI to call it, for example:
+// 'http://' . $_SERVER['HTTP_HOST'] . '/spellchecker.php?lang='
 // Get Nox Spell Server from http://orangoo.com/labs/?page_id=72 or
 // the After the Deadline package from http://www.afterthedeadline.com.
 // Leave empty to use the public API of service.afterthedeadline.com
