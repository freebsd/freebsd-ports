--- xpcom/reflect/xptcall/src/md/unix/xptc_platforms_unixish_x86.h.orig	Fri Jun 21 01:12:40 2002
+++ xpcom/reflect/xptcall/src/md/unix/xptc_platforms_unixish_x86.h	Fri Jun 21 01:41:51 2002
@@ -94,8 +94,16 @@
  * gcc is that the system gcc defines __FreeBSD_cc_version.  This variable
  * can also identify the period of time that 4.0-CURRENT used thunks.
  */
-#if defined(__FreeBSD_cc_version) && \
-    (__FreeBSD_cc_version < 400002 || __FreeBSD_cc_version > 400003)
+
+/* It seems we need to use thunks in FreeBSD -CURRENT after gcc-3.1 was merged.
+ * This solves a problem wherein regxpcom and/or regchrome would seg fault
+ * after running for a while.  This problem has also exhibited itself on 
+ * the alpha platform.  Therefore, use thunks on all versions of
+ * -CURRENT that are using gcc-3.1.
+ */
+#if defined(__FreeBSD_cc_version) && \
+    (__FreeBSD_cc_version < 400002 || __FreeBSD_cc_version > 400003) && \
+    (__FreeBSD_cc_version < 500003)
 #define CFRONT_STYLE_THIS_ADJUST
 #else
 #define THUNK_BASED_THIS_ADJUST
