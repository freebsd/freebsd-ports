--- fuse_module/fuse.h.orig	Tue Jun 19 14:35:22 2007
+++ fuse_module/fuse.h	Sat Jul 14 13:23:37 2007
@@ -33,6 +33,24 @@
 #endif
 #endif
 
+#ifndef USE_PRIVILEGE_API
+/*
+ * __FreeBSD_version bump was omitted for introduction of
+ * the privilege API (both when it's been added and when the
+ * legacy API has been removed), so here we just use the first
+ * value of __FreeBSD_version after adding the priv stuff.
+ */
+#if __FreeBSD_version >= 700025
+#define USE_PRIVILEGE_API 1
+#else
+#define USE_PRIVILEGE_API 0
+#endif
+#endif
+#if ! USE_PRIVILEGE_API
+#define priv_check(td, priv) suser(td)
+#define priv_check_cred(cred, priv, flag) suser_cred(cred, SUSER_ALLOWJAIL)
+#endif
+
 /*
  * Appearance of new FUSE operations is not always in par with version
  * numbering... At least, 7.3 is a sufficient condition for having
@@ -210,7 +228,7 @@
 void fprettyprint(struct fuse_iov *fiov, size_t dlen);
 #endif
 
-#if _DEBUG || _DEBUG2G || _DEBUG3G || defined(INVARIANTS)
+#if _DEBUG || _DEBUG2G || _DEBUG3G || defined(INVARIANTS) || FUSELIB_CONFORM_BIOREAD
 int isbzero(void *buf, size_t len);
 #endif
 
