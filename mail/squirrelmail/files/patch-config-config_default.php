--- config/config_default.php.orig	Wed Jun  2 10:49:41 2004
+++ config/config_default.php	Wed Jun  2 10:50:21 2004
@@ -442,7 +442,7 @@
  *   $data_dir = SM_PATH . 'data/';
  * @global string $data_dir
  */
-$data_dir = SM_PATH . 'data/';
+$data_dir = '/var/spool/squirrelmail/pref/';
 
 /**
  * Attachments directory
@@ -460,7 +460,7 @@
  *    + It should probably be another directory than data_dir.
  * @global string $attachment_dir
  */
-$attachment_dir = $data_dir;
+$attachment_dir = '/var/spool/squirrelmail/attach/';
 
 /**
  * Hash level used for data directory.
