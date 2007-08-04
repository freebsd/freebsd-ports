--- md5.h.orig	2007-08-04 13:45:30.000000000 +0400
+++ md5.h	2007-08-04 13:41:19.000000000 +0400
@@ -21,11 +21,15 @@
 typedef unsigned short int UINT2;
 
 /* UINT4 defines a four byte word */
+#if 0
 #if defined(__alpha) && (defined(__osf__) || defined(__linux__))
 typedef unsigned int UINT4;
 #else
 typedef unsigned long int UINT4;
 #endif
+#endif
+#include <sys/types.h>
+typedef uint32_t UINT4;
 
 /* PROTO_LIST is defined depending on how PROTOTYPES is defined above.
    If using PROTOTYPES, then PROTO_LIST returns the list, otherwise it
