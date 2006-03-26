--- applications/utilities/preProcessing/FoamX/C++/FoamXLib/ProcessControl.C.orig	Wed Jun 22 14:33:39 2005
+++ applications/utilities/preProcessing/FoamX/C++/FoamXLib/ProcessControl.C	Thu Dec 22 00:01:29 2005
@@ -30,6 +30,9 @@
 #include <fcntl.h>
 #include <sys/wait.h>
 #include <errno.h>
+#if defined(__FreeBSD__)
+#  include <sys/stat.h>
+#endif
 
 // Foam header files.
 #include "ProcessControl.H"
