--- pwg/outputwndimpl.cpp.orig	Sat Jun 21 18:40:54 2003
+++ pwg/outputwndimpl.cpp	Sat Jun 21 18:41:22 2003
@@ -20,7 +20,7 @@
 #include <klocale.h>
 
 #include <unistd.h>
-
+#include <time.h>
 
 OutputWndImpl::OutputWndImpl(QWidget* parent, const char *name)
  : OutputWnd(parent, name)
