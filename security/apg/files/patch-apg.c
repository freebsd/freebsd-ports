Description: Fix a segfault with crypt(3) password encryption.
Origin: Debian; http://bugs.debian.org/337116
Forwarded: yes
Author: Paul Martin <pm@debian.org>
Last-Update: 2010-12-23

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
