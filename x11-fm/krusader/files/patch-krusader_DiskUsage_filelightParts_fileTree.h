--- krusader/DiskUsage/filelightParts/fileTree.h.orig	Tue Nov 23 07:52:07 2004
+++ krusader/DiskUsage/filelightParts/fileTree.h	Thu Dec 16 18:35:46 2004
@@ -5,6 +5,7 @@
 #define FILETREE_H
 
 #include <stdlib.h>
+#include <sys/types.h>
 #include <kio/global.h>
 
 //TODO these are pointlessly general purpose now, make them incredibly specific
