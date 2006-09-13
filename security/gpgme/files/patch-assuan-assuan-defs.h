--- assuan/assuan-defs.h.orig	Thu Sep 14 00:33:50 2006
+++ assuan/assuan-defs.h	Thu Sep 14 00:34:51 2006
@@ -251,5 +251,16 @@
 #define funopen(a,r,w,s,c) _assuan_funopen ((a), (r), (w), (s), (c))
 #endif /*HAVE_FOPENCOOKIE*/
 
+#ifndef HAVE_STPCPY
+static char * _gpgme_stpcpy (char *a, const char *b)
+{
+  while (*b)
+    *a++ = *b++;
+  *a = 0;
+  return a;
+}
+#define stpcpy(a,b) _gpgme_stpcpy ((a), (b))
+#endif /*!HAVE_STPCPY*/
+
 #endif /*ASSUAN_DEFS_H*/
 
