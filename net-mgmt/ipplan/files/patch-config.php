--- config.php.org	Sat Nov 20 12:07:00 2004
+++ config.php	Thu Dec  2 13:47:54 2004
@@ -96,7 +96,7 @@
 // not work if php is running in safemode. probing and scanning may 
 // also be against policy for your site!
 //define("NMAP", "");
-define("NMAP", "/usr/bin/nmap");
+define("NMAP", "/usr/local/bin/nmap");
 
 //-------------------------START OF REGISTRAR---------------------------
 
@@ -137,7 +137,7 @@
 //   this will usually be the user under which Apache runs. If the 
 // permissions are not correct, the files will be created in the
 // system temp directory, usually /tmp
-define("DNSEXPORTPATH", "/tmp/dns/");
+define("DNSEXPORTPATH", "/tmp/ipplan-dns/");
 //-------------------------START OF LANGUAGES---------------------------
 
 // which languages are supported by ipplan - see TRANSLATIONS to 
