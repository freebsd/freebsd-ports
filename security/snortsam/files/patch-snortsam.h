--- src/snortsam.h.old	2008-08-03 00:08:34.000000000 -0300
+++ src/snortsam.h	2008-08-03 00:10:58.000000000 -0300
@@ -178,10 +178,10 @@
 #define safecopy(dst,src)		_safecp(dst,sizeof(dst),src)
 
 #ifdef WIN32
-#define FWSAMCONFIGFILE			"snortsam.cfg"
-#define FWSAMHISTORYFILE			"snortsam.sta"
+#define FWSAMCONFIGFILE			"/usr/local/etc/snortsam.cfg"
+#define FWSAMHISTORYFILE			"/var/db/snortsam.sta"
 #else
-#define FWSAMCONFIGFILE			"/etc/snortsam.conf"
+#define FWSAMCONFIGFILE			"/usr/local/etc/snortsam.conf"
 #define FWSAMHISTORYFILE			"/var/db/snortsam.state"  
 #endif
 
