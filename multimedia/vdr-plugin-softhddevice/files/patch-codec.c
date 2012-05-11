--- a/codec.c
+++ b/codec.c
@@ -37,7 +37,11 @@
 
 #include <stdio.h>
 #include <unistd.h>
+#ifdef __FreeBSD__
+#include <sys/endian.h>
+#else
 #include <endian.h>
+#endif
 
 #include <sys/types.h>
 #include <sys/stat.h>
