--- src/devreader-bsd.cpp.orig	2011-06-12 10:01:11 UTC
+++ src/devreader-bsd.cpp
@@ -91,7 +91,7 @@ list<string> DevReaderBsd::findAllDevice
         if(sdl->sdl_family != AF_LINK)
             continue;
         
-        interfaceNames.push_back(string(sdl->sdl_data));
+        interfaceNames.push_back(string(sdl->sdl_data, sdl->sdl_nlen));
     }
 
     free(buf);
