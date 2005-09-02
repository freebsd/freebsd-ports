--- tumgreyspfsupp.py.orig	Wed Aug 31 21:39:42 2005
+++ tumgreyspfsupp.py	Wed Aug 31 21:41:24 2005
@@ -10,15 +10,15 @@
 
 
 #  default values
-defaultConfigFilename = '/var/local/tumgreyspf/config/tumgreyspf.conf'
+defaultConfigFilename = '%%PREFIX%%/etc/tumgreyspf.conf'
 defaultConfigData = {
 		'debugLevel' : 0,
 		'defaultSeedOnly' : 0,
 		'defaultAllowTime' : 600,
-		'configPath' : 'file:///var/local/lib/tumgreyspf/config',
-		'greylistDir' : '/var/local/lib/tumgreyspf/data',
-		'blackholeDir' : '/var/local/lib/tumgreyspf/blackhole',
-		'spfqueryPath' : '/usr/local/lib/tumgreyspf/spfquery',
+		'configPath' : 'file:///%%TUMGREYSPF_DIR%%/config',
+		'greylistDir' : '%%TUMGREYSPF_DIR%%/data',
+		'blackholeDir' : '%%TUMGREYSPF_DIR%%/blackhole',
+		'spfqueryPath' : '%%PREFIX%%/bin/spfquery',
 		}
 
 
