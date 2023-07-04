--- src/Container/SALOME_ContainerManager.cxx.orig	2023-07-03 21:24:41 UTC
+++ src/Container/SALOME_ContainerManager.cxx
@@ -64,6 +64,8 @@
 #include "PaCOPP.hxx"
 #endif
 
+#include <sys/wait.h> // for WEXITSTATUS
+
 const int SALOME_ContainerManager::TIME_OUT_TO_LAUNCH_CONT=60;
 
 const char *SALOME_ContainerManager::_ContainerManagerNameInNS =
