--- encoder.php.orig	Fri Jul 25 10:21:09 2003
+++ encoder.php	Mon Jul 28 13:04:19 2003
@@ -1,10 +1,12 @@
+#!%%LOCALBASE%%/bin/php -f
+
 <?php
 $web_error = "";
 
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
@@ -16,10 +18,10 @@
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
