--- src/io/ReadABAQUS.cpp.orig	2018-11-04 23:41:08 UTC
+++ src/io/ReadABAQUS.cpp
@@ -105,7 +105,7 @@ void ReadABAQUS::reset()
 ReadABAQUS::~ReadABAQUS() 
 {
   mdbImpl->release_interface(readMeshIface);
-  if (NULL != abFile)
+  if (abFile.is_open())
     abFile.close();
 }
 
