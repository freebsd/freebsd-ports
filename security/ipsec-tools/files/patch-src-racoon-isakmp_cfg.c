--- src/racoon/isakmp_cfg.c
+++ src/racoon/isakmp_cfg.c
@@ -38,7 +38,9 @@
 #include <sys/socket.h>
 #include <sys/queue.h>
 
+#if __FreeBSD_version >= 900007
 #include <utmpx.h>
+#endif
 #if defined(__APPLE__) && defined(__MACH__)
 #include <util.h>
 #endif
@@ -1663,6 +1665,7 @@
 	char *usr;
 	int inout;
 {
+#if __FreeBSD_version >= 900007
 	int error = 0;
 	struct utmpx ut;
 	char addr[NI_MAXHOST];
@@ -1706,6 +1709,7 @@
 		plog(LLV_ERROR, LOCATION, NULL, "Unepected inout\n");
 		break;
 	}
+#endif
 
 	return 0;
 }
