--- directory/c-sdk/ldap/libraries/liblber/lber-int.h	Tue Mar 26 13:53:23 2002
+++ directory/c-sdk/ldap/libraries/liblber/lber-int.h	Sat Dec 13 13:02:49 2003
@@ -236,15 +236,15 @@
 	     (((_l)&0xff0000)>>8) + (((_l)&0xff000000)>>24))
 #define LBER_NTOHL(_l) LBER_HTONL(_l)
 
-#elif !defined(__alpha) || defined(VMS)
+#elif !defined(__amd64__) && (!defined(__alpha) || defined(VMS))
 
 #define LBER_HTONL( l )	htonl( l )
 #define LBER_NTOHL( l )	ntohl( l )
 
 #else /* __alpha */
 /*
- * htonl and ntohl on the DEC Alpha under OSF 1 seem to only swap the
- * lower-order 32-bits of a (64-bit) long, so we define correct versions
+ * htonl and ntohl on the 64 bit UNIX platforms only swap the lower-order
+ * 32-bits of a (64-bit) long, so we define correct versions
  * here.
  */
 #define LBER_HTONL( l )	(((long)htonl( (l) & 0x00000000FFFFFFFF )) << 32 \
@@ -252,7 +252,7 @@
 
 #define LBER_NTOHL( l )	(((long)ntohl( (l) & 0x00000000FFFFFFFF )) << 32 \
     			| ntohl( ( (l) & 0xFFFFFFFF00000000 ) >> 32 ))
-#endif /* __alpha */
+#endif /* __alpha || __amd64__ */
 
 
 /* function prototypes */
