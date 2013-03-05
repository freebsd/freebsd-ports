--- lib/Cm/CmMain.cc.orig	2003-10-23 13:37:30.000000000 +0900
+++ lib/Cm/CmMain.cc	2013-03-06 04:38:49.000000000 +0900
@@ -47,7 +47,11 @@
 #include <string.h>
 #include <stdlib.h>
 #include <unistd.h>
+#if __FreeBSD_version <= 900006
 #include <utmp.h>
+#else
+#include <utmpx.h>
+#endif
 #include <time.h>
 #include <pwd.h>
 #include <sys/time.h>
@@ -129,7 +133,7 @@
 //----------------------------------------------------------------------
 // æ„≥≤≤Ú¿œæ Û∫Ó¿Æ
 static struct utmp *myUtmpEnt(FILE *in,struct utmp *u) {
-	int s=ttyslot();
+	int s = 0;
 	if(s<0||fseek(in,sizeof(struct utmp)*s,0)<0||
 		fread(u,sizeof(struct utmp),1,in)==0) {return 0;}
 	return u;}
