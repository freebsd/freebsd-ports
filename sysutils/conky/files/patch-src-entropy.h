--- src/entropy.h.orig
+++ src/entropy.h
@@ -31,7 +31,7 @@
 #ifndef _ENTROPY_H
 #define _ENTROPY_H
 
-void update_entropy(void);
+int update_entropy(void);
 
 void print_entropy_avail(struct text_object *, char *, int);
 void print_entropy_perc(struct text_object *, char *, int);
