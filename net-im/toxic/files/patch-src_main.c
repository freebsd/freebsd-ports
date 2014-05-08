--- src/main.c.orig	2014-04-20 22:43:14.000000000 +0200
+++ src/main.c	2014-04-21 12:44:27.000000000 +0200
@@ -169,6 +169,8 @@
 
 #ifdef __linux__
     tox_set_name(m, (uint8_t *) "Cool guy", strlen("Cool guy"));
+#elif defined(__FreeBSD__)
+    tox_set_name(m, (uint8_t *) "Very cool guy", strlen("Very cool guy"));
 #elif defined(_WIN32)
     tox_set_name(m, (uint8_t *) "I should install GNU/Linux", strlen("I should install GNU/Linux"));
 #elif defined(__APPLE__)
