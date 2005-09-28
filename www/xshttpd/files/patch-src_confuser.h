--- src/confuser.h	Thu Dec  2 14:26:32 2004
+++ src/confuser.h	Fri Sep 23 17:09:20 2005
@@ -78,7 +78,7 @@
 mime.types file are NOT standard. Read the comments in the default
 mime.types for details. */
 
-#define MIMETYPESFILE "mime.types"
+#define MIMETYPESFILE "@LOCALBASE@/etc/mime.types"
 
 /* What is the bit bucket on your system? */
 
