diff --git third_party/sqlite3/ext/sqlite-vec/sqlite-vec.c third_party/sqlite3/ext/sqlite-vec/sqlite-vec.c
index 96612e26d385..c43c46136bef 100644
--- third_party/sqlite3/ext/sqlite-vec/sqlite-vec.c
+++ third_party/sqlite3/ext/sqlite-vec/sqlite-vec.c
@@ -11,6 +11,10 @@
 #include <stdlib.h>
 #include <string.h>
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#endif
+
 #ifndef SQLITE_VEC_OMIT_FS
 #include <stdio.h>
 #endif
