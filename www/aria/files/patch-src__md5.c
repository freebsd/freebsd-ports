--- src/md5.c.orig	2001-05-19 20:38:59.000000000 +0200
+++ src/md5.c	2003-08-07 01:34:12.000000000 +0200
@@ -291,8 +291,8 @@
 
     p = hd->buf;
   #ifdef BIG_ENDIAN_HOST
-    #define X(a) do { *p++ = hd->##a	  ; *p++ = hd->##a >> 8;      \
-		      *p++ = hd->##a >> 16; *p++ = hd->##a >> 24; } while(0)
+    #define X(a) do { *p++ = hd->a	  ; *p++ = hd->a >> 8;      \
+		      *p++ = hd->a >> 16; *p++ = hd->a >> 24; } while(0)
   #else /* little endian */
     /*#define X(a) do { *(u32*)p = hd->##a ; p += 4; } while(0)*/
     /* Unixware's cpp doesn't like the above construct so we do it his way:
