--- aclocal.m4.orig	Thu Nov 23 05:32:03 2000
+++ aclocal.m4	Sat Dec  2 12:21:18 2000
@@ -1996,9 +1996,12 @@
 		  [CATOBJEXT=.gmo
 		   DATADIRNAME=share],
 		  [CATOBJEXT=.mo
-		   DATADIRNAME=lib])
+		   DATADIRNAME=share])
 		INSTOBJEXT=.mo
 	      fi
+	    fi
+	    if test "$gt_cv_func_gettext_libintl" = "yes"; then
+		INTLLIBS='-lintl'
 	    fi
 	])
 
