--- OrthancFramework/Sources/Images/JpegWriter.cpp.orig	2024-08-01 21:59:25 UTC
+++ OrthancFramework/Sources/Images/JpegWriter.cpp
@@ -177,7 +177,7 @@ namespace Orthanc
     Internals::JpegErrorManager jerr;
 
     unsigned char* data = NULL;
-    size_t size;
+    unsigned long size;
 
     if (setjmp(jerr.GetJumpBuffer())) 
     {
