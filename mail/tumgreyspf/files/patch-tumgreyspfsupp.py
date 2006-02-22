--- tumgreyspfsupp.py.orig	Thu Feb  2 18:48:25 2006
+++ tumgreyspfsupp.py	Wed Feb 22 10:20:40 2006
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
+		'configPath' : 'file://%%TUMGREYSPF_DIR%%/config',
+		'greylistDir' : '%%TUMGREYSPF_DIR%%/data',
+		'blackholeDir' : '%%TUMGREYSPF_DIR%%/blackhole',
+		'spfqueryPath' : '%%LOCALBASE%%/bin/spfquery',
 		'ignoreLastByte' : 0,
 		}
 
