diff -u -r1.109 -r1.110
--- IO/vtkImageReader.cxx	2002/12/26 18:18:50	1.109
+++ IO/vtkImageReader.cxx	2003/10/19 14:38:03	1.110
@@ -166,7 +166,7 @@
   streamStart += this->GetHeaderSize(idx);
   
   // error checking
-  this->File->seekg((long)streamStart, ios::beg);
+  this->File->seekg(static_cast<long>(streamStart), ios::beg);
   if (this->File->fail())
     {
     vtkErrorMacro(<< "File operation failed: " << streamStart << ", ext: "
@@ -366,7 +366,7 @@
       // if that happens, store the value in correction and apply later
       if (filePos + streamSkip0 >= 0)
         {
-        self->GetFile()->seekg(self->GetFile()->tellg() + streamSkip0, ios::beg);
+        self->GetFile()->seekg(static_cast<long>(self->GetFile()->tellg()) + streamSkip0, ios::beg);
         correction = 0;
         }
       else
@@ -376,7 +376,7 @@
       outPtr1 += outIncr[1];
       }
     // move to the next image in the file and data
-    self->GetFile()->seekg(self->GetFile()->tellg() + streamSkip1 + correction, 
+    self->GetFile()->seekg(static_cast<long>(self->GetFile()->tellg()) + streamSkip1 + correction, 
                       ios::beg);
     outPtr2 += outIncr[2];
     }
