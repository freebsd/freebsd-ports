--- scribus/page.cpp.orig	Tue Apr 20 16:17:32 2004
+++ scribus/page.cpp	Tue Apr 20 16:20:34 2004
@@ -55,6 +55,8 @@
 #include <qprocess.h>
 #include <qscrollbar.h>
 
+#include <unistd.h>
+
 #ifdef HAVE_TIFF
 	#include <tiffio.h>
 #endif
@@ -7929,7 +7931,7 @@
 				it++;
 				hg->cab = it == NULL ? 0 : (*it).toInt();
 				it++;
-				hg->cstroke = it == NULL ? "None" : *it;
+				hg->cstroke = it == NULL ? QString("None") : *it;
 				it++;
 				hg->cshade2 = it == NULL ? 100 : (*it).toInt();
 				it++;
