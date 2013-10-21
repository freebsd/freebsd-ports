--- ./src/proto/tlv.c.orig	2012-01-01 16:17:19.000000000 -0800
+++ ./src/proto/tlv.c	2013-10-20 23:22:04.000000000 -0700
@@ -41,7 +41,7 @@
 	    *(src + srclen) = '\0';
 	    len = srclen * 4 + 1;
 	    str = my_malloc(len);
-	    strnvis(str, src, len, VIS_NL|VIS_TAB|VIS_GLOB|VIS_OCTAL);
+	    strnvis(str, len, src, VIS_NL|VIS_TAB|VIS_GLOB|VIS_OCTAL);
 	    break;
 	case PEER_CAP:
 	    memcpy(&cap, value, sizeof(uint16_t));
@@ -92,7 +92,7 @@
     *(str + srclen) = '\0';
     len = srclen * 4 + 1;
     safe = my_malloc(len);
-    strnvis(safe, str, len, VIS_SAFE|VIS_OCTAL);
+    strnvis(safe, len, str, VIS_SAFE|VIS_OCTAL);
     return safe;
 }
 
