--- less.h	2000/05/22 23:34:52	1.8
+++ less.h	2004/03/08 21:33:32
@@ -114,7 +114,7 @@
  * its users aren't careful.  Access through the macros is considered
  * careful.
  */
-GLOBAL(enum error erreur, NULL);
+GLOBAL(enum error erreur, E_OK);
 GLOBAL(char *errstr, NULL);  /* must point be null or free()'ble */
 
 #define SETERR(e) do { \
