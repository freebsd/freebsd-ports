--- VTK/ThirdParty/xdmf2/vtkxdmf2/libsrc/XdmfArray.cxx.orig	2024-02-28 20:42:21 UTC
+++ VTK/ThirdParty/xdmf2/vtkxdmf2/libsrc/XdmfArray.cxx
@@ -310,9 +310,6 @@ XdmfInt32 XdmfArray::Allocate( void ){
     if( this->DataPointer == NULL ) {
       XdmfDebug("Allocation Failed");
       perror(" Alloc :" );
-#ifndef _WIN32      
-      XdmfDebug("End == " << sbrk(0)  );
-#endif
       }
   }
   XdmfDebug("Data Pointer = " << this->DataPointer );
