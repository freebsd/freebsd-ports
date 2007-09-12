--- Build.PL.orig	2007-06-20 03:11:06.000000000 +0800
+++ Build.PL	2007-09-12 09:34:41.000000000 +0800
@@ -36,10 +36,10 @@
     web_files => \@web_dirs,
     build_web_directory => 'root',
     install_web_directories =>  { 
-        'default' => '/home/httpd/html/gantry',
-        'prod'    => '/home/httpd/html/gantry',
-        'dev'     => '/home/httpd/html/gantry',
-        'tim'     => '/home/tkeefer/httpd/html/gantry' 
+        'default' => '/usr/local/www/gantry',
+        'prod'    => '/usr/local/www/gantry',
+        'dev'     => '/usr/local/www/gantry',
+        'tim'     => '/usr/local/www/gantry'
     },
     create_makefile_pl => 'passthrough',
     license            => 'perl',
@@ -105,7 +105,7 @@
 if ( not -d $template_path ) {
     my $make_path = $build->y_n(
         "$template_path does not exist, should I make it?",
-        'y'
+        'n'
     );
 
     if ( $make_path ) {
