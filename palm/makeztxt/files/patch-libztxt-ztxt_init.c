--- libztxt/ztxt_init.c.orig	Mon May 28 20:23:08 2007
+++ libztxt/ztxt_init.c	Mon May 28 20:23:16 2007
@@ -61,7 +61,7 @@
 
   /* Initialize the Palm DB header structure */
   header = ztxtdb->dbHeader;
-  strcpy(header->name, "New zTXT database");
+  strcpy((char *)header->name, "New zTXT database");
   header->attributes = htons(dmHdrAttrBackup);
   header->version = htons(ZTXT_VERSION);
   header->creationDate = htonl(time(NULL) + PALM_CTIME_OFFSET);
