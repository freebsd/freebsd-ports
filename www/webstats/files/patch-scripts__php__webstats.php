--- scripts/php/webstats.php	Sun Jul 15 21:50:15 2001
+++ scripts/php/webstats.php	Sun Feb 16 18:10:25 2003
@@ -4,7 +4,7 @@
 <?php 
 include "class.inifile.php";
 //we read the serverwide config file
-$serverwideini = new IniFile("/etc/webstats/webstats.ini");
+$serverwideini = new IniFile("%%PREFIX%%/etc/webstats/webstats.ini");
 $servername = $serverwideini->value("misc","SERVERNAME","not defined/config file not found?");
 $vhost_directory = $serverwideini->value("rmagic","VHOSTDIR","VHOSTDIR not defined/config file not found?");
 $logs_directory = $serverwideini->value("rmagic","LOGSDIR","LOGSDIR not defined/config file not found?");
