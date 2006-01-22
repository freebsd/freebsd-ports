--- applications/utilities/preProcessing/FoamX/C++/FoamXLib/ITypeDescriptorImpl.C.orig	Wed Aug 17 11:35:37 2005
+++ applications/utilities/preProcessing/FoamX/C++/FoamXLib/ITypeDescriptorImpl.C	Sat Dec 24 18:36:45 2005
@@ -39,6 +39,11 @@
 // Namespaces
 #include "FoamXNameSpaces.H"
 
+#if (__FreeBSD__)
+#  include <sys/types.h>
+   typedef unsigned long  ulong;
+#endif
+
 // * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //
 
 FoamX::ITypeDescriptorImpl::ITypeDescriptorImpl
