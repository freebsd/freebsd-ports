--- acinclude.m4.orig	Tue Jan  1 09:39:27 2002
+++ acinclude.m4	Tue Jan  1 09:50:18 2002
@@ -68,6 +68,9 @@
           fi
         done
       fi
+    else
+      ac_qt_libname=-lqt2-mt
+      ac_qt_libdir=$ac_qt_libraries
     fi
 
     ac_cv_lib_qtlib="ac_qt_libname=$ac_qt_libname ac_qt_libdir=$ac_qt_libdir"
