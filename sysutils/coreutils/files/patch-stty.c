--- src/stty.c.orig	2010-07-21 17:11:49.000000000 +0200
+++ src/stty.c	2010-07-21 17:12:36.000000000 +0200
@@ -282,10 +282,10 @@
 # ifdef TAB3
   {"tab3", output, SANE_UNSET, TAB3, TABDLY},
 # endif
-# ifdef TAB2
+# if 0
   {"tab2", output, SANE_UNSET, TAB2, TABDLY},
 # endif
-# ifdef TAB1
+# if 0
   {"tab1", output, SANE_UNSET, TAB1, TABDLY},
 # endif
 # ifdef TAB0
@@ -635,7 +635,7 @@
       fputs (_("\
  * [-]onocr      do not print carriage returns in the first column\n\
    [-]opost      postprocess output\n\
- * tabN          horizontal tab delay style, N in [0..3]\n\
+ * tabN          horizontal tab delay style, N in [0,3]\n\
  * tabs          same as tab0\n\
  * -tabs         same as tab3\n\
  * vtN           vertical tab delay style, N in [0..1]\n\
