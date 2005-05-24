--- lib/CSConv/csconv.c.orig	Tue May 17 04:10:30 2005
+++ lib/CSConv/csconv.c	Tue May 17 04:11:40 2005
@@ -64,7 +64,7 @@
     /* should we read other configuration files 
      * such as ~/.iiim/encoding.norm ?
      */
-    fp = fopen(CSCONV_DIR "/encoding.norm", "r");
+    fp = fopen(CSC_BASE_DIR_DEFAULT "/encoding.norm", "r");
     if (!fp) return -1;
 
     while((fgets(buf, sizeof(buf), fp) != NULL)) {
