--- servers/slapd/daemon.c.orig	2021-08-18 17:11:41 UTC
+++ servers/slapd/daemon.c
@@ -228,10 +228,9 @@ static slap_daemon_st *slap_daemon;
 } while (0)
 
 /* a kqueue fd obtained before a fork can't be used in child process.
- * close it and reacquire it.
+ * reacquire it.
  */
 # define SLAP_SOCK_INIT2() do { \
-	close(slap_daemon[0].sd_kq); \
 	slap_daemon[0].sd_kq = kqueue(); \
 } while (0)
 
