--- include/bterror.h.old	Thu Feb 26 17:38:32 2004
+++ include/bterror.h	Thu Feb 26 17:38:53 2004
@@ -15,15 +15,6 @@
     BTERR_LAST
 };
 
-#ifdef BTERROR_BODY
-char *bterror_string[] = {
-    "Bad protocol ID on peer connection",
-    "Unrecognized Flags in peer protocol handshake",
-    "Peer hash value doesn't match my hash value",
-    "Peer disconnected after repeated errors"
-};
-#else
 extern char *bterror_string[];
-#endif
 
 #endif 
