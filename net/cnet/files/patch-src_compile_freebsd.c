--- src/compile/freebsd.c.orig	Wed May 12 18:13:45 2004
+++ src/compile/freebsd.c	Sun Jun 12 20:05:45 2005
@@ -84,7 +84,7 @@
     cp			= (CACHE *)malloc(sizeof(CACHE));
     cp->so_filenm	= strdup(so_filenm);
     cp->length_data	= (nls[1].n_value - nls[0].n_value);
-    cp->incore_data	= (char *)((long)dlsym(handle,"end") - cp->length_data);
+    cp->incore_data	= (char *)((long)dlsym(handle,"_end") - cp->length_data);
     cp->original_data	= (char *)malloc(cp->length_data);
     memcpy(cp->original_data, cp->incore_data, cp->length_data);
     cp->next		= chd;
