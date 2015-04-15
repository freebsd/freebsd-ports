--- swig/ZorbaIOStream.i.orig	2012-10-03 22:35:16 UTC
+++ swig/ZorbaIOStream.i
@@ -46,7 +46,7 @@ void ZorbaIOStream::setStream(const char
 
 void ZorbaIOStream::setStream(const char *BYTE, size_t aLen)
 {
-  if (aLen<0) aLen=0;
+  /* if (aLen<0) aLen=0;  size_t is unsigned, check always fails */
   if (aLen > 0)
     memcpy(buffer, BYTE, aLen*sizeof(char));
   len = aLen;
@@ -71,4 +71,4 @@ void ZorbaIOStream::write(const char *BY
 %}  // end   Implementation
 
 
-%include "ZorbaIOStream.h"
\ No newline at end of file
+%include "ZorbaIOStream.h"
