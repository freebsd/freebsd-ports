--- mod_auth_mysql.c	Sat May 10 16:12:34 2003
+++ mod_auth_mysql.c	Sun Jan 11 13:16:47 2004
@@ -97,6 +97,7 @@
  * MODULE-DEFINITION-END
  */
 
+#define MYSQL_CRYPT_LEN 17U
 
 #ifdef APACHE2
 #define PCALLOC apr_pcalloc
@@ -617,7 +618,8 @@
   conn_rec *c = r->connection;
   const char *sent_pw, *real_pw;
   int res;
-  char *scrambled_sent_pw;
+  unsigned long hash_res[2];
+  char scrambled_sent_pw[MYSQL_CRYPT_LEN];
 
   if ((res = ap_get_basic_auth_pw (r, &sent_pw)))
     return res;
@@ -658,8 +660,10 @@
 
   /* if AuthMySQLScrambledPassword is On, compare the scrambled password */
   if(sec->mysqlScrambled) {
-    scrambled_sent_pw = PCALLOC(r->pool, 33);
-    make_scrambled_password(scrambled_sent_pw, sent_pw);
+    /* make_scrambled_password(scrambled_sent_pw, sent_pw); */
+    hash_password(hash_res, sent_pw);
+    snprintf(scrambled_sent_pw, sizeof scrambled_sent_pw, "%08lx%08lx",
+    	hash_res[0], hash_res[1]);
     if(strcmp(real_pw, scrambled_sent_pw)) {
 	  passwords_match = 0;
     }
