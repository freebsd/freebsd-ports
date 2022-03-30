--- third_party/swiftshader/src/WSI/libXCB.cpp.orig	2022-03-28 18:11:04 UTC
+++ third_party/swiftshader/src/WSI/libXCB.cpp
@@ -53,7 +53,7 @@ LibXcbExports *LibXCB::loadExports()
 		}
 		else
                 {
-			libxcb = loadLibrary("libxcb.so.1");
+			libxcb = loadLibrary("libxcb.so");
 		}
 
 		if(getProcAddress(RTLD_DEFAULT, "xcb_shm_query_version"))  // Search the global scope for pre-loaded XCB library.
