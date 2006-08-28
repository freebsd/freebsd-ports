--- src/jispman.h.orig	Sun Apr 10 19:03:54 2005
+++ src/jispman.h	Mon Aug 28 20:11:39 2006
@@ -25,6 +25,8 @@
 #include "jisp.h"
 
 typedef struct _KfJispManager {
+	GHashTable *jisps;
+	GList *patterns;
 } KfJispManager;
 
 /**
