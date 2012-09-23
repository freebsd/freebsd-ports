
$FreeBSD$

--- apg.c.orig
+++ apg.c
@@ -709,7 +709,7 @@
 */
 char * crypt_passstring (const char *p)
 {
- char salt[10];
+ char salt[11];
  gen_rand_pass (salt, 10, 10, S_SL|S_CL|S_NB);
  return (crypt(p, salt));
 }
