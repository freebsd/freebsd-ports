--- messagesAdmin.php.orig	2007-06-14 19:00:15 UTC
+++ messagesAdmin.php
@@ -55,6 +55,7 @@ if (! Auth::isMailAdmin()) {
   CmnFns::do_error_box(translate('Access Denied'));
 
 } else {
+  $content_type = (CmnFns::get_ctype() ? CmnFns::get_ctype() : 'A');
   // Draw search engine
   printSearchEngine($content_type, $_SERVER['PHP_SELF'], 1);
   echo '<br>';
