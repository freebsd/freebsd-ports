commit 6336890d9f6eff8cc697b50d6e29a665b3b66050
Author: Christoph Moench-Tegeder <cmt@FreeBSD.org>

    additional include on FreeBSD

diff --git third_party/sqlite3/ext/sqlite-vec/sqlite-vec.c third_party/sqlite3/ext/sqlite-vec/sqlite-vec.c
index 5511263765d7..6f9d64c730de 100644
--- third_party/sqlite3/ext/sqlite-vec/sqlite-vec.c
+++ third_party/sqlite3/ext/sqlite-vec/sqlite-vec.c
@@ -11,6 +11,10 @@
 #include <stdlib.h>
 #include <string.h>
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#endif
+
 #ifdef SQLITE_VEC_DEBUG
 #include <stdio.h>
 #endif
