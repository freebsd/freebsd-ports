--- mod_auth_mysql.c.orig	Fri Jan  9 22:13:01 2004
+++ mod_auth_mysql.c	Fri Jan  9 22:13:12 2004
@@ -692,7 +692,7 @@
   /* if AuthMySQLScrambledPassword is On, compare the scrambled password */
   if(sec->mysqlScrambled) {
     scrambled_sent_pw = PCALLOC(r->pool, 33);
-    make_scrambled_password(scrambled_sent_pw, sent_pw, NULL, 0);
+    make_scrambled_password(scrambled_sent_pw, sent_pw);
     if(strcmp(real_pw, scrambled_sent_pw)) {
 	  passwords_match = 0;
     }
