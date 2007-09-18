--- lib/system.c.orig	Mon Aug 20 15:04:50 2007
+++ lib/system.c	Sun Sep 16 04:25:55 2007
@@ -574,7 +574,11 @@
 {
 	char *wd;
 #ifdef HAVE_GETCWD
+#ifdef PATH_MAX
+	wd = (char *)getcwd(s, PATH_MAX);
+#else
 	wd = (char *)getcwd(s, sizeof (pstring));
+#endif
 #else
 	wd = (char *)getwd(s);
 #endif
@@ -643,6 +647,25 @@
 }
 
 /*******************************************************************
+ Wrapper for lchown.
+********************************************************************/
+
+int sys_lchown(const char *fname,uid_t uid,gid_t gid)
+{
+#ifndef HAVE_LCHOWN
+	static int done;
+	if (!done) {
+		DEBUG(1,("WARNING: no lchown!\n"));
+		done=1;
+	}
+	errno = ENOSYS;
+	return -1;
+#else
+	return(lchown(fname,uid,gid));
+#endif
+}
+
+/*******************************************************************
 os/2 also doesn't have chroot
 ********************************************************************/
 int sys_chroot(const char *dname)
@@ -871,15 +894,13 @@
 }
 
 /**************************************************************************
- Wrapper for getgroups. Deals with broken (int) case.
+ Wrap setgroups and getgroups for systems that declare getgroups() as
+ returning an array of gid_t, but actuall return an array of int.
 ****************************************************************************/
 
-int sys_getgroups(int setlen, gid_t *gidset)
+#if defined(HAVE_BROKEN_GETGROUPS)
+static int sys_broken_getgroups(int setlen, gid_t *gidset)
 {
-#if !defined(HAVE_BROKEN_GETGROUPS)
-	return getgroups(setlen, gidset);
-#else
-
 	GID_T gid;
 	GID_T *group_list;
 	int i, ngroups;
@@ -901,7 +922,7 @@
 	if (setlen == 0)
 		setlen = groups_max();
 
-	if((group_list = (GID_T *)malloc(setlen * sizeof(GID_T))) == NULL) {
+	if((group_list = SMB_MALLOC_ARRAY(GID_T, setlen)) == NULL) {
 		DEBUG(0,("sys_getgroups: Malloc fail.\n"));
 		return -1;
 	}
@@ -918,26 +939,10 @@
 
 	SAFE_FREE(group_list);
 	return ngroups;
-#endif /* HAVE_BROKEN_GETGROUPS */
 }
 
-
-/**************************************************************************
- Wrapper for setgroups. Deals with broken (int) case. Automatically used
- if we have broken getgroups.
-****************************************************************************/
-
-int sys_setgroups(int setlen, gid_t *gidset)
+static int sys_broken_setgroups(int setlen, gid_t *gidset)
 {
-#if !defined(HAVE_SETGROUPS)
-	errno = ENOSYS;
-	return -1;
-#endif /* HAVE_SETGROUPS */
-
-#if !defined(HAVE_BROKEN_GETGROUPS)
-	return setgroups(setlen, gidset);
-#else
-
 	GID_T *group_list;
 	int i ; 
 
@@ -954,7 +959,7 @@
 	 * GID_T array of size setlen.
 	 */
 
-	if((group_list = (GID_T *)malloc(setlen * sizeof(GID_T))) == NULL) {
+	if((group_list = SMB_MALLOC_ARRAY(GID_T, setlen)) == NULL) {
 		DEBUG(0,("sys_setgroups: Malloc fail.\n"));
 		return -1;    
 	}
@@ -971,7 +976,105 @@
  
 	SAFE_FREE(group_list);
 	return 0 ;
+}
+
 #endif /* HAVE_BROKEN_GETGROUPS */
+
+/* This is a list of systems that require the first GID passed to setgroups(2)
+ * to be the effective GID. If your system is one of these, add it here.
+ */
+#if defined (FREEBSD) || defined (DARWINOS)
+#define USE_BSD_SETGROUPS
+#endif
+
+#if defined(USE_BSD_SETGROUPS)
+/* Depending on the particular BSD implementation, the first GID that is
+ * passed to setgroups(2) will either be ignored or will set the credential's
+ * effective GID. In either case, the right thing to do is to guarantee that
+ * gidset[0] is the effective GID.
+ */
+static int sys_bsd_setgroups(gid_t primary_gid, int setlen, const gid_t *gidset)
+{
+	gid_t *new_gidset = NULL;
+	int max;
+	int ret;
+
+	/* setgroups(2) will fail with EINVAL if we pass too many groups. */
+	max = groups_max();
+
+	/* No group list, just make sure we are setting the efective GID. */
+	if (setlen == 0) {
+		return setgroups(1, &primary_gid);
+	}
+
+	/* If the primary gid is not the first array element, grow the array
+	 * and insert it at the front.
+	 */
+	if (gidset[0] != primary_gid) {
+	        new_gidset = SMB_MALLOC_ARRAY(gid_t, setlen + 1);
+	        if (new_gidset == NULL) {
+			return -1;
+	        }
+
+		memcpy(new_gidset + 1, gidset, (setlen * sizeof(gid_t)));
+		new_gidset[0] = primary_gid;
+		setlen++;
+	}
+
+	if (setlen > max) {
+		DEBUG(3, ("forced to truncate group list from %d to %d\n",
+			setlen, max));
+		setlen = max;
+	}
+
+#if defined(HAVE_BROKEN_GETGROUPS)
+	ret = sys_broken_setgroups(setlen, new_gidset ? new_gidset : gidset);
+#else
+	ret = setgroups(setlen, new_gidset ? new_gidset : gidset);
+#endif
+
+	if (new_gidset) {
+		int errsav = errno;
+		SAFE_FREE(new_gidset);
+		errno = errsav;
+	}
+
+	return ret;
+}
+
+#endif /* USE_BSD_SETGROUPS */
+
+/**************************************************************************
+ Wrapper for getgroups. Deals with broken (int) case.
+****************************************************************************/
+
+int sys_getgroups(int setlen, gid_t *gidset)
+{
+#if defined(HAVE_BROKEN_GETGROUPS)
+	return sys_broken_getgroups(setlen, gidset);
+#else
+	return getgroups(setlen, gidset);
+#endif
+}
+
+/**************************************************************************
+ Wrapper for setgroups. Deals with broken (int) case and BSD case.
+****************************************************************************/
+
+int sys_setgroups(gid_t UNUSED(primary_gid), int setlen, gid_t *gidset)
+{
+#if !defined(HAVE_SETGROUPS)
+	errno = ENOSYS;
+	return -1;
+#endif /* HAVE_SETGROUPS */
+
+#if defined(USE_BSD_SETGROUPS)
+	return sys_bsd_setgroups(primary_gid, setlen, gidset);
+#elif defined(HAVE_BROKEN_GETGROUPS)
+	return sys_broken_setgroups(setlen, gidset);
+#else
+	return setgroups(setlen, gidset);
+#endif
 }
 
 /**************************************************************************
