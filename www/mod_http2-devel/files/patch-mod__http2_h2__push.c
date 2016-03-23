Upstream fix for i386 build
https://github.com/icing/mod_h2/pull/89

--- mod_http2/h2_push.c.orig	2016-02-29 13:59:13 UTC
+++ mod_http2/h2_push.c
@@ -792,7 +792,7 @@ static apr_status_t gset_encode_next(gse
     flex_bits = (delta >> encoder->fixed_bits);
     ap_log_perror(APLOG_MARK, GCSLOG_LEVEL, 0, encoder->pool,
                   "h2_push_diary_enc: val=%"APR_UINT64_T_HEX_FMT", delta=%"
-                  APR_UINT64_T_HEX_FMT" flex_bits=%ld, "
+                  APR_UINT64_T_HEX_FMT" flex_bits=%"APR_UINT64_T_FMT", "
                   "fixed_bits=%d, fixed_val=%"APR_UINT64_T_HEX_FMT, 
                   pval, delta, flex_bits, encoder->fixed_bits, delta&encoder->fixed_mask);
     for (; flex_bits != 0; --flex_bits) {
