--- libmpeg3/ifo.h.orig	Mon Feb 12 22:35:19 2001
+++ libmpeg3/ifo.h	Mon Nov  1 09:41:06 2004
@@ -194,6 +194,7 @@
 #define ID_TITLE_CELL_ADDR	7
 #define ID_TITLE_VOBU_ADDR_MAP 	8
 
+typedef off_t __off64_t;
 
 /**
  * Information Table - for internal use only
