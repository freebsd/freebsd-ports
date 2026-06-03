--- telnet.c.orig	2025-05-15 15:31:27 UTC
+++ telnet.c
@@ -228,7 +228,7 @@ void TelProcessLine(char **bufpp, size_t *lenp)
 	*lenp = 0;
 }
 
-int DoTelnet(char *buf, size_t *lenp, int f)
+int DoTelnet(char *buf, int *lenp, int f)
 {
 	int echo = !fore->w_telropts[TO_ECHO];
 	int cmode = fore->w_telropts[TO_SGA];
