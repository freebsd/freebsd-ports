--- tumgreyspfsupp.py.orig	Tue May 30 07:24:11 2006
+++ tumgreyspfsupp.py	Tue Jun 13 22:00:23 2006
@@ -9,15 +9,15 @@
 
 
 #  default values
-defaultConfigFilename = '/var/local/lib/tumgreyspf/config/tumgreyspf.conf'
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
 
