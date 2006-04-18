--- config.php.orig	Thu Mar 16 22:16:54 2006
+++ config.php	Tue Apr 18 03:56:19 2006
@@ -96,7 +96,7 @@
 // see either httpd.conf User directive or ps -ef to see which user
 // apache runs under, then set mode 700 on directory and change owner
 // to this user
-define("UPLOADDIRECTORY", '/var/spool/ipplanuploads');
+define("UPLOADDIRECTORY", '/var/spool/ipplan/uploads');
 
 // default country code ("" for none)
 define("DEFAULTCOUNTRY", "US");
@@ -109,7 +109,7 @@
 // not work if php is running in safemode. probing and scanning may 
 // also be against policy for your site!
 //define("NMAP", '');
-define("NMAP", '/usr/bin/nmap');
+define("NMAP", '%%LOCALBASE%%/bin/nmap');
 
 // helpdesk email address
 define("HELPDESKEMAIL", "helpdesk@mydomain.com");
@@ -186,7 +186,7 @@
 //   this will usually be the user under which Apache runs. If the 
 // permissions are not correct, the files will be created in the
 // system temp directory, usually /tmp
-define("DNSEXPORTPATH", '/tmp/dns/');
+define("DNSEXPORTPATH", '/var/spool/ipplan/dnsexport/');
 
 // dnsslaveonly is the default setting for when creating new zones. If your
 // dns server only serves as a slave for most of your zones, it's helpful
@@ -202,7 +202,7 @@
 
 // export path where DHCP files in XML format will be output ready for
 // transformation into DHCP file for various DHCP servers
-define("DHCPEXPORTPATH", '/tmp/dhcp/');
+define("DHCPEXPORTPATH", '/var/spool/ipplan/dncpexport/');
 
 // This string identifies ip addresses that belong in the DHCP pool
 define("DHCPRESERVED", "Reserved - DHCP pool");
