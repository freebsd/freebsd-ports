--- aclocal.m4.orig	Sat Mar  9 04:27:20 2002
+++ aclocal.m4	Wed May 22 21:11:00 2002
@@ -273,6 +273,9 @@
 
         CATOBJEXT=.gmo
       fi
+      if test "$gt_cv_func_gettext_libintl" = "yes"; then
+	    INTLLIBS='-lintl'
+      fi
     ])
 
     if test "$gt_use_preinstalled_gnugettext" = "yes" \
