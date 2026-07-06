--- progs/mincdump/mincdump.h.orig	2012-09-24 17:35:36 UTC
+++ progs/mincdump/mincdump.h
@@ -15,7 +15,7 @@
 #define  Printf  (void) printf
 
 typedef int boolean;
-enum {false=0, true=1};
+enum {my_false=0, my_true=1};
 
 struct ncdim {			/* dimension */
     char name[NC_MAX_NAME];
