--- di.c.old	Tue Oct 23 11:48:51 2007
+++ di.c	Tue Oct 23 11:49:19 2007
@@ -267,10 +267,8 @@
     char            *disp;
 } dispTable_t;
 
-#if ! _lib_zone_list
-# define zoneid_t       int
-# define ZONENAME_MAX   65
-#endif
+#define zoneid_t       int
+#define ZONENAME_MAX   65
 
 typedef struct {
     zoneid_t    zoneid;
