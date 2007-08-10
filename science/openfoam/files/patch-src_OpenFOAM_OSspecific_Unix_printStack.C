--- src/OpenFOAM/OSspecific/Unix/printStack.C.orig	Fri May 18 15:24:33 2007
+++ src/OpenFOAM/OSspecific/Unix/printStack.C	Sun Aug  5 00:07:39 2007
@@ -35,6 +35,8 @@
 #include <execinfo.h>
 #include <dlfcn.h>
 
+typedef	u_long ulong;
+
 // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
 
 namespace Foam
