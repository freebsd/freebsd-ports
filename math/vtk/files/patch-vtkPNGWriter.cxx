--- IO/vtkPNGWriter.cxx.orig	2003-12-30 21:51:31.000000000 +0100
+++ IO/vtkPNGWriter.cxx	2012-05-05 09:43:24.000000000 +0200
@@ -147,7 +147,7 @@
   void vtkPNGWriteErrorFunction(png_structp png_ptr,
                                 png_const_charp vtkNotUsed(error_msg))
   {
-    longjmp(png_ptr->jmpbuf, 1);
+    longjmp(png_jmpbuf(png_ptr), 1);
   }
 }
 
@@ -223,7 +223,7 @@
       png_init_io(png_ptr, this->TempFP);
       png_set_error_fn(png_ptr, png_ptr,
                        vtkPNGWriteErrorFunction, vtkPNGWriteWarningFunction);
-      if (setjmp(png_ptr->jmpbuf))
+      if (setjmp(png_jmpbuf(png_ptr)))
         {
         fclose(this->TempFP);
         this->SetErrorCode(vtkErrorCode::OutOfDiskSpaceError);
