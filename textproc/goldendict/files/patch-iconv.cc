--- ./iconv.cc.orig	2010-12-04 00:12:46.000000000 +0300
+++ ./iconv.cc	2010-12-28 11:46:37.208721626 +0300
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
 
