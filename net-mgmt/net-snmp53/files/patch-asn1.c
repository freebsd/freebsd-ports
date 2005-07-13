--- snmplib/asn1.c.orig	Fri Dec 10 18:07:16 2004
+++ snmplib/asn1.c	Fri Jun 10 20:09:34 2005
@@ -181,6 +181,9 @@
 #include <in.h>
 #endif
 
+#if HAVE_UNISTD_H
+#include <unistd.h>
+#endif
 #if HAVE_DMALLOC_H
 #include <dmalloc.h>
 #endif
@@ -584,6 +587,11 @@
         return NULL;
     }
     integer = *intp;
+    if (intsize > 4) {
+	register u_long signmask = ((u_long)1 << ((8 * sizeof(long)) - 1));
+	register u_long signbit = ((integer & signmask) != 0);
+	integer &= (signbit << 31) | 0x7fffffff;
+    }
     /*
      * Truncate "unnecessary" bytes off of the most significant end of this
      * 2's complement integer.  There should be no sequence of 9
@@ -663,6 +671,9 @@
         return NULL;
     }
     integer = *intp;
+    if (intsize > 4) {
+	integer &= 0xffffffff;
+    }
     mask = ((u_long) 0xFF) << (8 * (sizeof(long) - 1));
     /*
      * mask is 0xFF000000 on a big-endian machine 
@@ -2668,19 +2679,26 @@
     register long   integer = *intp;
     int             testvalue = (*intp < 0) ? -1 : 0;
     size_t          start_offset = *offset;
+    int             imaxbytes = 4;
 
     if (intsize != sizeof(long)) {
         _asn_size_err(errpre, intsize, sizeof(long));
         return 0;
     }
 
+    if (intsize > 4) {
+	register u_long signmask = ((u_long)1 << ((8 * sizeof(long)) - 1));
+	register u_long signbit = ((integer & signmask) != 0);
+	integer &= (signbit << 31) | 0x7fffffff;
+    }
+
     if (((*pkt_len - *offset) < 1) && !(r && asn_realloc(pkt, pkt_len))) {
         return 0;
     }
     *(*pkt + *pkt_len - (++*offset)) = (u_char) integer;
     integer >>= 8;
 
-    while (integer != testvalue) {
+    while (integer != testvalue && (--imaxbytes)) {
         if (((*pkt_len - *offset) < 1)
             && !(r && asn_realloc(pkt, pkt_len))) {
             return 0;
@@ -2823,6 +2841,10 @@
     if (intsize != sizeof(unsigned long)) {
         _asn_size_err(errpre, intsize, sizeof(unsigned long));
         return 0;
+    }
+
+    if (intsize > 4) {
+	integer &= 0xffffffff;
     }
 
     if (((*pkt_len - *offset) < 1) && !(r && asn_realloc(pkt, pkt_len))) {
