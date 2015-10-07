--- src/include/sharedLibrary.h.orig	2015-08-07 18:40:37.855840000 -0400
+++ src/include/sharedLibrary.h	2015-08-07 18:40:42.675578000 -0400
@@ -52,6 +52,14 @@
   {
           std::cerr << ::dlerror( ) << std::endl;
   }
+#elif defined(__FreeBSD__)
+        tstring freebsdName = unixPrefix;
+        freebsdName += libraryName += ".so";
+        void* fileHandle = ::dlopen( freebsdName.c_str( ), RTLD_NOW );
+        if( !quiet && !fileHandle )
+        {
+                std::cerr << ::dlerror( ) << std::endl;
+        }
 #else
         #error "unsupported platform"
 #endif
