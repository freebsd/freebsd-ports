--- pgp4pine/md5.c.orig	Sun Mar  7 13:55:00 2004
+++ pgp4pine/md5.c	Sun Mar  7 13:55:02 2004
@@ -288,8 +288,8 @@
 
     p = hd->buf;
 #ifdef WORDS_BIGENDIAN
-#define X(a) do { *p++ = hd->##a	  ; *p++ = hd->##a >> 8;      \
-		      *p++ = hd->##a >> 16; *p++ = hd->##a >> 24; } while(0)
+#define X(a) do { *p++ = (*hd).a	  ; *p++ = (*hd).a >> 8;      \
+		  *p++ = (*hd).a >> 16;     *p++ = (*hd).a >> 24; } while(0)
 #else /* little endian */
     /*#define X(a) do { *(u_int32_t*)p = hd->##a ; p += 4; } while(0)*/
     /* Unixware's cpp doesn't like the above construct so we do it his way:
