--- includes/defaults.inc.php.orig	2019-09-03 04:19:02 UTC
+++ includes/defaults.inc.php
@@ -49,20 +49,20 @@ $config['own_hostname'] = 'localhost';
 $config['fping_options']['timeout'] = 500;
 $config['fping_options']['count']   = 3;
 $config['fping_options']['interval'] = 500;
-$config['snmpwalk']                  = '/usr/bin/snmpwalk';
-$config['snmpget']                   = '/usr/bin/snmpget';
-$config['snmpbulkwalk']              = '/usr/bin/snmpbulkwalk';
-$config['snmptranslate']             = '/usr/bin/snmptranslate';
+$config['snmpwalk']                  = '/usr/local/bin/snmpwalk';
+$config['snmpget']                   = '/usr/local/bin/snmpget';
+$config['snmpbulkwalk']              = '/usr/local/bin/snmpbulkwalk';
+$config['snmptranslate']             = '/usr/local/bin/snmptranslate';
 $config['whois']          = '/usr/bin/whois';
-$config['ping']           = '/bin/ping';
-$config['mtr']            = '/usr/bin/mtr';
-$config['nmap']           = '/usr/bin/nmap';
+$config['ping']           = '/dbin/ping';
+$config['mtr']            = '/usr/local/bin/mtr';
+$config['nmap']           = '/usr/local/bin/nmap';
 $config['nagios_plugins'] = '/usr/lib/nagios/plugins';
-$config['ipmitool']       = '/usr/bin/ipmitool';
-$config['virsh']          = '/usr/bin/virsh';
-$config['dot']            = '/usr/bin/dot';
-$config['sfdp']           = '/usr/bin/sfdp';
-$config['nfdump']         = '/usr/bin/nfdump';
+$config['ipmitool']       = '/usr/local/bin/ipmitool';
+$config['virsh']          = '/usr/local/bin/virsh';
+$config['dot']            = '/usr/local/bin/dot';
+$config['sfdp']           = '/usr/local/bin/sfdp';
+$config['nfdump']         = '/usr/local/bin/nfdump';
 
 $config['slow_statistics'] = true;
 // THIS WILL CHANGE TO FALSE IN FUTURE
