--- stats.h.orig	2007-05-28 06:12:52 UTC
+++ stats.h
@@ -89,10 +89,12 @@ struct stats {
 		reserved:4;
 };
 
-enum {
+typedef enum {
 	M_COUNTER, M_TV_START, M_TV_END, M_RECORD, M_MAX
-} measurement_tags;
+} measurement_tags_t;
 
+extern measurement_tags_t measurement_tags;
+
 struct measurement {
 	uint32_t counter;
 	struct timeval tv_start;
@@ -103,9 +105,11 @@ struct measurement {
 #define SHA1_DIGESTSIZE	20
 #endif
 
-enum {
+typedef enum {
 	SIG_NAME, SIG_DIGEST, SIG_DATA, SIG_COMPRESSED_DATA, SIG_MAX
-} signature_tags;
+} signature_tags_t;
+
+extern signature_tags_t signature_tags;
 
 struct signature {
 	char *name;
