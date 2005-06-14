--- VTK/Hybrid/vtkVRMLImporter.cxx.orig	Sat Jun  4 15:21:57 2005
+++ VTK/Hybrid/vtkVRMLImporter.cxx	Sat Jun  4 15:21:58 2005
@@ -17,7 +17,7 @@
 #ifndef alloca
 char *alloca ();
 #endif
-#include <malloc.h>
+#include <stdlib.h>
 #endif /* not _AIX */
 #endif /* not HAVE_ALLOCA_H */
 #endif /* not __GNUC__ */
@@ -513,7 +513,7 @@
 #define YYDEBUG 1
 
 #ifndef __APPLE__
-#include <malloc.h>
+#include <stdlib.h>
 #endif
 
 #ifdef USE_STD_NAMESPACE
