--- src/providers/ad/ad_gpo_ndr.c.orig	2020-03-17 13:31:28 UTC
+++ src/providers/ad/ad_gpo_ndr.c
@@ -105,7 +105,7 @@ ndr_pull_security_ace_object_type(struct ndr_pull *ndr
                                   union security_ace_object_type *r)
 {
     uint32_t level;
-    level = ndr_pull_get_switch_value(ndr, r);
+    level = ndr_token_peek(&ndr->switch_list, r);
     NDR_PULL_CHECK_FLAGS(ndr, ndr_flags);
     if (ndr_flags & NDR_SCALARS) {
         NDR_CHECK(ndr_pull_union_align(ndr, 4));
@@ -135,7 +135,7 @@ ndr_pull_security_ace_object_inherited_type(struct ndr
                                             union security_ace_object_inherited_type *r)
 {
     uint32_t level;
-    level = ndr_pull_get_switch_value(ndr, r);
+    level = ndr_token_peek(&ndr->switch_list, r);
     NDR_PULL_CHECK_FLAGS(ndr, ndr_flags);
     if (ndr_flags & NDR_SCALARS) {
         NDR_CHECK(ndr_pull_union_align(ndr, 4));
@@ -198,7 +198,7 @@ ndr_pull_security_ace_object_ctr(struct ndr_pull *ndr,
                                  union security_ace_object_ctr *r)
 {
     uint32_t level;
-    level = ndr_pull_get_switch_value(ndr, r);
+    level = ndr_token_peek(&ndr->switch_list, r);
     NDR_PULL_CHECK_FLAGS(ndr, ndr_flags);
     if (ndr_flags & NDR_SCALARS) {
         NDR_CHECK(ndr_pull_union_align(ndr, 4));
