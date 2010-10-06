--- ./tools/omusrmsg.c.orig	2010-10-05 02:35:15.216392638 +0000
+++ ./tools/omusrmsg.c	2010-10-05 02:38:59.119754578 +0000
@@ -50,7 +50,7 @@
 #include <assert.h>
 #include <signal.h>
 #include <sys/param.h>
-#include <utmp.h>
+#include <utmpx.h>
 #include <unistd.h>
 #include <sys/uio.h>
 #include <sys/stat.h>
@@ -117,41 +117,6 @@
 ENDdbgPrintInstInfo
 
 
-/**
- * BSD setutent/getutent() replacement routines
- * The following routines emulate setutent() and getutent() under
- * BSD because they are not available there. We only emulate what we actually
- * need! rgerhards 2005-03-18
- */
-#ifdef OS_BSD
-static FILE *BSD_uf = NULL;
-void setutent(void)
-{
-	assert(BSD_uf == NULL);
-	if ((BSD_uf = fopen(_PATH_UTMP, "r")) == NULL) {
-		errmsg.LogError(NO_ERRCODE, "%s", _PATH_UTMP);
-		return;
-	}
-}
-
-struct utmp* getutent(void)
-{
-	static struct utmp st_utmp;
-
-	if(fread((char *)&st_utmp, sizeof(st_utmp), 1, BSD_uf) != 1)
-		return NULL;
-
-	return(&st_utmp);
-}
-
-void endutent(void)
-{
-	fclose(BSD_uf);
-	BSD_uf = NULL;
-}
-#endif  /* #ifdef OS_BSD */
-
-
 /*  WALLMSG -- Write a message to the world at large
  *
  *	Write the specified message to either the entire
@@ -173,27 +138,25 @@
 	int errnoSave;
 	int ttyf;
 	int wrRet;
-	struct utmp ut;
-	struct utmp *uptr;
+	struct utmpx ut;
+	struct utmpx *uptr;
 	struct stat statb;
 	DEFiRet;
 
 	assert(pMsg != NULL);
 
 	/* open the user login file */
-	setutent();
+	setutxent();
 
 	/* scan the user login file */
-	while((uptr = getutent())) {
+	while((uptr = getutxent())) {
 		memcpy(&ut, uptr, sizeof(ut));
 		/* is this slot used? */
-		if(ut.ut_name[0] == '\0')
+		if(ut.ut_user[0] == '\0')
 			continue;
-#ifndef OS_BSD
 		if(ut.ut_type != USER_PROCESS)
 			continue;
-#endif
-		if(!(strncmp (ut.ut_name,"LOGIN", 6))) /* paranoia */
+		if(!(strncmp (ut.ut_user,"LOGIN", 6))) /* paranoia */
 			continue;
 
 		/* should we send the message to this user? */
@@ -203,7 +166,7 @@
 					i = MAXUNAMES;
 					break;
 				}
-				if(strncmp(pData->uname[i], ut.ut_name, UNAMESZ) == 0)
+				if(strncmp(pData->uname[i], ut.ut_user, UNAMESZ) == 0)
 					break;
 			}
 			if(i == MAXUNAMES) /* user not found? */
@@ -239,7 +202,7 @@
 	}
 
 	/* close the user login file */
-	endutent();
+	endutxent();
 	RETiRet;
 }
 
