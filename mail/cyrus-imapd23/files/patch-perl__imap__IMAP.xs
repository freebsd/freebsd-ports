Index: perl/imap/IMAP.xs
diff -u perl/imap/IMAP.xs.orig perl/imap/IMAP.xs
--- perl/imap/IMAP.xs.orig	2011-04-13 23:35:22.000000000 +0900
+++ perl/imap/IMAP.xs	2011-05-20 15:27:09.000000000 +0900
@@ -68,6 +68,16 @@
 #define aTHX_
 #endif
 
+#ifndef sv_no
+#define sv_no		PL_sv_no
+#endif
+#ifndef sv_undef
+#define sv_undef	PL_sv_undef
+#endif
+#ifndef sv_yes
+#define sv_yes		PL_sv_yes
+#endif
+
 /*
  * This is the code from xsutil.c
  */
