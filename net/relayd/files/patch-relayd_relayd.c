--- relayd/relayd.c.orig	2014-08-10 20:08:47 UTC
+++ relayd/relayd.c
@@ -241,8 +241,7 @@ main(int argc, char *argv[])
 		log_info("startup");
 
 #ifdef __FreeBSD__
-#if __FreeBSD_version > 800040
-	arc4random_stir();
+#if __FreeBSD_version > 1000002
 	arc4random_buf(rnd, sizeof(rnd));
 	RAND_seed(rnd, sizeof(rnd));
 #else
