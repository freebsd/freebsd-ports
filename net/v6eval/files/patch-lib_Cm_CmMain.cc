--- lib/Cm/CmMain.cc.orig	2009-08-27 09:10:04.000000000 +0900
+++ lib/Cm/CmMain.cc	2013-05-04 04:59:43.000000000 +0900
@@ -48,13 +48,17 @@
 #include <string.h>
 #include <stdlib.h>
 #include <unistd.h>
+#include <sys/param.h>
+#if __FreeBSD_version <= 900006
 #include <utmp.h>
+#else
+#include <utmpx.h>
+#endif
 #include <time.h>
 #include <pwd.h>
 #include <sys/time.h>
 #include <sys/types.h>
 #include <sys/resource.h>
-#include <sys/param.h>
 extern int causeStopSignals[];
 static int stopSingals[]={SIGINT,SIGQUIT,SIGTERM,0};
 extern void applicationMain(CmMain*);
@@ -129,21 +133,37 @@
 
 //----------------------------------------------------------------------
 // æ„≥≤≤Ú¿œæ Û∫Ó¿Æ
+#if __FreeBSD_version <= 900006
 static struct utmp *myUtmpEnt(FILE *in,struct utmp *u) {
-	int s=ttyslot();
+	int s = 0;
 	if(s<0||fseek(in,sizeof(struct utmp)*s,0)<0||
 		fread(u,sizeof(struct utmp),1,in)==0) {return 0;}
 	return u;}
 void CmMain::makeCatch2Eye(STR p) {
 static char catch2[]=" on %*.*s:%-*.*s from %*.*s";
 	struct utmp ux[1], *u; FILE *in;
-	if((in=fopen("/etc/utmp","r"))==NULL) {return;}
+	if((in=fopen(_PATH_UTMP,"r"))==NULL) {return;}
 	u=myUtmpEnt(in,ux); fclose(in);
 	if(!u) {return;}
 #define A(a)sizeof(a),sizeof(a),a
 	sprintf(p,catch2,A(u->ut_line),A(u->ut_name),A(u->ut_host));
 #undef A
 	return;}
+#else
+void CmMain::makeCatch2Eye(STR p) {
+static char catch2[]=" on %*.*s:%-*.*s from %*.*s";
+	struct utmpx ux, *u;
+	memset(&ux, 0, sizeof(ux));
+	ux.ut_type = USER_PROCESS; 
+	snprintf(ux.ut_user, sizeof(ux.ut_user), "%d", getuid());
+	u = getutxuser(ux.ut_user);
+	if (u == NULL)
+		return;
+#define A(a)sizeof(a),sizeof(a),a
+	sprintf(p, catch2, A(u->ut_line), A(u->ut_user), A(u->ut_host));
+#undef A
+	return;}
+#endif
 void CmMain::makeCatchEye(const STR pgmName) {
 static char catch1[]="@(#) %02d/%02d/%02d %02d:%02d:%02d %s STARTED by %s@%s";
 	time_t now=time(0); struct tm *m=localtime(&now);
