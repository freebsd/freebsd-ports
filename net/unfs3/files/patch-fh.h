--- fh.h.orig	2022-11-17 12:27:31 UTC
+++ fh.h
@@ -30,8 +30,6 @@ typedef struct {
 #define FH_ANY 0
 #define FH_DIR 1
 
-#define FD_NONE (-1)			/* used for get_gen */
-
 extern int st_cache_valid;		/* stat value is valid */
 extern backend_statstruct st_cache;	/* cached stat value */
 
