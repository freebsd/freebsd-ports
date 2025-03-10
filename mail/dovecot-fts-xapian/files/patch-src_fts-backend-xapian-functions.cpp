--- src/fts-backend-xapian-functions.cpp.orig	2025-01-01 12:38:47 UTC
+++ src/fts-backend-xapian-functions.cpp
@@ -21,7 +21,7 @@ static long fts_backend_xapian_get_free_memory(int ver
 		if(verbose>1) syslog(LOG_WARNING,"FTS Xapian: Memory limit not available from getrlimit (probably vsz_limit not set");
 #if defined(__FreeBSD__) || defined(__NetBSD__)
         	u_int page_size;
-        	uint_size uint_size = sizeof(page_size);
+        	size_t uint_size = sizeof(page_size);
         	sysctlbyname("vm.stats.vm.v_page_size", &page_size, &uint_size, NULL, 0);
         	struct vmtotal vmt;
         	size_t vmt_size = sizeof(vmt);
@@ -906,7 +906,7 @@ class XDocsWriter
 
 			if(sqlite3_exec(db,sql.c_str(),NULL,0,&zErrMsg) != SQLITE_OK )
                 	{
-                        	syslog(LOG_ERR,"FTS Xapian: Can not replace keyword : %s",sql.c_str(),zErrMsg);
+                        	syslog(LOG_ERR,"FTS Xapian: Can not replace keyword %s: %s",sql.c_str(),zErrMsg);
                         	sqlite3_free(zErrMsg);
                         	sqlite3_close(db);
                         	return;
@@ -1531,7 +1531,7 @@ static void fts_backend_xapian_build_qs(XQuerySet * qs
 				std::vector<icu::UnicodeString *> st; st.clear();
 				if(sqlite3_exec(db,sql.c_str(),fts_backend_xapian_sqlite3_vector_icu,&st,&zErrMsg) != SQLITE_OK )
                         	{
-                        	        syslog(LOG_ERR,"FTS Xapian: Can not search keyword : %s",sql.c_str(),zErrMsg);
+                        	        syslog(LOG_ERR,"FTS Xapian: Can not search keyword %s: %s",sql.c_str(),zErrMsg);
                                 	sqlite3_free(zErrMsg);
                         	}
 				sqlite3_close(db);	
