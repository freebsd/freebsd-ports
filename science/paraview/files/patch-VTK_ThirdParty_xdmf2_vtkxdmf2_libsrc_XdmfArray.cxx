--- VTK/ThirdParty/xdmf2/vtkxdmf2/libsrc/XdmfArray.cxx.orig
+++ VTK/ThirdParty/xdmf2/vtkxdmf2/libsrc/XdmfArray.cxx
@@ -310,9 +310,6 @@
     if( this->DataPointer == NULL ) {
       XdmfDebug("Allocation Failed");
       perror(" Alloc :" );
-#ifndef _WIN32      
-      XdmfDebug("End == " << sbrk(0)  );
-#endif
       }
   }
   XdmfDebug("Data Pointer = " << this->DataPointer );
