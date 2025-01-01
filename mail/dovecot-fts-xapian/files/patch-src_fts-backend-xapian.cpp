--- src/fts-backend-xapian.cpp.orig	2025-01-01 12:39:49 UTC
+++ src/fts-backend-xapian.cpp
@@ -542,7 +542,7 @@ static int fts_backend_xapian_optimize(struct fts_back
 						}
 						i_free(u);
 					}
-					if(fts_xapian_settings.verbose>0) i_info("FTS Xapian: Optimize - Closing DB %s",s);
+					if(fts_xapian_settings.verbose>0) i_info("FTS Xapian: Optimize - Closing DB %s",s.c_str());
 					fts_backend_xapian_close_db(db,s.c_str(),"fts_optimize",fts_xapian_settings.verbose);
 				}
 				catch(Xapian::Error e)
