--- ./largefile.h.orig	2010-12-13 04:42:49.000000000 +0100
+++ ./largefile.h	2014-06-29 12:15:04.246544121 +0200
@@ -18,3 +18,15 @@
 #define strtoofft(x,y,z)	(strtol((x),(y),(z)))
 #define PRIofft			"l"
 #endif
+
+#if SIZEOF_TIME_T == 8
+    #ifdef HAVE_STRTOLL
+    #define strtotimet(x,y,z)	(strtoll((x),(y),(z)))
+    #else /* !HAVE_STRTOLL */
+    #define strtotimet(x,y,z)	(strtol((x),(y),(z)))
+    #endif /* HAVE_STRTOLL */
+    #define PRItimet		"ll"
+#else /* SIZEOF_TIME_T != 8 */
+    #define strtotimet(x,y,z)	(strtol((x),(y),(z)))
+    #define PRItimet		"l"
+#endif /* SIZEOF_TIME_T */
