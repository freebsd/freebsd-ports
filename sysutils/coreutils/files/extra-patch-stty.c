--- src/stty.c.orig	2007-03-18 14:36:43.000000000 -0700
+++ src/stty.c	2008-08-28 18:54:40.000000000 -0700
@@ -282,8 +282,6 @@
 #endif
 #ifdef TABDLY
   {"tab3", output, SANE_UNSET, TAB3, TABDLY},
-  {"tab2", output, SANE_UNSET, TAB2, TABDLY},
-  {"tab1", output, SANE_UNSET, TAB1, TABDLY},
   {"tab0", output, SANE_SET, TAB0, TABDLY},
 #else
 # ifdef OXTABS
@@ -632,7 +630,7 @@
       fputs (_("\
  * [-]onocr      do not print carriage returns in the first column\n\
    [-]opost      postprocess output\n\
- * tabN          horizontal tab delay style, N in [0..3]\n\
+ * tabN          horizontal tab delay style, N in [0,3]\n\
  * tabs          same as tab0\n\
  * -tabs         same as tab3\n\
  * vtN           vertical tab delay style, N in [0..1]\n\
