Index: saslauthd/saslcache.c
diff -u -p saslauthd/saslcache.c.orig saslauthd/saslcache.c
--- saslauthd/saslcache.c.orig	Sat Mar 29 04:59:24 2003
+++ saslauthd/saslcache.c	Thu Dec 14 13:44:41 2006
@@ -137,7 +137,7 @@ int main(int argc, char **argv) {
 	}
 
 	table_stats = shm_base + 64;
-	(char *)table = (char *)table_stats + 128;
+	table = (struct bucket *)((char *)table_stats + 128);
 
 	if (dump_stat_info == 0 && dump_user_info == 0)
 		dump_stat_info = 1;
