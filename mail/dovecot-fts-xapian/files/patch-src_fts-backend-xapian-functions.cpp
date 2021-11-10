--- src/fts-backend-xapian-functions.cpp.orig	2021-11-10 13:09:44 UTC
+++ src/fts-backend-xapian-functions.cpp
@@ -505,7 +505,17 @@ static long fts_backend_xapian_current_time()
 
 static long fts_backend_xapian_get_free_memory() // KB
 {
-	return long(sysconf(_SC_AVPHYS_PAGES)*sysconf(_SC_PAGE_SIZE) / 1024.0);
+#ifdef __FreeBSD__
+	uint32_t m;
+	size_t len = sizeof(m);
+	sysctlbyname("vm.stats.vm.v_free_count", &m, &len, NULL, 0);
+	if(fts_xapian_settings.verbose>1) i_info("FTS Xapian: (BSD) Free pages %ld",long(m));
+	m = m * fts_xapian_settings.pagesize / 1024.0;
+	if(fts_xapian_settings.verbose>1) i_info("FTS Xapian: (BSD) Free memory %ld kB",long(m));
+	return long(m);
+#else
+	return long(sysconf(_SC_AVPHYS_PAGES) * fts_xapian_settings.pagesize / 1024.0);
+#endif
 }
 
 static bool fts_backend_xapian_test_memory()
@@ -1100,7 +1110,7 @@ bool fts_backend_xapian_index_text(struct xapian_fts_b
 
 	XResultSet * result=fts_backend_xapian_query(dbx,xq,1);
 
-	Xapian::docid docid;
+	Xapian::docid docid = 0;
 	Xapian::Document * doc = NULL;
 
 	try
