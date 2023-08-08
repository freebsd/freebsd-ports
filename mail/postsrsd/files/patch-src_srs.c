--- src/srs.c.orig	2023-07-15 18:53:41 UTC
+++ src/srs.c
@@ -21,6 +21,7 @@
 
 #include <ctype.h>
 #include <string.h>
+#include <strings.h>
 
 char* postsrsd_forward(const char* addr, const char* domain, srs_t* srs,
                        database_t* db, domain_set_t* local_domains, bool* error,
