--- src/sympa_wizard.pl	Sat Oct 23 19:50:48 2004
+++ src/sympa_wizard.pl	Sat Oct 23 19:53:21 2004
@@ -308,14 +308,14 @@
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
