--- init/halt.c.orig	2024-04-16 07:23:50 UTC
+++ init/halt.c
@@ -150,7 +150,7 @@ static int init_was_not_there(void)
 	 * mounting of /proc, happened. By that time init should be ready
 	 * for signals.
 	 */
-	while (access("/proc/meminfo", F_OK) != 0 && --cnt >= 0)
+	while (access("/compat/linux/proc/meminfo", F_OK) != 0 && --cnt >= 0)
 		sleep1();
 
 	/* Does it look like init wasn't there? */
@@ -169,8 +169,11 @@ int halt_main(int argc UNUSED_PARAM, char **argv)
 		RB_POWER_OFF,
 		RB_AUTOBOOT
 	};
+#if defined(__FreeBSD__)
+	static const smallint signals[] = { SIGUSR1, SIGUSR2, SIGINT };
+#else
 	static const smallint signals[] = { SIGUSR1, SIGUSR2, SIGTERM };
-
+#endif
 	int delay = 0;
 	int which, flags, rc;
 
