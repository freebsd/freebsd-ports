--- src/i8k.h.orig
+++ src/i8k.h
@@ -32,7 +32,7 @@
 #ifndef _I8K_H
 #define _I8K_H
 
-void update_i8k(void);
+int update_i8k(void);
 void print_i8k_left_fan_status(struct text_object *, char *, int);
 void print_i8k_cpu_temp(struct text_object *, char *, int);
 void print_i8k_right_fan_status(struct text_object *, char *, int);
