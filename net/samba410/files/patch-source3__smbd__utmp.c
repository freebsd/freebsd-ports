--- source3/smbd/utmp.c.orig	2018-01-15 12:41:58 UTC
+++ source3/smbd/utmp.c
@@ -257,7 +257,7 @@ static char *uw_pathname(TALLOC_CTX *ctx
  Update utmp file directly.  No subroutine interface: probably a BSD system.
 ****************************************************************************/
 
-static void pututline_my(const char *uname, struct utmp *u, bool claim)
+static void pututline_my(const char *uname, STRUCT_UTMP *u, bool claim)
 {
 	DEBUG(1,("pututline_my: not yet implemented\n"));
 	/* BSD implementor: may want to consider (or not) adjusting "lastlog" */
@@ -271,7 +271,7 @@ static void pututline_my(const char *una
  Credit: Michail Vidiassov <master@iaas.msu.ru>
 ****************************************************************************/
 
-static void updwtmp_my(const char *wname, struct utmp *u, bool claim)
+static void updwtmp_my(const char *wname, STRUCT_UTMP *u, bool claim)
 {
 	int fd;
 	struct stat buf;
@@ -303,7 +303,7 @@ static void updwtmp_my(const char *wname
 	if ((fd = open(wname, O_WRONLY|O_APPEND, 0)) < 0)
 		return;
 	if (fstat(fd, &buf) == 0) {
-		if (write(fd, (char *)u, sizeof(struct utmp)) != sizeof(struct utmp))
+		if (write(fd, (char *)u, sizeof(STRUCT_UTMP)) != sizeof(STRUCT_UTMP))
 		(void) ftruncate(fd, buf.st_size);
 	}
 	(void) close(fd);
@@ -314,12 +314,12 @@ static void updwtmp_my(const char *wname
  Update via utmp/wtmp (not utmpx/wtmpx).
 ****************************************************************************/
 
-static void utmp_nox_update(struct utmp *u, bool claim)
+static void utmp_nox_update(STRUCT_UTMP *u, bool claim)
 {
 	char *uname = NULL;
 	char *wname = NULL;
 #if defined(PUTUTLINE_RETURNS_UTMP)
-	struct utmp *urc;
+	STRUCT_UTMP *urc;
 #endif /* PUTUTLINE_RETURNS_UTMP */
 
 	uname = uw_pathname(talloc_tos(), "utmp", ut_pathname);
@@ -376,127 +376,52 @@ static void utmp_nox_update(struct utmp 
 	}
 }
 
-/****************************************************************************
- Copy a string in the utmp structure.
-****************************************************************************/
 
-static void utmp_strcpy(char *dest, const char *src, size_t n)
-{
-	size_t len = 0;
 
-	memset(dest, '\0', n);
-	if (src)
-		len = strlen(src);
-	if (len >= n) {
-		memcpy(dest, src, n);
-	} else {
-		if (len)
-			memcpy(dest, src, len);
-	}
-}
+
 
 /****************************************************************************
  Update via utmpx/wtmpx (preferred) or via utmp/wtmp.
 ****************************************************************************/
 
-static void sys_utmp_update(struct utmp *u, const char *hostname, bool claim)
+static void sys_utmp_update(STRUCT_UTMP *u, const char *hostname, bool claim)
 {
-#if !defined(HAVE_UTMPX_H)
-	/* No utmpx stuff.  Drop to non-x stuff */
-	utmp_nox_update(u, claim);
-#elif !defined(HAVE_PUTUTXLINE)
-	/* Odd.  Have utmpx.h but no "pututxline()".  Drop to non-x stuff */
-	DEBUG(1,("utmp_update: have utmpx.h but no pututxline() function\n"));
-	utmp_nox_update(u, claim);
-#elif !defined(HAVE_GETUTMPX)
-	/* Odd.  Have utmpx.h but no "getutmpx()".  Drop to non-x stuff */
-	DEBUG(1,("utmp_update: have utmpx.h but no getutmpx() function\n"));
-	utmp_nox_update(u, claim);
-#elif !defined(HAVE_UPDWTMPX)
-	/* Have utmpx.h but no "updwtmpx()".  Drop to non-x stuff */
-	DEBUG(1,("utmp_update: have utmpx.h but no updwtmpx() function\n"));
-	utmp_nox_update(u, claim);
-#else
-	char *uname = NULL;
-	char *wname = NULL;
-	struct utmpx ux, *uxrc;
-
-	getutmpx(u, &ux);
-
-#if defined(HAVE_UX_UT_SYSLEN)
-	if (hostname)
-		ux.ut_syslen = strlen(hostname) + 1;	/* include end NULL */
-	else
-		ux.ut_syslen = 0;
-#endif
-#if defined(HAVE_UT_UT_HOST)
-	utmp_strcpy(ux.ut_host, hostname, sizeof(ux.ut_host));
-#endif
-
-	uname = uw_pathname(talloc_tos(), "utmpx", ux_pathname);
-	wname = uw_pathname(talloc_tos(), "wtmpx", wx_pathname);
-	if (uname && wname) {
-		DEBUG(2,("utmp_update: uname:%s wname:%s\n", uname, wname));
-	}
+	STRUCT_UTMP *urc;
 
-	/*
-	 * Check for either uname or wname being empty.
-	 * Some systems, such as Redhat 6, have a "utmpx.h" which doesn't
-	 * define default filenames.
-	 * Also, our local installation has not provided an override.
-	 * Drop to non-x method.  (E.g. RH6 has good defaults in "utmp.h".)
-	 */
-	if (!uname || !wname || (strlen(uname) == 0) || (strlen(wname) == 0)) {
-		utmp_nox_update(u, claim);
-	} else {
-		utmpxname(uname);
-		setutxent();
-		uxrc = pututxline(&ux);
-		endutxent();
-		if (uxrc == NULL) {
-			DEBUG(2,("utmp_update: pututxline() failed\n"));
-			return;
-		}
-		updwtmpx(wname, &ux);
+	setutxent();
+	urc = pututxline(u);
+	endutxent();
+	if (urc == NULL) {
+		DEBUG(2,("utmp_update: pututxline() failed\n"));
+		return;
 	}
-#endif /* HAVE_UTMPX_H */
 }
 
 #if defined(HAVE_UT_UT_ID)
 /****************************************************************************
  Encode the unique connection number into "ut_id".
 ****************************************************************************/
-
-static int ut_id_encode(int i, char *fourbyte)
+static void ut_id_encode(char *buf, int id, size_t buf_size)
 {
-	int nbase;
-	const char *ut_id_encstr = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
-
-/*
- * 'ut_id_encstr' is the character set on which modulo arithmetic is done.
- * Example: digits would produce the base-10 numbers from '001'.
- */
-	nbase = strlen(ut_id_encstr);
+	const char ut_id_encstr[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
 
-	fourbyte[0] = ut_id_encstr[i % nbase];
-	i /= nbase;
-	fourbyte[1] = ut_id_encstr[i % nbase];
-	i /= nbase;
-	fourbyte[3] = ut_id_encstr[i % nbase];
-	i /= nbase;
-	fourbyte[2] = ut_id_encstr[i % nbase];
-	i /= nbase;
+	int nbase = sizeof(ut_id_encstr) - 1;
+	/*
+	 * 'ut_id_encstr' is the character set on which modulo arithmetic is done.
+	 * Example: digits would produce the base-10 numbers from '001'.
+	 */
 
-	/* we do not care about overflows as i is a random number */
-	return 0;
+	for(int i = 0; i < buf_size; i++) {
+		buf[i] = ut_id_encstr[id % nbase];
+		id /= nbase;
+	}
 }
 #endif /* defined(HAVE_UT_UT_ID) */
 
-
 /*
   fill a system utmp structure given all the info we can gather
 */
-static bool sys_utmp_fill(struct utmp *u,
+static bool sys_utmp_fill(STRUCT_UTMP *u,
 			const char *username, const char *hostname,
 			const char *id_str, int id_num)
 {
@@ -509,16 +434,16 @@ static bool sys_utmp_fill(struct utmp *u
 	 *	rather than to try to detect and optimise.
 	 */
 #if defined(HAVE_UT_UT_USER)
-	utmp_strcpy(u->ut_user, username, sizeof(u->ut_user));
+	strncpy(u->ut_user, username, sizeof(u->ut_user));
 #elif defined(HAVE_UT_UT_NAME)
-	utmp_strcpy(u->ut_name, username, sizeof(u->ut_name));
+	strncpy(u->ut_name, username, sizeof(u->ut_name));
 #endif
 
 	/*
 	 * ut_line:
 	 *	If size limit proves troublesome, then perhaps use "ut_id_encode()".
 	 */
-	utmp_strcpy(u->ut_line, id_str, sizeof(u->ut_line));
+	strncpy(u->ut_line, id_str, sizeof(u->ut_line));
 
 #if defined(HAVE_UT_UT_PID)
 	u->ut_pid = getpid();
@@ -535,20 +460,23 @@ static bool sys_utmp_fill(struct utmp *u
 	u->ut_time = timeval.tv_sec;
 #elif defined(HAVE_UT_UT_TV)
 	GetTimeOfDay(&timeval);
-	u->ut_tv = timeval;
+	u->ut_tv.tv_sec = timeval.tv_sec;
+	u->ut_tv.tv_usec = timeval.tv_usec;
 #else
 #error "with-utmp must have UT_TIME or UT_TV"
 #endif
 
 #if defined(HAVE_UT_UT_HOST)
-	utmp_strcpy(u->ut_host, hostname, sizeof(u->ut_host));
+	if(hostname != NULL) {
+		strncpy(u->ut_host, hostname, sizeof(u->ut_host));
+#if defined(HAVE_UT_UT_SYSLEN)
+		u->ut_syslen = strlen(hostname) + 1;	/* include trailing NULL */
+#endif
+	}
 #endif
 
 #if defined(HAVE_UT_UT_ID)
-	if (ut_id_encode(id_num, u->ut_id) != 0) {
-		DEBUG(1,("utmp_fill: cannot encode id %d\n", id_num));
-		return False;
-	}
+	ut_id_encode(u->ut_id, id_num, sizeof(u->ut_id));
 #endif
 
 	return True;
@@ -561,7 +489,7 @@ static bool sys_utmp_fill(struct utmp *u
 void sys_utmp_yield(const char *username, const char *hostname,
 		    const char *id_str, int id_num)
 {
-	struct utmp u;
+	STRUCT_UTMP u;
 
 	ZERO_STRUCT(u);
 
@@ -587,7 +515,7 @@ void sys_utmp_yield(const char *username
 void sys_utmp_claim(const char *username, const char *hostname,
 		    const char *id_str, int id_num)
 {
-	struct utmp u;
+	STRUCT_UTMP u;
 
 	ZERO_STRUCT(u);
 
