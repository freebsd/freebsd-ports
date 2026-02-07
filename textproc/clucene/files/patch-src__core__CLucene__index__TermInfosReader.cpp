--- src/core/CLucene/index/TermInfosReader.cpp.orig	2011-03-16 20:21:07.000000000 -0400
+++ src/core/CLucene/index/TermInfosReader.cpp	2014-06-24 18:19:42.000000000 -0400
@@ -111,7 +111,7 @@
 	      //destroy their elements
 #ifdef _DEBUG
          for ( int32_t i=0; i<indexTermsLength;++i ){
-            indexTerms[i].__cl_refcount--;
+            indexTerms[i].__cl_decref();
          }
 #endif
          //Delete the arrays
