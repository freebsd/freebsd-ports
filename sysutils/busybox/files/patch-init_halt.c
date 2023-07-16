--- init/halt.c.orig	2021-01-01 10:52:27 UTC
+++ init/halt.c
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
 
