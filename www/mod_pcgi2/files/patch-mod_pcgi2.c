--- mod_pcgi2.c.orig	Wed May  8 21:15:01 2002
+++ mod_pcgi2.c	Sun May 19 09:30:33 2002
@@ -166,12 +166,12 @@
 
 
 /* Merge resource records */
-#define CREATE_pcgi_mergef(name, addr, maxsz) static void pcgi_merge_##name##(pcgiResource *r, pcgiResource *base, pcgiResource *overrides) \
+#define CREATE_pcgi_mergef(name, addr, maxsz) static void pcgi_merge_##name(pcgiResource *r, pcgiResource *base, pcgiResource *overrides) \
 { \
-   if (overrides->##addr##[0]) { \
-      strncpy(r->##addr##, overrides->##addr##, maxsz); \
-   } else if (base->##addr##[0]) { \
-      strncpy(r->##addr##, base->##addr##, maxsz); \
+   if (overrides->addr[0]) { \
+      strncpy(r->addr, overrides->addr, maxsz); \
+   } else if (base->addr[0]) { \
+      strncpy(r->addr, base->addr, maxsz); \
    } \
 }
 
@@ -314,9 +314,9 @@
 
 
 /* Parse command parameters */
-#define CREATE_pcgi_setf(name, addr, maxsz) static const char *pcgi_set_##name##(cmd_parms *parms, void *r, const char *arg) \
+#define CREATE_pcgi_setf(name, addr, maxsz) static const char *pcgi_set_##name(cmd_parms *parms, void *r, const char *arg) \
 { \
-   strncpy(((pcgiResource *)r)->##addr##, arg, maxsz); \
+   strncpy(((pcgiResource *)r)->addr, arg, maxsz); \
    return NULL; \
 }
 
