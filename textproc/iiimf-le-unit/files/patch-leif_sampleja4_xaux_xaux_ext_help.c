--- leif/sampleja4/xaux/xaux_ext_help.c	Fri Jun 27 11:41:21 2003
+++ leif/sampleja4/xaux/xaux_ext_help.c	Wed Feb 16 20:43:43 2005
@@ -66,7 +66,7 @@
 
 #else /* defined(USE_DTACTIONINVOKE) */
 
-#define DTACTION_CMD    "/usr/dt/bin/dtaction"
+#define DTACTION_CMD    "/usr/local/bin/dtaction"
 
 static int help_available = 0;
 static char tmp_file[256];
