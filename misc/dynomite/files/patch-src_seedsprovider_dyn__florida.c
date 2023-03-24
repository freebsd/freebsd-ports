- workaround for https://github.com/Netflix/dynomite/issues/818

--- src/seedsprovider/dyn_florida.c.orig	2023-03-24 06:10:53 UTC
+++ src/seedsprovider/dyn_florida.c
@@ -32,7 +32,7 @@
 #endif
 
 static char *floridaIp = NULL;
-static int floridaPort = NULL;
+static int floridaPort = 0;
 static char *request = NULL;
 static int isOsVarEval = 0;
 
