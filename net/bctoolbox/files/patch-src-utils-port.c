--- src/utils/port.c.orig	2025-03-11 08:53:26 UTC
+++ src/utils/port.c
@@ -361,7 +361,7 @@ void bctbx_set_self_thread_name(const char *name) {
 	prctl(PR_SET_NAME, name, NULL, NULL, NULL);
 #elif TARGET_OS_MAC
 	pthread_setname_np(name);
-#elif
+#else
 	bctbx_warning("bctbx_set_self_thread_name(): not implemented on this platform.");
 #endif
 }
@@ -1639,7 +1639,7 @@ void bctbx_sockaddr_remove_nat64_mapping(const struct 
 		if (htonl(0x0064ff9b) ==
 #ifdef _MSC_VER
 		    ((in6->sin6_addr.u.Word[0] << 16) & in6->sin6_addr.u.Word[1])
-#elif __APPLE__
+#elif __APPLE__ || __FreeBSD__
 		    in6->sin6_addr.__u6_addr.__u6_addr32[0]
 #else
 		    in6->sin6_addr.s6_addr32[0]
