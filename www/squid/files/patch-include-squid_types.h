--- include/squid_types.h.orig Mon Jul  7 00:45:26 2003
+++ include/squid_types.h      Mon Jul  7 00:48:39 2003
@@ -66,8 +66,5 @@
 #if HAVE_SYS_TYPES_H
 #include <sys/types.h>
 #endif
-#if HAVE_SYS_BITYPES_H
-#include <sys/bitypes.h>
-#endif

 #endif /* SQUID_TYPES_H */
