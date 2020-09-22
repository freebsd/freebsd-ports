--- tagging.h.orig	2020-09-22 13:41:40 UTC
+++ tagging.h
@@ -44,12 +44,14 @@ struct hash {
 	u_char digest[SHINGLE_SIZE];
 };
 
-enum {
+typedef enum {
 	REC_TV_START, REC_TV_END, REC_SRC, REC_DST, REC_SRC_PORT, REC_DST_PORT,
 	REC_PROTO, REC_STATE, REC_OS_FP, REC_HASH, REC_BYTES, REC_FLAGS,
 	REC_MAX_TAGS
-} record_tags;
+} record_tags_t;
 
+extern record_tags_t record_tags;
+
 #define RECORD_STATE_NEW	0x01
 
 struct record {
@@ -69,9 +71,11 @@ struct record {
 	TAILQ_HEAD(hashq, hash) hashes;	/* optional */
 };
 
-enum {
+typedef enum {
 	ADDR_TYPE, ADDR_BITS, ADDR_ADDR, ADDR_MAX_TAGS
-} address_tags;
+} address_tags_t;
+
+extern address_tags_t address_tags;
 
 void record_marshal(struct evbuffer *, struct record *);
 
