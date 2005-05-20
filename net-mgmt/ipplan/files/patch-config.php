--- config.php.orig	Wed May 11 00:26:32 2005
+++ config.php	Wed May 11 19:30:43 2005
@@ -89,7 +89,7 @@
 // see either httpd.conf User directive or ps -ef to see which user
 // apache runs under, then set mode 700 on directory and change owner
 // to this user
-define("UPLOADDIRECTORY", "/var/spool/ipplanuploads");
+define("UPLOADDIRECTORY", "/var/spool/ipplan/uploads");
 
 // default country code ("" for none)
 define("DEFAULTCOUNTRY", "US");
@@ -102,7 +102,7 @@
 // not work if php is running in safemode. probing and scanning may 
 // also be against policy for your site!
 define("NMAP", "");
-//define("NMAP", "/usr/bin/nmap");
+//define("NMAP", "/usr/local/bin/nmap");
 
 //-------------------------START OF REGISTRAR---------------------------
 
@@ -145,7 +145,7 @@
 //   this will usually be the user under which Apache runs. If the 
 // permissions are not correct, the files will be created in the
 // system temp directory, usually /tmp
-define("DNSEXPORTPATH", "/tmp/dns/");
+define("DNSEXPORTPATH", "/var/spool/ipplan/exportdns/");
 
 // dnsslaveonly is the default setting for when creating new zones. If your
 // dns server only serves as a slave for most of your zones, it's helpful
