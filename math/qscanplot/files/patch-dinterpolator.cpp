--- qscanplot/dinterpolator.cpp.orig	Tue Feb 17 14:15:08 2004
+++ qscanplot/dinterpolator.cpp	Tue Feb 17 14:15:25 2004
@@ -30,6 +30,7 @@
 #include "dinterpolator.h"
 #include <qlistbox.h>
 #include <qmultilineedit.h>
+#include <qregexp.h>
 
 dInterpolator::dInterpolator(QWidget *parent, const char *name, bool modal )
   : dlgInterpolator(parent,name,modal)
