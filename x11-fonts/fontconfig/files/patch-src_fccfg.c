--- src/fccfg.c.orig	Mon Mar 31 15:11:28 2003
+++ src/fccfg.c	Mon Mar 31 15:12:06 2003
@@ -1265,8 +1265,8 @@
     return FcConfigSubstituteWithPat (config, p, 0, kind);
 }
 
-#ifndef FONTCONFIG_PATH
-#define FONTCONFIG_PATH	"/etc/fonts"
+#ifndef CONFDIR
+#define CONFDIR	"/etc/fonts"
 #endif
 
 #ifndef FONTCONFIG_FILE
@@ -1343,7 +1343,7 @@
 	}
     }
     
-    dir = (FcChar8 *) FONTCONFIG_PATH;
+    dir = (FcChar8 *) CONFDIR;
     path[i] = malloc (strlen ((char *) dir) + 1);
     if (!path[i])
 	goto bail1;
