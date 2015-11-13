--- includes/defaults.inc.php.orig	2015-10-16 23:09:41 UTC
+++ includes/defaults.inc.php
@@ -40,7 +40,7 @@ $config['project_name'] = 'LibreNMS';
 $config['project_id']   = strtolower($config['project_name']);
 
 $config['temp_dir']    = '/tmp';
-$config['install_dir'] = '/opt/'.$config['project_id'];
+$config['install_dir'] = '/usr/local/www/'.$config['project_id'];
 $config['log_dir']     = $config['install_dir'].'/logs';
 
 // MySQL extension to use
@@ -50,26 +50,26 @@ $config['db']['extension']       = 'mysq
 $config['own_hostname'] = 'localhost';
 
 // Location of executables
-$config['rrdtool']                  = '/usr/bin/rrdtool';
+$config['rrdtool']                  = '/usr/local/bin/rrdtool';
 $config['rrdtool_version']          = 1.4; // Doesn't need to contain minor numbers.
-$config['fping']                    = '/usr/bin/fping';
-$config['fping6']                   = 'fping6';
+$config['fping']                    = '/usr/local/sbin/fping';
+$config['fping6']                   = '/usr/local/sbin/fping6';
 $config['fping_options']['retries'] = 3;
 $config['fping_options']['timeout'] = 500;
 $config['fping_options']['count']   = 3;
 $config['fping_options']['millisec'] = 200;
-$config['snmpwalk']                  = '/usr/bin/snmpwalk';
-$config['snmpget']                   = '/usr/bin/snmpget';
-$config['snmpbulkwalk']              = '/usr/bin/snmpbulkwalk';
+$config['snmpwalk']                  = '/usr/local/bin/snmpwalk';
+$config['snmpget']                   = '/usr/local/bin/snmpget';
+$config['snmpbulkwalk']              = '/usr/local/bin/snmpbulkwalk';
 $config['whois']          = '/usr/bin/whois';
-$config['ping']           = '/bin/ping';
-$config['mtr']            = '/usr/bin/mtr';
-$config['nmap']           = '/usr/bin/nmap';
-$config['nagios_plugins'] = '/usr/lib/nagios/plugins';
-$config['ipmitool']       = '/usr/bin/ipmitool';
-$config['virsh']          = '/usr/bin/virsh';
-$config['dot']            = '/usr/bin/dot';
-$config['sfdp']           = '/usr/bin/sfdp';
+$config['ping']           = '/sbin/ping';
+$config['mtr']            = '/usr/local/bin/mtr';
+$config['nmap']           = '/usr/local/bin/nmap';
+$config['nagios_plugins'] = '/usr/local/libexec/nagios';
+$config['ipmitool']       = '/usr/local/bin/ipmitool';
+$config['virsh']          = '/usr/local/bin/virsh';
+$config['dot']            = '/usr/local/bin/dot';
+$config['sfdp']           = '/usr/local/bin/sfdp';
 
 // Memcached - Keep immediate statistics
 $config['memcached']['enable'] = false;
