diff -urN -x .svn ../../vendor/vpopmail/vchkpw.c ./vchkpw.c
--- ../../vendor/vpopmail/vchkpw.c	Tue Oct  3 17:40:12 2006
+++ ./vchkpw.c	Tue Oct  3 17:58:48 2006
@@ -761,9 +762,6 @@
 
 int authapop(unsigned char *password, unsigned char *timestamp, unsigned char *clearpass)
 {
-#ifdef USE_ACTIVE_DIR
-  return(-1);
-#else
   MD5_CTX context;
   unsigned char digest[16];
   char encrypted[16*2+1];
@@ -782,5 +780,4 @@
   *s = '\0';
  
   return strcmp(password,encrypted);
-#endif
 }
