diff -u -r1.44 -r1.45
--- IO/vtkBMPReader.cxx	2003/09/10 19:41:56	1.44
+++ IO/vtkBMPReader.cxx	2003/10/19 14:38:03	1.45
@@ -504,11 +504,11 @@
         outPtr0 += outIncr[0];
         }
       // move to the next row in the file and data
-      self->GetFile()->seekg(self->GetFile()->tellg() + streamSkip0, ios::beg);
+      self->GetFile()->seekg(static_cast<long>(self->GetFile()->tellg()) + streamSkip0, ios::beg);
       outPtr1 += outIncr[1];
       }
     // move to the next image in the file and data
-    self->GetFile()->seekg(self->GetFile()->tellg() + streamSkip1, ios::beg);
+    self->GetFile()->seekg(static_cast<long>(self->GetFile()->tellg()) + streamSkip1, ios::beg);
     outPtr2 += outIncr[2];
     }
