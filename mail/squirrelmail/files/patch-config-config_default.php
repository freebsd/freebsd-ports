--- config/config_default.php.orig	Thu Aug 21 03:14:08 2003
+++ config/config_default.php	Tue Jan 13 00:57:57 2004
@@ -220,7 +220,7 @@
  *   $data_dir = SM_PATH . 'data/';
  */
 global $data_dir;
-$data_dir = SM_PATH . 'data/';
+$data_dir = '/var/spool/squirrelmail/pref/';
 
 /**
  * Path to directory used for storing attachments while a mail is
@@ -236,7 +236,7 @@
  *    + It should probably be another directory than data_dir.
  */
 global $attachment_dir;
-$attachment_dir = "$data_dir";
+$attachment_dir = '/var/spool/squirrelmail/attach/';
 
 /* Hash level used for data directory. */
 global $dir_hash_level;
