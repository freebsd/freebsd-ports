--- aclocal.m4.orig	Wed Jun 27 15:31:51 2001
+++ aclocal.m4	Wed Jun 27 15:32:46 2001
@@ -395,6 +395,9 @@
 		INSTOBJEXT=.mo
 	      fi
 	    fi
+	    if test "$gt_cv_func_gettext_libintl" = "yes"; then
+		INTLLIBS='-lintl'
+	    fi
 	])
 
         if test "$CATOBJEXT" = "NONE"; then
