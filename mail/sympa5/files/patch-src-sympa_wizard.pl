--- src/sympa_wizard.pl.orig	Thu Aug 24 17:05:36 2006
+++ src/sympa_wizard.pl	Wed Sep 27 10:53:39 2006
@@ -92,13 +92,13 @@
                'advice' =>''},
 
 	      {'name' => 'arc_path',
-	       'default' => '--DIR--/arc',
+	       'default' => '--DIR--/sympa/arc',
 	       'query' => 'Where to store HTML archives',
 	       'file' => 'wwsympa.conf','edit' => '1',
                'advice' =>'Better if not in a critical partition'},
 	      
 	      {'name' => 'bounce_path',
-	       'default' => '--DIR--/bounce',
+	       'default' => '--DIR--/sympa/bounce',
 	       'query' => 'Where to store bounces',
 	       'file' => 'wwsympa.conf',
                'advice' =>'Better if not in a critical partition'},
@@ -186,7 +186,7 @@
 	      {'title' => 'Tuning'},
 	      	      
 
-	      {'name' => 'cache\_list\_config',
+	      {'name' => 'cache_list_config',
 	       'default' => 'none',
 	       'query' => 'Use of binary version of the list config structure on disk: none | binary_file',
 	       'file' => 'sympa.conf','edit' => '1',
@@ -316,14 +316,14 @@
 	       'advice' =>''},
 
               {'name' => 'mhonarc',
-	       'default' => '/usr/bin/mhonarc',
+	       'default' => '/usr/local/bin/mhonarc',
 	       'query' => 'Path to MhOnarc mail2html pluggin',
 	       'file' => 'wwsympa.conf','edit' => '1',
 	       'advice' =>'This is required for HTML mail archiving'},
 
 	      {'title' => 'S/MIME pluggin'},
 	      {'name' => 'openssl',
-	       'sample' => '/usr/local/bin/openssl',
+	       'sample' => '/usr/bin/openssl',
 	       'query' => 'Path to OpenSSL',
 	       'file' => 'sympa.conf','edit' => '1',
 	       'advice' =>'Sympa knowns S/MIME if openssl is installed'},
