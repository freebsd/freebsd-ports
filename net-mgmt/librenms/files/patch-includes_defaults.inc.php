--- includes/defaults.inc.php.orig	2017-12-31 20:48:36 UTC
+++ includes/defaults.inc.php
@@ -48,19 +48,21 @@ $config['fping_options']['retries'] = 3;
 $config['fping_options']['timeout'] = 500;
 $config['fping_options']['count']   = 3;
 $config['fping_options']['millisec'] = 200;
-$config['snmpwalk']                  = '/usr/bin/snmpwalk';
-$config['snmpget']                   = '/usr/bin/snmpget';
-$config['snmpbulkwalk']              = '/usr/bin/snmpbulkwalk';
+$config['snmpwalk']                  = '/usr/local/bin/snmpwalk';
+$config['snmpget']                   = '/usr/local/bin/snmpget';
+$config['snmpbulkwalk']              = '/usr/local/bin/snmpbulkwalk';
 $config['snmptranslate']             = '/usr/bin/snmptranslate';
 $config['whois']          = '/usr/bin/whois';
-$config['ping']           = '/bin/ping';
-$config['mtr']            = '/usr/bin/mtr';
-$config['nmap']           = '/usr/bin/nmap';
+$config['ping']           = '/sbin/ping';
+$config['mtr']            = '/usr/local/bin/mtr';
+$config['nmap']           = '/usr/local/bin/nmap';
 $config['nagios_plugins'] = '/usr/lib/nagios/plugins';
-$config['ipmitool']       = '/usr/bin/ipmitool';
-$config['virsh']          = '/usr/bin/virsh';
-$config['dot']            = '/usr/bin/dot';
-$config['sfdp']           = '/usr/bin/sfdp';
+$config['rrdtool']        = '/usr/local/bin/rrdtool';
+$config['rrdtool_version'] = 1.7;
+$config['ipmitool']       = '/usr/local/bin/ipmitool';
+$config['virsh']          = '/usr/lacal/bin/virsh';
+$config['dot']            = '/usr/local/bin/dot';
+$config['sfdp']           = '/usr/local/bin/sfdp';
 
 $config['slow_statistics'] = true;
 // THIS WILL CHANGE TO FALSE IN FUTURE
