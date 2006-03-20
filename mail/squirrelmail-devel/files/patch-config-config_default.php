--- config/config_default.php.orig	Sun Feb 12 02:03:10 2006
+++ config/config_default.php	Wed Mar 15 20:09:20 2006
@@ -469,7 +469,7 @@
  *
  * @global string $data_dir
  */
-$data_dir = '/var/local/squirrelmail/data';
+$data_dir = '/var/spool/squirrelmail/pref/';
 
 /**
  * Attachments directory
@@ -488,7 +488,7 @@
  *    + It should probably be another directory than data_dir.
  * @global string $attachment_dir
  */
-$attachment_dir = $data_dir;
+$attachment_dir = '/var/spool/squirrelmail/attach/';
 
 /**
  * Hash level used for data directory.

