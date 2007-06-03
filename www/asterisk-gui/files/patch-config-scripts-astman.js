--- config/scripts/astman.js.orig	Tue May  1 16:01:00 2007
+++ config/scripts/astman.js	Tue May  1 16:12:08 2007
@@ -25,16 +25,18 @@
 var asterisk_guitoolsversion = "0.7";
 var asterisk_guiversion = "$Revision: 817 $";
 var asterisk_guifbt = 3000; // Feedback msg time
-var asterisk_scriptsFolder = "/var/lib/asterisk/scripts/" ; /* Directory for gui scripts (graphs.sh, for example) */
-var asterisk_ConfigBkpPath = "/var/lib/asterisk/gui_configbackups/" ;
-var asterisk_Sounds_path = "/var/lib/asterisk/sounds/";
+var asterisk_prefix = "%%PREFIX%%/"  // "/" for typical linux instalation
+var asterisk_varlib = asterisk_prefix + "share/asterisk/" // /var/lib/astersik/ for linux
+var asterisk_scriptsFolder = asterisk_varlib + "scripts/" ; /* Directory for gui scripts (graphs.sh, for example) */
+var asterisk_ConfigBkpPath = asterisk_varlib + "gui_configbackups/" ;
+var asterisk_Sounds_path = asterisk_varlib + "sounds/";
 var asterisk_menusRecord_path = asterisk_Sounds_path + "record/";
 var asterisk_guiSysInfo = "sh " + asterisk_scriptsFolder + "gui_sysinfo" ;
 var asterisk_guiSysInfo_output = "./sysinfo_output.html";
-var asterisk_guiZapscan = "/sbin/zapscan.bin" ;
+var asterisk_guiZapscan = asterisk_prefix + "sbin/zapscan.bin" ;
 var asterisk_rawmanPath = "../../rawman" ;
 var asterisk_guiConfigFile = "guipreferences.conf"; // will be created in asterisk_configfolder, if the file does not exist 
-var asterisk_configfolder = "/etc/asterisk/";
+var asterisk_configfolder = asterisk_prefix + "etc/asterisk/";
 var asterisk_guiListFiles = "sh " + asterisk_scriptsFolder + "listfiles" ;
 
 var sortbynames = false;
@@ -1521,7 +1523,7 @@
 	this.doConfig = function(t, box) {
 		if( t[0].headers['message'] && t[0].headers['message'] == "Config file not found" ){
 			if( box.config_file == "zapscan.conf" || box.config_file == "contactinfo.conf" || box.config_file == "jingle.conf" || box.config_file == "providers.conf" ){
-				parent.astmanEngine.run_tool("/bin/touch /etc/asterisk/"+box.config_file, function(){ window.location.href = window.location.href ; } );
+				parent.astmanEngine.run_tool("touch "+ asterisk_configfolder + box.config_file, function(){ window.location.href = window.location.href ; } );
 				return ;
 			} else {
 				alert( "Asterisk says it cannot find a required config file (" + box.config_file + ") \n You will be now redirected to the main page !" );
