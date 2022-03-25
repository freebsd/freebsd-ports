Patch to silence a warning, until adopted by upstream (issue #101)

--- src/fts-backend-xapian.cpp.orig	2022-03-25 21:16:29 UTC
+++ src/fts-backend-xapian.cpp
@@ -750,7 +750,7 @@ struct fts_backend fts_backend_xapian =
 {
 	.name = "xapian",
 	.flags = FTS_BACKEND_FLAG_BUILD_FULL_WORDS,
-	{
+	.v = {
 		fts_backend_xapian_alloc,
 		fts_backend_xapian_init,
 		fts_backend_xapian_deinit,
