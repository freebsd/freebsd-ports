--- encoder.php.orig	Thu May  8 16:58:25 2003
+++ encoder.php	Thu May  8 17:00:00 2003
@@ -1,25 +1,25 @@
-#! /usr/bin/php -f
+#! %%LOCALBASE%%/bin/php -f
 
 <?php
 function mmcache_encoder_usage() {
-  echo "Usage:\tphp -q encoder.php [options] source_file_name\n";
-  echo       "\tphp -q encoder.php [options] source_file_name...\n";
-  echo       "\tphp -q encoder.php [options] source_directory_name...\n\n";
+  echo "Usage:\tencoder [options] source_file_name\n";
+  echo       "\tencoder [options] source_file_name...\n";
+  echo       "\tencoder [options] source_directory_name...\n\n";
   echo "Options:\n";
   echo "\t-s suffix\n\t\tencode files only with following suffix (default is \"php\")\n";
   echo "\t-a\n\t\tencode all files (no by default)\n";
   echo "\t-l\n\t\tfollow symbolic links (no by default)\n";
   echo "\t-r\n\t\tencode directories recursively (no by default)\n";
   echo "\t-c\n\t\tcopy files those shouldn't be encoded (no by default)\n";
-  echo "\t-f\n\t\toverfrite existing files (no by default)\n";
+  echo "\t-f\n\t\toverwrite existing files (no by default)\n";
   echo "\t-o target\n\t\tIf you encode only one script then 'target' specifyes an output\n";
   echo               "\t\tfile name. If you encode directory or several files at once\n";
   echo               "\t\tthen 'target' specifyes an output directory name.\n";
   echo "\nExamples:\n";
-  echo "\tphp -q encoder.php some_file.php\n";
-  echo "\tphp -q encoder.php some_file.php -o some_encoded_file.php\n";
-  echo "\tphp -q encoder.php *.php -o some_dir\n";
-  echo "\tphp -q encoder.php ~/public_html/x -rcf -sphp -sinc -o ~/public_html/y\n";
+  echo "\tencoder some_file.php\n";
+  echo "\tencoder some_file.php -o some_encoded_file.php\n";
+  echo "\tencoder *.php -o some_dir\n";
+  echo "\tencoder ~/public_html/x -rcf -sphp -sinc -o ~/public_html/y\n";
   echo "\n";
   exit();
 }
