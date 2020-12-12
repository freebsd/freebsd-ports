--- src/providers/ad/ad_gpo_ndr.c-orig	2020-11-28 22:21:39.860006000 +0000
+++ src/providers/ad/ad_gpo_ndr.c	2020-11-28 22:23:15.849602000 +0000
@@ -105,7 +105,7 @@
                                   union security_ace_object_type *r)
 {
     uint32_t level;
-    level = ndr_pull_get_switch_value(ndr, r);
+    level = ndr_token_peek(&ndr->switch_list, r);
     NDR_PULL_CHECK_FLAGS(ndr, ndr_flags);
     if (ndr_flags & NDR_SCALARS) {
         NDR_CHECK(ndr_pull_union_align(ndr, 4));
@@ -135,7 +135,7 @@
                                             union security_ace_object_inherited_type *r)
 {
     uint32_t level;
-    level = ndr_pull_get_switch_value(ndr, r);
+    level = ndr_token_peek(&ndr->switch_list, r);
     NDR_PULL_CHECK_FLAGS(ndr, ndr_flags);
     if (ndr_flags & NDR_SCALARS) {
         NDR_CHECK(ndr_pull_union_align(ndr, 4));
@@ -198,7 +198,7 @@
                                  union security_ace_object_ctr *r)
 {
     uint32_t level;
-    level = ndr_pull_get_switch_value(ndr, r);
+    level = ndr_token_peek(&ndr->switch_list, r);
     NDR_PULL_CHECK_FLAGS(ndr, ndr_flags);
     if (ndr_flags & NDR_SCALARS) {
         NDR_CHECK(ndr_pull_union_align(ndr, 4));
