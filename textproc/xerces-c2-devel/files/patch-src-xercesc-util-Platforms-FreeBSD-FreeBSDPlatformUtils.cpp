--- src/xercesc/util/Platforms/FreeBSD/FreeBSDPlatformUtils.cpp	Wed Nov 12 20:32:33 2003
+++ src/xercesc/util/Platforms/FreeBSD/FreeBSDPlatformUtils.cpp	Wed Nov 12 20:31:16 2003
@@ -298,7 +298,7 @@
 		 XMLExcepts::CPtr_PointerIsZero);
     const char* tmpFileName = XMLString::transcode(fileName, fgMemoryManager);
     ArrayJanitor<char> janText((char*)tmpFileName, fgMemoryManager);
-    FileHandle retVal = (FileHandle)fopen( tmpFileName , "r+" );
+    FileHandle retVal = (FileHandle)fopen( tmpFileName , "r" );
     return retVal;
 }
 
@@ -307,7 +307,7 @@
     if (fileName == NULL)
 	ThrowXML(XMLPlatformUtilsException,
 		 XMLExcepts::CPtr_PointerIsZero);
-    FileHandle retVal = (FileHandle)fopen( fileName , "r+" );
+    FileHandle retVal = (FileHandle)fopen( fileName , "r" );
     return retVal;
 }
 
