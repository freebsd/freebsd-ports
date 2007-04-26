--- ./src/OpenFOAM/primitives/ulong/ulongIO.C.orig	Wed Jan 17 15:45:49 2007
+++ ./src/OpenFOAM/primitives/ulong/ulongIO.C	Thu Apr 12 23:36:50 2007
@@ -37,6 +37,8 @@
 
 #include <sstream>
 
+typedef	u_long ulong;
+
 // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
 
 namespace Foam
