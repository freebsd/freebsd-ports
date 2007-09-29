diff -rpu8 sysdep/common/md5.h sysdep-FIXED/common/md5.h
--- sysdep/common/md5.h	Sun Jan 28 23:38:47 2001
+++ sysdep-FIXED/common/md5.h	Sat Mar 25 02:47:19 2006
@@ -7,24 +7,26 @@
      function argument prototyping.
    The following makes PROTOTYPES default to 0 if it has not already
      been defined with C compiler flags.
  */
 #ifndef PROTOTYPES
 #define PROTOTYPES 1
 #endif
 
+#include <sys/types.h>
+
 /* POINTER defines a generic pointer type */
 typedef unsigned char *POINTER;
 
 /* UINT2 defines a two byte word */
-typedef unsigned short int UINT2;
+typedef u_int16_t UINT2;
 
 /* UINT4 defines a four byte word */
-typedef unsigned long int UINT4;
+typedef u_int32_t UINT4;
 
 /* PROTO_LIST is defined depending on how PROTOTYPES is defined above.
    If using PROTOTYPES, then PROTO_LIST returns the list, otherwise it
      returns an empty list.
  */
 
 #if PROTOTYPES
 #define PROTO_LIST(list) list
