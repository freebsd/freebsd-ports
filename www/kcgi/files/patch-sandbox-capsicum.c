--- sandbox-capsicum.c.orig	2015-05-17 21:02:13 UTC
+++ sandbox-capsicum.c
@@ -55,9 +55,7 @@ ksandbox_capsicum_init_child(void *arg, 
 	rl_zero.rlim_cur = rl_zero.rlim_max = 0;
 
 	if (-1 == setrlimit(RLIMIT_NOFILE, &rl_zero))
-		XWARNX("setrlimit: rlimit_fsize");
-	if (-1 == setrlimit(RLIMIT_FSIZE, &rl_zero))
-		XWARNX("setrlimit: rlimit_fsize");
+		XWARNX("setrlimit: rlimit_nofile");
 	if (-1 == setrlimit(RLIMIT_NPROC, &rl_zero))
 		XWARNX("setrlimit: rlimit_nproc");
 
