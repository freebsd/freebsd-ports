--- master.c.orig	Sat Jan  6 15:07:32 2001
+++ master.c	Sat Jan  6 15:06:54 2001
@@ -37,7 +37,7 @@
 #include "master.h"
 #include "lib.h"
 
-#define	MASTER_CONFIG		"/etc/dnrd/master"
+#define	MASTER_CONFIG		"%%PREFIX%%/etc/dnrd/master"
 #define	PACKET_ASSEMBLYSIZE	600
 
 
