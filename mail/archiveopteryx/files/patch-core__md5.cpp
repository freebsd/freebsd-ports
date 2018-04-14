--- core/md5.cpp.orig	2014-03-10 13:44:59 UTC
+++ core/md5.cpp
@@ -52,7 +52,7 @@ void MD5::init()
 
 void MD5::add( const char *str, uint len )
 {
-    register uint32 t;
+    uint32 t;
 
     /* It's not possible to add() data, call hash(), then add more data
        and call hash() again, because hash() destroys the accumulated
@@ -149,12 +149,9 @@ EString MD5::hash()
     }
     swapBytes( in, 14 );
 
-#pragma GCC diagnostic push
-#pragma GCC diagnostic ignored "-Wstrict-aliasing"
     /* Append length in bits and transform. */
     ((uint32 *)in)[14] = bits[0];
     ((uint32 *)in)[15] = bits[1];
-#pragma GCC diagnostic pop
     transform();
     swapBytes( (char *)buf, 4 );
 
@@ -247,7 +244,7 @@ EString MD5::HMAC( const EString &secret
 
 void MD5::transform()
 {
-    register uint32 a, b, c, d;
+    uint32 a, b, c, d;
     uint32 *inw = (uint32 *)in;
 
     a = buf[0];
