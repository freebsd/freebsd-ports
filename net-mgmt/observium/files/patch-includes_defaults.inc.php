--- includes/defaults.inc.php.orig	2024-12-23 01:13:57 UTC
+++ includes/defaults.inc.php
@@ -77,7 +77,7 @@ $config['db']['debug'] = FALSE;       // If TRUE store
 
 // Default directories
 
-#$config['install_dir']   = "/opt/observium";
+#$config['install_dir']   = "/usr/local/www/observium";
 #$config['html_dir']      = $config['install_dir'] . "/html";
 #$config['rrd_dir']       = $config['install_dir'] . "/rrd";
 #$config['template_dir']  = $config['install_dir'] . "/templates";
@@ -93,26 +93,26 @@ $config['db']['debug'] = FALSE;       // If TRUE store
 
 // Location of executables
 
-$config['rrdtool']       = "/usr/bin/rrdtool";
-$config['fping']         = "/usr/bin/fping";
-$config['fping6']        = "/usr/bin/fping6"; // Note, for version 4+ not required
-$config['snmpwalk']      = "/usr/bin/snmpwalk";
-$config['snmpget']       = "/usr/bin/snmpget";
-$config['snmpgetnext']   = "/usr/bin/snmpgetnext";
-$config['snmpbulkget']   = "/usr/bin/snmpbulkget";
-$config['snmpbulkwalk']  = "/usr/bin/snmpbulkwalk";
-$config['snmptranslate'] = "/usr/bin/snmptranslate";
+$config['rrdtool']       = "/usr/local/bin/rrdtool";
+$config['fping']         = "/usr/local/sbin/fping";
+$config['fping6']        = "/usr/local/sbin/fping6"; // Note, for version 4+ not required
+$config['snmpwalk']      = "/usr/local/bin/snmpwalk";
+$config['snmpget']       = "/usr/local/bin/snmpget";
+$config['snmpgetnext']   = "/usr/local/bin/snmpgetnext";
+$config['snmpbulkget']   = "/usr/local/bin/snmpbulkget";
+$config['snmpbulkwalk']  = "/usr/local/bin/snmpbulkwalk";
+$config['snmptranslate'] = "/usr/local/bin/snmptranslate";
 $config['whois']         = "/usr/bin/whois";     // ip_whois()
-$config['mtr']           = "/usr/bin/mtr";       // is_pingable()
-$config['ipmitool']      = "/usr/bin/ipmitool";  // ipmi module
-$config['virsh']         = "/usr/bin/virsh";     // libvirt module
-$config['wmic']          = "/bin/wmic";          // wmi_cmd()
-$config['dot']           = "/usr/bin/dot";       // Graphviz, networkmap (only)
+$config['mtr']           = "/usr/local/sbin/mtr";       // is_pingable()
+$config['ipmitool']      = "/usr/local/bin/ipmitool";  // ipmi module
+$config['virsh']         = "/usr/local/bin/virsh";     // libvirt module
+$config['wmic']          = "/usr/local/bin/wmic";          // wmi_cmd()
+$config['dot']           = "/usr/local/bin/dot";       // Graphviz, networkmap (only)
 //$config['unflatten']     = "/usr/bin/unflatten"; // Graphviz, networkmap (only, unused)
 //$config['neato']         = "/usr/bin/neato";     // Graphviz (unused)
 //$config['sfdp']          = "/usr/bin/sfdp";      // Graphviz, networkmap (only, unused)
-$config['svn']           = "/usr/bin/svn";
-$config['git']           = "/usr/bin/git"; // Used in show device config feature for git-enabled repos and rancid >= 3.2
+$config['svn']           = "/usr/local/bin/svn";
+$config['git']           = "/usr/local/bin/git"; // Used in show device config feature for git-enabled repos and rancid >= 3.2
 //$config['nmap']          = "/usr/bin/nmap"; // unused
 //$config['file']          = "/usr/bin/file"; // unused
 //$config['wc']            = "/usr/bin/wc";   // unused
