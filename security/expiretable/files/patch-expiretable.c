--- expiretable.c.orig	2006-01-18 22:47:01 UTC
+++ expiretable.c
@@ -290,6 +290,7 @@ main(int argc, char *const *argv) {
 			for (i = 0; i < astats_count; i++) {
 				if (astats[i].pfras_tzero <= min_timestamp) {
 					del_addrs_list[del_addrs_count] = astats[i].pfras_a;
+					del_addrs_list[del_addrs_count].pfra_fback = 0;
 					del_addrs_count++;
 				}
 			}
