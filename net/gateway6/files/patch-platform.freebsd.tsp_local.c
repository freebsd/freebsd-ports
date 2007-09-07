--- platform/freebsd/tsp_local.c.orig	2007-04-25 21:31:31.000000000 +0200
+++ platform/freebsd/tsp_local.c	2007-07-12 18:38:01.000000000 +0200
@@ -53,11 +53,11 @@
 #include "tsp_tun.h"   /* freebsd's tun */
 
 
-char *FileName  = "gw6c.conf";
+char *FileName  = "/usr/local/etc/gw6c.conf";
 char *ScriptInterpretor = "/bin/sh";
 char *ScriptExtension = "sh";
 char *ScriptDir = NULL;
-char *TspHomeDir = "/usr/local/etc/gw6";
+char *TspHomeDir = "/usr/local";
 char DirSeparator = '/';
 
 int RootUid = 0;
@@ -77,17 +77,12 @@
 void
 tspSetEnv(char *Variable, char *Value, int Flag)
 {
-	char *buf;
 	if(Value) {
-		int size=(strlen(Variable) + strlen(Value) + 2);
-		if((buf=malloc(size)) == NULL) {
+	       if(setenv(Variable, Value, Flag) == -1) {
 			Display(LOG_LEVEL_3, ELError, "SetEnv", HEX_STR_NOT_ENOUGH_MEM);
 			return;
 		}
-		snprintf(buf, size, "%s=%s", Variable, Value);
-		putenv(buf);
-		Display(LOG_LEVEL_3, ELNotice, "tspSetEnv", "%s", buf);
-		free(buf);
+	        Display(LOG_LEVEL_3, ELNotice, "tspSetEnv", "%s=%s", Variable, Value);
 	}
 }
 
