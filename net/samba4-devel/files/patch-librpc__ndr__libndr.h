--- ./librpc/ndr/libndr.h.orig	2009-06-19 04:36:48.000000000 +0000
+++ ./librpc/ndr/libndr.h	2009-07-12 03:24:17.000000000 +0000
@@ -419,7 +419,7 @@
 			 struct ndr_token_list **list, 
 			 const void *key, 
 			 uint32_t value);
-enum ndr_err_code ndr_token_retrieve_cmp_fn(struct ndr_token_list **list, const void *key, uint32_t *v, comparison_fn_t _cmp_fn, bool _remove_tok);
+enum ndr_err_code ndr_token_retrieve_cmp_fn(struct ndr_token_list **list, const void *key, uint32_t *v, int (*_cmp_fn)(const void *, const void *), bool _remove_tok);
 enum ndr_err_code ndr_token_retrieve(struct ndr_token_list **list, const void *key, uint32_t *v);
 uint32_t ndr_token_peek(struct ndr_token_list **list, const void *key);
 enum ndr_err_code ndr_pull_array_size(struct ndr_pull *ndr, const void *p);
