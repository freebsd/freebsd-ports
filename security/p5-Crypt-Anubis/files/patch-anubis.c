--- _anubis.c.orig	Sun May 16 10:04:36 2004
+++ _anubis.c	Sun May 16 10:05:13 2004
@@ -976,7 +976,7 @@
 void print_data(char *str, u8 *val, int len);
 int compare_blocks(u8 *m1, u8 *m2, int len_bits); /* 0=equal, 1=not eq. */
 
-int main(void)
+int main _((int argc, char** argv, char** env))
 {
   struct NESSIEstruct subkeys;
   u8 key[KEYSIZEB];
