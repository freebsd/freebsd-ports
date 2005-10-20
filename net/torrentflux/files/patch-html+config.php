--- html/config.php.orig	Tue Sep 27 21:03:12 2005
+++ html/config.php	Fri Jan 21 05:03:28 2005
@@ -28,18 +28,18 @@
 /**************************************************************************/
 // Check the adodb/drivers/ directory for support for your database
 // you may choose from many (mysql is the default)
-$cfg["db_type"] = "mysql";       // mysql, postgres7 view adodb/drivers/
-$cfg["db_host"] = "localhost";   // DB host computer name or IP
-$cfg["db_name"] = "torrentflux"; // Name of the Database
-$cfg["db_user"] = "user";        // username for your MySQL database
-$cfg["db_pass"] = "password";    // password for database
+$cfg["db_type"] = "sqlite";                    // mysql, postgres7 view adodb/drivers/
+$cfg["db_host"] = "%%DATABASE%%/tf.db"; // path to sqlite database
+$cfg["db_name"] = "";                          // unused for sqlite
+$cfg["db_user"] = "";                          // unused for sqlite
+$cfg["db_pass"] = "";                          // unused for sqlite
 /**************************************************************************/
 
 /**************************************************************************/
 // Define the PATH where the downloads will go (note that it ends with a / [slash])
 // Note this can be anywhere (not where TorrentFlux is installed)
-// must be chmod'd to 777 (DO NOT MAKE THIS THE PATH TO YOUR PHP FILES!)
-$cfg["path"] = "/usr/local/torrent/";
+// must be chown'd to www (DO NOT MAKE THIS THE PATH TO YOUR PHP FILES!)
+$cfg["path"] = "%%DOWNLOADS%%/";
 /**************************************************************************/
 
 /**************************************************************************/
@@ -47,13 +47,13 @@
 // Only change the path to this file as needed.
 // You may use 'btphptornado.py' for BitTornado Client or 'btphptorrent.py'
 // for the original BitTorrent Client (read the INSTALL file for more).
-$cfg["btphpbin"] = "/usr/local/TF_BitTornado/btphptornado.py";
+$cfg["btphpbin"] = "%%PREFIX%%/libexec/btphptornado.py";
 /**************************************************************************/
 
 /**************************************************************************/
 // Specify the btshowmetainfo.py file name
 // Use the full path to this file -- change as needed.
-$cfg["btshowmetainfo"] = "/usr/local/TF_BitTornado/btshowmetainfo.py";
+$cfg["btshowmetainfo"] = "%%LOCALBASE%%/bin/btshowmetainfo.py";
 /**************************************************************************/
 
 // Set advanced_start to true if you want to allow users to use the advanced
@@ -84,6 +84,9 @@
 // Enable the Suprnova.org Search Form on Home Page
 $cfg["enable_search"] = true;
 
+// Calculate directory size in directory browsing
+$cfg["show_directory_size"] = true;
+
 // Enable users to download files from the directory browsing
 $cfg["enable_file_download"] = true;
 
@@ -93,9 +96,6 @@
 // Enable showing the average server load over the last 15 minutes from /proc/loadavg file
 $cfg["show_server_load"] = true;
 
-// The path to your loadavg file
-$cfg["loadavg_path"] = "/proc/loadavg";
-
 // days to keep audit actions in DB. (owner ship of torrent based on this)
 $cfg['days_to_keep'] = 30;
 
@@ -160,6 +160,9 @@
 // DO NOT Edit below this line unless you know what you're doing.
 // ***************************************************************************
 // ***************************************************************************
+
+// Set a reasonable umask
+umask(0022);
 
 $cfg["pagetitle"] = "TorrentFlux";
 
