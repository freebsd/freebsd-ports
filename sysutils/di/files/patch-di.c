--- C/di.c.orig	2011-01-01 15:25:04.000000000 -0500
+++ C/di.c	2011-01-02 15:31:35.000000000 -0500
@@ -252,10 +252,8 @@
     char            *disp[2];
 } dispTable_t;
 
-#if ! _lib_zone_list
-# define zoneid_t       int
-# define ZONENAME_MAX   65
-#endif
+#define zoneid_t       int
+#define ZONENAME_MAX   65
 
 typedef struct {
     zoneid_t    zoneid;
