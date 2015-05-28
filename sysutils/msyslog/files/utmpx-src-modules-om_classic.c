--- src/modules/om_classic.c.orig	2010-01-25 16:36:53.000000000 -0800
+++ src/modules/om_classic.c
@@ -66,7 +66,7 @@
 #include <string.h>
 #include <syslog.h>
 #include <unistd.h>
-#include <utmp.h>
+#include <utmpx.h>
 #include <netdb.h>
 /* if _PATH_UTMP isn't defined, define it here... */
 #ifndef _PATH_UTMP
@@ -100,7 +100,7 @@
 struct om_classic_ctx {
 	int	fd;
 	union {
-		char    f_uname[MAXUNAMES][UT_NAMESIZE+1];
+		char    f_uname[MAXUNAMES][MAXLOGNAME+2];
 		struct {
 			char    f_hname[MAXHOSTNAMELEN];
 			struct sockaddr		f_addr;
@@ -396,9 +396,9 @@
 		for (i = 0; i < MAXUNAMES && *p; i++) {
 			for (q = p; *q && *q != ','; )
 				q++;
-			(void)strncpy(c->f_un.f_uname[i], p, UT_NAMESIZE);
-			if ((q - p) > UT_NAMESIZE)
-				c->f_un.f_uname[i][UT_NAMESIZE] = '\0';
+			(void)strncpy(c->f_un.f_uname[i], p, MAXLOGNAME+1);
+			if ((q - p) > MAXLOGNAME+1)
+				c->f_un.f_uname[i][MAXLOGNAME+1] = '\0';
 			else
 				c->f_un.f_uname[i][q - p] = '\0';
 			while (*q == ',' || *q == ' ')
@@ -456,24 +456,19 @@
 {
 	static int reenter;			/* avoid calling ourselves */
 	FILE *uf;
-	struct utmp ut;
+	struct utmpx ut;
 	int i;
 	char *p;
 	char line[sizeof(ut.ut_line) + 1];
 
 	if (reenter++)
 		return;
-	if ( (uf = fopen(_PATH_UTMP, "r")) == NULL) {
-		dprintf(MSYSLOG_SERIOUS, "om_classic: error opening "
-		    "%s\n", _PATH_UTMP);
-		reenter = 0;
-		return;
-	}
+
 	/* NOSTRICT */
 	while (fread(&ut, sizeof(ut), 1, uf) == 1) {
 
 #ifndef __linux__
-		if (ut.ut_name[0] == '\0')
+		if (ut.ut_user[0] == '\0')
 #else
 		if ((ut.ut_type != USER_PROCESS && ut.ut_type != LOGIN_PROCESS) ||
 		    ut.ut_line[0] == ':' /* linux logs users that are not logged in (?!) */)
@@ -494,7 +489,7 @@
 		for (i = 0; i < MAXUNAMES; i++) {
 			if (!c->f_un.f_uname[i][0])
 				break;
-			if (!strncmp(c->f_un.f_uname[i], ut.ut_name,
+			if (!strncmp(c->f_un.f_uname[i], ut.ut_user,
 			    UT_NAMESIZE)) {
 				if ((p = ttymsg(iov, 6, line, TTYMSGTIME))
 								!= NULL) {
