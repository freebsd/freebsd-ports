--- OrthancFramework/Sources/Images/JpegWriter.cpp.orig	2024-12-17 16:33:40 UTC
+++ OrthancFramework/Sources/Images/JpegWriter.cpp
@@ -187,7 +187,7 @@ namespace Orthanc
      **/
     unsigned long size;
 #else
-    size_t size;
+    unsigned long size;
 #endif
 
     if (setjmp(jerr.GetJumpBuffer())) 
