--- iconv.cc.orig	2009-04-18 21:20:12.000000000 +0400
+++ iconv.cc	2009-11-09 01:15:24.000000000 +0300
@@ -44,11 +44,7 @@
   throw( exIncorrectSeq, exOther )
 {
   size_t result = iconv( state,
-                         #ifdef __WIN32
                          (char const **)&inBuf,
-                         #else
-                         (char **)&inBuf,
-                         #endif
                                            &inBytesLeft,
                          (char **)&outBuf, &outBytesLeft );
 
