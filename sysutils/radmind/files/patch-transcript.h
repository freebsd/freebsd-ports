--- ./transcript.h.orig	2010-12-13 04:42:49.000000000 +0100
+++ ./transcript.h	2014-06-29 12:15:04.249543651 +0200
@@ -39,6 +39,14 @@
 extern FILE		*outtran;
 extern char		*path_prefix;
 
+
+#define T_SKIP_POSITIVE		(1 << 1)
+#define T_SKIP_NEGATIVE		(1 << 2)
+#define T_SKIP_SPECIAL		(1 << 3)
+#define T_SKIP_EXCLUDES		(1 << 4)
+#define	T_SKIP_ALL		(T_SKIP_POSITIVE | T_SKIP_NEGATIVE | \
+				 T_SKIP_SPECIAL | T_SKIP_EXCLUDES)
+
 struct pathinfo {
     char			pi_type;
     int				pi_minus;
