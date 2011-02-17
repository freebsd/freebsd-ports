--- IO/vtkJPEGWriter.cxx
+++ IO/vtkJPEGWriter.cxx
@@ -129,7 +129,7 @@ void vtkJPEGWriter::Write()
   this->InternalFileName = NULL;
 }
 
-// these three routines are for wqriting into memory
+// these three routines are for writing into memory
 extern "C"
 {
   void vtkJPEGWriteToMemoryInit(j_compress_ptr cinfo)
@@ -157,16 +157,20 @@ extern "C"
 {
   boolean vtkJPEGWriteToMemoryEmpty(j_compress_ptr cinfo)
   {
+    // Even if (cinfo->dest->free_in_buffer != 0) we still need to write on the
+    // new array and not at (arraySize - nbFree)
     vtkJPEGWriter *self = vtkJPEGWriter::SafeDownCast(
       static_cast<vtkObject *>(cinfo->client_data));
     if (self)
       {
       vtkUnsignedCharArray *uc = self->GetResult();
-      // we must grow the array, we grow by 50% each time
+      // we must grow the array
       int oldSize = uc->GetSize();
-      uc->Resize(oldSize + oldSize/2);
+      uc->Resize(oldSize*1.5);
+      // Resize do grow the array but it is not the size we expect
+      int newSize = uc->GetSize();
       cinfo->dest->next_output_byte = uc->GetPointer(oldSize);
-      cinfo->dest->free_in_buffer = oldSize/2;
+      cinfo->dest->free_in_buffer = newSize - oldSize;
       }
     return TRUE;
   }
@@ -182,8 +186,8 @@ extern "C"
       {
       vtkUnsignedCharArray *uc = self->GetResult();
       // we must close the array
-      vtkIdType oldSize = uc->GetSize();
-      uc->SetNumberOfTuples(oldSize - static_cast<vtkIdType>(cinfo->dest->free_in_buffer));
+      int realSize = uc->GetSize() - cinfo->dest->free_in_buffer;
+      uc->SetNumberOfTuples(realSize);
       }
   }
 }
