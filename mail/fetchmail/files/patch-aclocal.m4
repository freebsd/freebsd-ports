--- aclocal.m4	2001/03/20 09:46:26	1.3
+++ aclocal.m4	2001/03/23 11:09:05
@@ -177,6 +177,9 @@
 		INSTOBJEXT=.mo
 	      fi
 	    fi
+	    if test "$gt_cv_func_gettext_libintl" = "yes"; then
+		INTLLIBS='-lintl'
+	    fi
 	])
 
         if test "$CATOBJEXT" = "NONE"; then
