https://github.com/Netflix/vmaf/commit/122089fa3d23

--- source/x265.h.orig	2023-06-27 14:11:49 UTC
+++ source/x265.h
@@ -753,7 +753,7 @@ typedef struct x265_vmaf_commondata
     int enable_conf_interval;
 }x265_vmaf_commondata;
 
-static const x265_vmaf_commondata vcd[] = { { NULL, (char *)"/usr/local/share/model/vmaf_v0.6.1.pkl", NULL, NULL, 0, 0, 0, 0, 0, 0, 0, NULL, 0, 1, 0 } };
+static const x265_vmaf_commondata vcd[] = { { NULL, (char *)"/usr/local/share/model/vmaf_v0.6.1.json", NULL, NULL, 0, 0, 0, 0, 0, 0, 0, NULL, 0, 1, 0 } };
 
 typedef struct x265_temporal_layer {
     int poc_offset;      /* POC offset */
