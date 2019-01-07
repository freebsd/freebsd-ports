--- src/bsdapm.h.orig	2018-12-02 18:26:02 UTC
+++ src/bsdapm.h
@@ -29,8 +29,8 @@
 #ifndef _BSDAPM_H
 #define _BSDAPM_H
 
-void print_apm_adapter(struct text_object *, char *, int);
-void print_apm_battery_life(struct text_object *, char *, int);
-void print_apm_battery_time(struct text_object *, char *, int);
+void print_apm_adapter(struct text_object *, char *, unsigned int);
+void print_apm_battery_life(struct text_object *, char *, unsigned int);
+void print_apm_battery_time(struct text_object *, char *, unsigned int);
 
 #endif /* _BSDAPM_H */
