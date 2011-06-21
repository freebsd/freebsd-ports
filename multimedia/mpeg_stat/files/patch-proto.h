--- proto.h.orig	2011-06-21 13:38:56.000000000 +0200
+++ proto.h	2011-06-21 13:37:22.000000000 +0200
@@ -87,7 +87,7 @@
 #else
 void int_handler P((int signum ));
 #endif
-void main P((int argc , char **argv ));
+int main P((int argc , char **argv ));
 void Usage P((void ));
 void DoDitherImage P((unsigned char *l , unsigned char *Cr , unsigned char *Cb , unsigned char *disp , int h , int w ));
 
