--- tube.h.orig	2011-06-24 15:37:57.000000000 +0400
+++ tube.h	2011-06-24 15:38:13.000000000 +0400
@@ -35,13 +35,13 @@
     char name[MAX_TUBE_NAME_LEN];
     struct pq ready;
     struct pq delay;
-    struct job buried;
     struct ms waiting; /* set of conns */
     struct stats stat;
     unsigned int using_ct;
     unsigned int watching_ct;
     usec pause;
     usec deadline_at;
+    struct job buried;
 };
 
 extern struct ms tubes;
