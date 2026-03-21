--- src/fts-backend-xapian-functions.cpp.orig	2025-08-26 00:29:45 UTC
+++ src/fts-backend-xapian-functions.cpp
@@ -21,7 +21,7 @@ static long fts_backend_xapian_get_free_memory(int ver
 		if(verbose>1) syslog(LOG_WARNING,"FTS Xapian: Memory limit not available from getrlimit (probably vsz_limit not set");
 #if defined(__FreeBSD__) || defined(__NetBSD__)
 		u_int page_size;
-		uint_size uint_size = sizeof(page_size);
+		size_t uint_size = sizeof(page_size);
 		sysctlbyname("vm.stats.vm.v_page_size", &page_size, &uint_size, NULL, 0);
 		struct vmtotal vmt;
 		size_t vmt_size = sizeof(vmt);
