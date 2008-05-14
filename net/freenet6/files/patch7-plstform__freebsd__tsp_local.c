--- platform/freebsd/tsp_local.c.orig	2004-03-30 23:27:35.000000000 +0200
+++ platform/freebsd/tsp_local.c	2007-07-11 13:40:26.000000000 +0200
@@ -74,21 +74,16 @@
 /* freebsd specific to setup an env variable */
 
 void
 tspSetEnv(char *Variable, char *Value, int Flag)
 {
-	char *buf;
 	if(Value) {
-		int size=(strlen(Variable) + strlen(Value) + 2);
-		if((buf=malloc(size)) == NULL) {
+	        if(setenv(Variable, Value, Flag) == -1) {
 			Display(1, ELError, "SetEnv", "Not enough memory!");
 			return;
 		}
-		snprintf(buf, size, "%s=%s", Variable, Value);
-		putenv(buf);
-		Display(2, ELNotice, "tspSetEnv", "%s", buf);
-		free(buf);
+		Display(2, ELNotice, "tspSetEnv", "%s=%s", Variable, Value);
 	}
 }
 
 
 /* tspSetupTunnel() will callback here */


