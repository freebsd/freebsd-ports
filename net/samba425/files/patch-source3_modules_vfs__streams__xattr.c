--- source3/modules/vfs_streams_xattr.c.orig	2026-08-10 19:16:53 UTC
+++ source3/modules/vfs_streams_xattr.c
@@ -22,6 +22,13 @@
  */
 
 #include "includes.h"
+#ifndef ENODATA
+#ifdef ENOATTR
+#define ENODATA ENOATTR
+#else
+#define ENODATA ENOENT
+#endif
+#endif
 #include "smbd/smbd.h"
 #include "system/filesys.h"
 #include "lib/util/tevent_unix.h"
@@ -424,7 +431,8 @@ static int streams_xattr_get_ea_value_fsp(
 		return EACCES;
 	}
 
-	if (attr_size > (SIZE_MAX / config->max_extents)) {
+	if (config->max_extents > 0 &&
+	    attr_size > (SIZE_MAX / config->max_extents)) {
 		return EOVERFLOW;
 	}
 	max_stream_size = attr_size * config->max_extents;
