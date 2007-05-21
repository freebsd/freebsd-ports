--- config/config_default.php.orig	Wed May  9 16:48:26 2007
+++ config/config_default.php	Wed May  9 16:49:20 2007
@@ -464,7 +464,7 @@
  *
  * @global string $data_dir
  */
-$data_dir = '/var/local/squirrelmail/data/';
+$data_dir = '/var/spool/squirrelmail/pref/';
 
 /**
  * Attachments directory
@@ -482,7 +482,7 @@
  *    + It should probably be another directory than data_dir.
  * @global string $attachment_dir
  */
-$attachment_dir = '/var/local/squirrelmail/attach/';
+$attachment_dir = '/var/spool/squirrelmail/attach/';
 
 /**
  * Hash level used for data directory.
