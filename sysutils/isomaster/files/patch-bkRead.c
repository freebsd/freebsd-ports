--- bk/bkRead.c.orig	Thu Dec 28 16:48:10 2006
+++ bk/bkRead.c
@@ -46,6 +46,7 @@
 {
     int rc;
     struct stat statStruct;
+    int len;
     
     volInfo->imageForReading = open(filename, O_RDONLY);
     if(volInfo->imageForReading == -1)
@@ -62,7 +63,7 @@
     volInfo->imageForReadingInode = statStruct.st_ino;
     
     /* skip the first 150 sectors if the image is an NRG */
-    int len = strlen(filename);
+    len = strlen(filename);
     if( (filename[len - 3] == 'N' || filename[len - 3] == 'n') &&
         (filename[len - 2] == 'R' || filename[len - 2] == 'r') &&
         (filename[len - 1] == 'G' || filename[len - 1] == 'g') )
@@ -105,6 +106,11 @@
     unsigned realRootLoc; /* location of the root dr inside root dir */
     unsigned char recordLen; /* length of rood dr */
     unsigned char sPsUentry[7]; /* su entry SP */
+
+    off_t locationOfNextDescriptor;
+    unsigned bootCatalogLocation; /* logical sector number */
+    char elToritoSig[24];
+    unsigned char bootMediaType;
     
     /* will always have this unless image is broken */
     volInfo->filenameTypes = FNTYPE_9660;
@@ -224,10 +230,6 @@
     /* END SKIP all extra copies of pvd */
     
     /* TRY read boot record */
-    off_t locationOfNextDescriptor;
-    unsigned bootCatalogLocation; /* logical sector number */
-    char elToritoSig[24];
-    unsigned char bootMediaType;
     
     locationOfNextDescriptor = lseek(volInfo->imageForReading, 0, SEEK_CUR) + 2048;
     
