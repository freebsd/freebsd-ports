--- src/ucp/core/ucp_ep.c.orig	2026-07-01 23:04:16 UTC
+++ src/ucp/core/ucp_ep.c
@@ -3181,11 +3181,25 @@ void ucp_ep_config_lane_info_str(ucp_worker_h worker,
     }
 
     dst_md_index = key->lanes[lane].dst_md_index;
+#ifdef __FreeBSD__
+    if (key->dst_md_cmpts != NULL) {
+        cmpt_index = ucp_ep_config_get_dst_md_cmpt(key, dst_md_index);
+        ucs_string_buffer_appendf(
+             strbuf, "md[%d]/%s/sysdev[%d] seg %zu", dst_md_index,
+             context->tl_cmpts[cmpt_index].attr.name,
+             key->lanes[lane].dst_sys_dev, key->lanes[lane].seg_size);
+    } else {
+        ucs_string_buffer_appendf(
+             strbuf, "md[%d]/sysdev[%d] seg %zu", dst_md_index,
+             key->lanes[lane].dst_sys_dev, key->lanes[lane].seg_size);
+    }
+#else
     cmpt_index   = ucp_ep_config_get_dst_md_cmpt(key, dst_md_index);
     ucs_string_buffer_appendf(
          strbuf, "md[%d]/%s/sysdev[%d] seg %zu", dst_md_index,
          context->tl_cmpts[cmpt_index].attr.name, key->lanes[lane].dst_sys_dev,
          key->lanes[lane].seg_size);
+#endif
 
     prio = ucp_ep_config_get_multi_lane_prio(key->rma_bw_lanes, lane);
     if (prio != -1) {
