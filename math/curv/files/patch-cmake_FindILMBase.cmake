--- cmake/FindILMBase.cmake.orig	2019-12-08 04:12:07 UTC
+++ cmake/FindILMBase.cmake
@@ -6,6 +6,6 @@
 
 SET( ILMBASE_FOUND TRUE )
 SET( ILMBASE_INCLUDE_DIR "" )
-SET( Ilmbase_HALF_LIBRARY -lHalf )
+SET( Ilmbase_HALF_LIBRARY -lImath )
 SET( Ilmbase_IEX_LIBRARY -lIex )
 SET( Ilmbase_ILMTHREAD_LIBRARY -lIlmThread )
