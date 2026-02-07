--- src/chm_lib.c.orig	2009-05-23 14:43:31 UTC
+++ src/chm_lib.c
@@ -149,6 +149,17 @@ typedef unsigned __int32        UInt32;
 typedef __int64                 Int64;
 typedef unsigned __int64        UInt64;
 
+/* FreeBSD */
+#elif __FreeBSD__
+#include <inttypes.h>
+typedef unsigned char           UChar;
+typedef int16_t                 Int16;
+typedef uint16_t                UInt16;
+typedef int32_t                 Int32;
+typedef uint32_t                UInt32;
+typedef int64_t                 Int64;
+typedef uint64_t                UInt64;
+
 /* I386, 32-bit, non-Windows */
 /* Sparc        */
 /* MIPS         */
