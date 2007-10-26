--- asn1.cpp.orig	2007-10-26 20:24:08.000000000 +0200
+++ asn1.cpp	2007-10-26 20:25:34.000000000 +0200
@@ -550,8 +550,9 @@ unsigned char * asn_parse_length( unsign
     memcpy((char *)length, (char *)data + 1, (int)lengthbyte);
     *length = ntohl(*length);
     // ntohl even on ALPHA (DEC/COMPAQ) 64bit platforms works on 32bit int,
-    // whereas long is 64bit - therefore:
-#ifdef __osf__
+    // whereas long is 64bit.  The same is true for FreeBSD (and probably
+    // for lots of other platforms).  Therefore:
+#if defined(__osf__) || defined(__FreeBSD__)
     *length >>= (8 * ((sizeof(int)) - lengthbyte));
 #else
     *length >>= (8 * ((sizeof(long)) - lengthbyte));
