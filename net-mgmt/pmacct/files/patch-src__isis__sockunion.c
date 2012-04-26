--- ./src/isis/sockunion.c.orig	2012-04-26 16:51:31.000000000 -0400
+++ ./src/isis/sockunion.c	2012-04-26 16:51:56.000000000 -0400
@@ -625,7 +625,7 @@
 	struct sockaddr_dl *sdl;
 
 	sdl = (struct sockaddr_dl *)&(su->sa);
-	printf ("link#%d\n", sdl->sdl_index);
+	//printf ("link#%d\n", sdl->sdl_index);
       }
       break;
 #endif /* AF_LINK */
