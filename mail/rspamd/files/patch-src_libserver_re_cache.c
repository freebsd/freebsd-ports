From 98e731bf69306a830834fbcfa7a21c3357130693 Mon Sep 17 00:00:00 2001
From: Vsevolod Stakhov <vsevolod@rspamd.com>
Date: Thu, 18 Sep 2025 10:03:39 +0100
Subject: [PATCH] [Minor] Fix non-hyperscan build

Issue: #5620
---
 src/libserver/re_cache.c | 29 +++++++++++++++++++++--------
 1 file changed, 21 insertions(+), 8 deletions(-)

diff --git src/libserver/re_cache.c src/libserver/re_cache.c
index fc056ecd8..2aa93e0d3 100644
--- src/libserver/re_cache.c
+++ src/libserver/re_cache.c
@@ -899,7 +899,6 @@ rspamd_re_cache_hyperscan_cb(unsigned int id,
 	}
 	else {
 		if (!isset(rt->checked, id)) {
-
 			processed = 0;
 
 			for (i = 0; i < cbdata->count; i++) {
@@ -933,7 +932,6 @@ rspamd_re_cache_process_regexp_data(struct rspamd_re_runtime *rt,
 									gboolean is_raw,
 									gboolean *processed_hyperscan)
 {
-
 	uint64_t re_id;
 	unsigned int ret = 0;
 	unsigned int i;
@@ -1268,7 +1266,6 @@ rspamd_re_cache_process_headers_list(struct rspamd_task *task,
 
 	DL_FOREACH(rh, cur)
 	{
-
 		if (is_strong && strcmp(cur->name, re_class->type_data) != 0) {
 			/* Skip a different case */
 			continue;
@@ -1669,7 +1666,6 @@ rspamd_re_cache_exec_re(struct rspamd_task *task,
 											 re_class->type_data,
 											 (unsigned char ***) &scvec,
 											 &lenvec, &cnt)) {
-
 			ret = rspamd_re_cache_process_regexp_data(rt, re,
 													  task, scvec, lenvec, cnt, raw, &processed_hyperscan);
 			msg_debug_re_task("checked selector(%s) regexp: %s -> %d",
@@ -2080,7 +2076,6 @@ rspamd_re_cache_is_finite(struct rspamd_re_cache *cache,
 					   &cache->plt,
 					   &test_db,
 					   &hs_errors) != HS_SUCCESS) {
-
 			msg_info_re_cache("cannot compile (prefilter mode) '%s' to hyperscan: '%s'",
 							  pat,
 							  hs_errors != NULL ? hs_errors->message : "unknown error");
@@ -2146,7 +2141,9 @@ struct rspamd_re_cache_hs_compile_cbdata {
 	double max_time;
 	gboolean silent;
 	unsigned int total;
+
 	void (*cb)(unsigned int ncompiled, GError *err, void *cbd);
+
 	void *cbd;
 };
 
@@ -2210,7 +2207,6 @@ rspamd_re_cache_compile_timer_cb(EV_P_ ev_timer *w, int revents)
 					G_DIR_SEPARATOR, re_class->hash);
 
 	if (rspamd_re_cache_is_valid_hyperscan_file(cache, path, TRUE, TRUE, NULL)) {
-
 		fd = open(path, O_RDONLY, 00600);
 
 		/* Read number of regexps */
@@ -2376,7 +2372,6 @@ rspamd_re_cache_compile_timer_cb(EV_P_ ev_timer *w, int revents)
 								 &cache->plt,
 								 &test_db,
 								 &hs_errors) != HS_SUCCESS) {
-
 			err = g_error_new(rspamd_re_cache_quark(), EINVAL,
 							  "cannot create tree of regexp when processing '%s': %s",
 							  hs_pats[hs_errors->expression], hs_errors->message);
@@ -2560,7 +2555,9 @@ struct rspamd_re_cache_scoped_compile_data {
 	unsigned int completed_scopes;
 	unsigned int total_compiled;
 	GError *first_error;
+
 	void (*final_cb)(unsigned int ncompiled, GError *err, void *cbd);
+
 	void *final_cbd;
 };
 
@@ -3435,7 +3432,9 @@ struct rspamd_re_cache_hs_compile_scoped_cbdata {
 	double max_time;
 	gboolean silent;
 	int lock_fd;
+
 	void (*cb)(const char *scope, unsigned int ncompiled, GError *err, void *cbd);
+
 	void *cbd;
 };
 
@@ -3463,7 +3462,8 @@ int rspamd_re_cache_compile_hyperscan_scoped_single(struct rspamd_re_cache *cach
 													double max_time,
 													gboolean silent,
 													struct ev_loop *event_loop,
-													void (*cb)(const char *scope, unsigned int ncompiled, GError *err, void *cbd),
+													void (*cb)(const char *scope, unsigned int ncompiled, GError *err,
+															   void *cbd),
 													void *cbd)
 {
 	struct rspamd_re_cache_hs_compile_scoped_cbdata *scoped_cbd;
@@ -3495,4 +3495,17 @@ int rspamd_re_cache_compile_hyperscan_scoped_single(struct rspamd_re_cache *cach
 	return rspamd_re_cache_compile_hyperscan(cache, cache_dir, max_time, silent,
 											 event_loop, rspamd_re_cache_compile_scoped_cb, scoped_cbd);
 }
+#else
+/* Non hyperscan version stub */
+int rspamd_re_cache_compile_hyperscan_scoped_single(struct rspamd_re_cache *cache,
+													const char *scope,
+													const char *cache_dir,
+													double max_time,
+													gboolean silent,
+													struct ev_loop *event_loop,
+													void (*cb)(const char *scope, unsigned int ncompiled, GError *err, void *cbd),
+													void *cbd)
+{
+	return 0;
+}
 #endif
-- 
2.51.0

