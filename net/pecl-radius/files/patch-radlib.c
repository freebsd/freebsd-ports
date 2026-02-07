--- radlib.c.orig	2025-05-06 17:27:50 UTC
+++ radlib.c
@@ -748,7 +748,6 @@ rad_auth_open(void)
 
 	h = (struct rad_handle *)malloc(sizeof(struct rad_handle));
 	if (h != NULL) {
-		php_srand(time(NULL) * getpid() * (unsigned long) (php_combined_lcg() * 10000.0));
 		h->fd = -1;
 		h->num_servers = 0;
 		h->ident = (zend_long) php_mt_rand();
