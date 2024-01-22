--- tests/sni_test.c.orig	2024-01-22 07:32:06 UTC
+++ tests/sni_test.c
@@ -1,10 +1,10 @@
-extern "C" {
+//extern "C" {
 void *sni_new();
 void sni_free(void *sni, void (*cb)(void *user));
 int sni_add(void *sni, const char *hostname, void *user);
 void *sni_remove(void *sni, const char *hostname);
 void *sni_find(void *sni, const char *hostname);
-}
+//}
 
 #include <assert.h>
 #include <stdio.h>
