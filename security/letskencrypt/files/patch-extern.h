--- extern.h.orig	2016-07-24 05:54:33 UTC
+++ extern.h
@@ -188,7 +188,7 @@ int		 fileproc(int, const char *);
 int		 keyproc(int, const char *,
 			const char **, size_t, int);
 int		 netproc(int, int, int, int, int, int, int, int, int,
-			const char *const *, size_t);
+			const char *const *, size_t, const char *);
 
 /*
  * Debugging functions.
