--- tclUnixInit.c	Thu May 15 13:29:41 2003
+++ tclUnixInit.c	Sun Oct 19 12:39:44 2003
@@ -184,5 +184,9 @@
 #endif /* SIGPIPE */
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) && defined(__GNUC__)
+/*
+ * FreeBSD only provides the __fpsetreg() used by the following two
+ * for the GNU Compiler. When using, say, Intel's icc they break.
+ */
     fpsetround(FP_RN);
     fpsetmask(0L);
