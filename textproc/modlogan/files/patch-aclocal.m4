--- aclocal.m4_bak	Tue Dec 26 12:57:08 2000
+++ aclocal.m4	Tue Dec 26 12:57:22 2000
@@ -672,6 +672,9 @@
 		INSTOBJEXT=.mo
 	      fi
 	    fi
+	    if test "$gt_cv_func_gettext_libintl" = "yes"; then
+		INTLLIBS='-lintl'
+	    fi
 	])
 
         if test "$CATOBJEXT" = "NONE"; then
