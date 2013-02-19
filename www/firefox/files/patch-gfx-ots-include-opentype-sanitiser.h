diff --git gfx/ots/include/opentype-sanitiser.h gfx/ots/include/opentype-sanitiser.h
index f42822e..1a5a699 100644
--- gfx/ots/include/opentype-sanitiser.h
+++ gfx/ots/include/opentype-sanitiser.h
@@ -44,6 +44,13 @@ typedef unsigned __int64 uint64_t;
 #include <stdint.h>
 #endif
 
+#ifdef __FreeBSD__
+# include <osreldate.h>
+# if __FreeBSD_version < 800067
+#  include <sys/types.h> // for off_t
+# endif
+#endif
+
 #include <algorithm>  // for std::min
 #include <cassert>
 #include <cstddef>
