--- includes/defaults.inc.php.orig	2014-11-21 12:33:07 UTC
+++ includes/defaults.inc.php
@@ -17,7 +17,7 @@ error_reporting(E_ERROR);
 
 // Default directories
 
-$config['install_dir']   = "/opt/observium";
+$config['install_dir']   = "/usr/local/www/observium";
 #$config['html_dir']      = $config['install_dir'] . "/html";
 #$config['rrd_dir']       = $config['install_dir'] . "/rrd";
 #$config['log_file']      = $config['install_dir'] . "/observium.log";
@@ -29,27 +29,27 @@ $config['install_dir']   = "/opt/observi
 
 // Location of executables
 
-$config['rrdtool']        = "/usr/bin/rrdtool";
-$config['fping']          = "/usr/bin/fping";
-$config['fping6']         = "/usr/bin/fping6";
-$config['snmpwalk']       = "/usr/bin/snmpwalk";
-$config['snmpget']        = "/usr/bin/snmpget";
-$config['snmpbulkget']    = "/usr/bin/snmpbulkget";
-$config['snmpbulkwalk']   = "/usr/bin/snmpbulkwalk";
-$config['snmptranslate']  = "/usr/bin/snmptranslate";
+$config['rrdtool']        = "/usr/local/bin/rrdtool";
+$config['fping']          = "/usr/local/sbin/fping";
+$config['fping6']         = "/usr/local/sbin/fping6";
+$config['snmpwalk']       = "/usr/local/bin/snmpwalk";
+$config['snmpget']        = "/usr/local/bin/snmpget";
+$config['snmpbulkget']    = "/usr/local/bin/snmpbulkget";
+$config['snmpbulkwalk']   = "/usr/local/bin/snmpbulkwalk";
+$config['snmptranslate']  = "/usr/local/bin/snmptranslate";
 $config['whois']          = "/usr/bin/whois";
-$config['mtr']            = "/usr/bin/mtr";
-$config['nmap']           = "/usr/bin/nmap";
-$config['nagios_plugins'] = "/usr/lib/nagios/plugins";
-$config['ipmitool']       = "/usr/bin/ipmitool";
-$config['virsh']          = "/usr/bin/virsh";
-$config['dot']            = "/usr/bin/dot";
-$config['unflatten']      = "/usr/bin/unflatten";
-$config['neato']          = "/usr/bin/neato";
-$config['sfdp']           = "/usr/bin/sfdp";
-$config['svn']            = "/usr/bin/svn";
-#$config['git']            = '/usr/bin/git'; // Not enabled by default, used in show device config feature for git-enabled repos
-$config['wmic']           = "/bin/wmic";
+$config['mtr']            = "/usr/local/sbin/mtr";
+$config['nmap']           = "/usr/local/bin/nmap";
+$config['nagios_plugins'] = "/usr/local/libexec/nagios";
+$config['ipmitool']       = "/usr/local/bin/ipmitool";
+$config['virsh']          = "/usr/local/bin/virsh";
+$config['dot']            = "/usr/local/bin/dot";
+$config['unflatten']      = "/usr/local/bin/unflatten";
+$config['neato']          = "/usr/local/bin/neato";
+$config['sfdp']           = "/usr/local/bin/sfdp";
+$config['svn']            = "/usr/local/bin/svn";
+#$config['git']            = "/usr/local/bin/git"; // Not enabled by default, used in show device config feature for git-enabled repos
+$config['wmic']           = "/usr/local/bin/wmic";
 $config['file']           = "/usr/bin/file";
 
 // RRD Format Settings
