--- config/config-data.h.orig	1998-11-10 03:59:47 UTC
+++ config/config-data.h
@@ -58,10 +58,10 @@ typedef 	struct dirent		DIRENTRY;
  * Set default write(2) return and amount types.
  */
 #if	!defined(WRITE_RETURN_T)
-#define		WRITE_RETURN_T		int	/* What write() returns */
+#define		WRITE_RETURN_T		ssize_t	/* What write() returns */
 #endif	/* WRITE_RETURN_T */
 #if	!defined(WRITE_AMT_T)
-#define		WRITE_AMT_T		int	/* Amount to write */
+#define		WRITE_AMT_T		size_t	/* Amount to write */
 #endif	/* WRITE_AMT_T */
 
 #endif	/* __configdata_h__ */
