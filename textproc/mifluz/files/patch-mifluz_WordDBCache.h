--- mifluz/WordDBCache.h.orig	2007-11-22 12:12:34.000000000 +0100
+++ mifluz/WordDBCache.h	2007-11-22 12:15:53.000000000 +0100
@@ -149,8 +149,8 @@
   inline int Absolute() {
     int i;
     for(i = 0; i < entries_length; i++) {
-      entries[i].key = pool + (int)(entries[i].key);
-      entries[i].data = pool + (int)(entries[i].data);
+      entries[i].key = pool + (long)(entries[i].key);
+      entries[i].data = pool + (long)(entries[i].data);
     }
     return OK;
   }
