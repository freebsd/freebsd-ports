--- src/bterror.c.old	Thu Feb 26 17:39:15 2004
+++ src/bterror.c	Thu Feb 26 17:39:54 2004
@@ -1,3 +1,9 @@
 /* bterror.c */
-#define BTERROR_BODY
 #include "bterror.h"
+
+char *bterror_string[] = {
+    "Bad protocol ID on peer connection",
+    "Unrecognized Flags in peer protocol handshake",
+    "Peer hash value doesn't match my hash value",
+    "Peer disconnected after repeated errors"
+};
