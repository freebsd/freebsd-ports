--- nam_stream.cc.orig	Thu Oct  3 11:32:39 2002
+++ nam_stream.cc	Thu Oct  3 11:33:21 2002
@@ -23,7 +23,7 @@
 #ifdef WIN32
 #include <limits.h>
 #else
-#include <values.h>
+#include <limits.h>
 #endif
 
 #include <assert.h>
@@ -429,7 +429,7 @@
 	switch(whence) {
 	case SEEK_SET: lim = offset; break;
 	case SEEK_CUR: lim = tell() + offset; break;
-	case SEEK_END: lim = MAXLONG; break; // XXX: MAXINT may not be max(off_t)
+	case SEEK_END: lim = LONG_MAX; break; // XXX: MAXINT may not be max(off_t)
 	}
 	insure_backing(lim);
 	if (0 == fseek(back_, offset, whence))
