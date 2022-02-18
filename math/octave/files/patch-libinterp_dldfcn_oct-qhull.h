--- libinterp/dldfcn/oct-qhull.h.orig	2021-10-30 14:20:24 UTC
+++ libinterp/dldfcn/oct-qhull.h
@@ -32,32 +32,18 @@
 
 extern "C" {
 
-#if defined (HAVE_LIBQHULL_LIBQHULL_H)
-#  include <libqhull/libqhull.h>
-#  include <libqhull/qset.h>
-#  include <libqhull/geom.h>
-#  include <libqhull/poly.h>
-#  include <libqhull/io.h>
-#elif defined (HAVE_QHULL_LIBQHULL_H) || defined (HAVE_QHULL_QHULL_H)
-#  if defined (HAVE_QHULL_LIBQHULL_H)
-#    include <qhull/libqhull.h>
-#  else
-#    include <qhull/qhull.h>
-#  endif
-#  include <qhull/qset.h>
-#  include <qhull/geom.h>
-#  include <qhull/poly.h>
-#  include <qhull/io.h>
-#  elif defined (HAVE_LIBQHULL_H) || defined (HAVE_QHULL_H)
-#  if defined (HAVE_LIBQHULL_H)
-#    include <libqhull.h>
-#  else
-#    include <qhull.h>
-#  endif
-#  include <qset.h>
-#  include <geom.h>
-#  include <poly.h>
-#  include <io.h>
+#if defined (HAVE_LIBQHULL_R_LIBQHULL_R_H)
+#  include <libqhull_r/libqhull_r.h>
+#  include <libqhull_r/qset_r.h>
+#  include <libqhull_r/geom_r.h>
+#  include <libqhull_r/poly_r.h>
+#  include <libqhull_r/io_r.h>
+#elif defined (HAVE_LIBQHULL_R_H)
+#  include <libqhull_r.h>
+#  include <qset_r.h>
+#  include <geom_r.h>
+#  include <poly_r.h>
+#  include <io_r.h>
 #endif
 
 }
