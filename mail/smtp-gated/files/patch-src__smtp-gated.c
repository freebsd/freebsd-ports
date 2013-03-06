--- ../../smtp-gated-1.4.20.0/src/smtp-gated.c	2013-02-26 08:06:59.000000000 -0300
+++ src/smtp-gated.c	2013-02-28 09:32:47.000000000 -0300
@@ -820,7 +820,11 @@
 	}
 } /* cleanup() */
 
+#ifdef __clang__
+static inline void cleanup_exit(int code)
+#else
 inline void cleanup_exit(int code)
+#endif
 {
 	cleanup();
 	exit(code);
