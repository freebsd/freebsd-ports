Regressed by https://chromium.googlesource.com/webm/libvpx/+/763f8318de2c%5E!/

gstvpxdec.c:65:15: error: use of undeclared identifier 'VP8_DEBUG_TXT_FRAME_INFO'
    {C_FLAGS (VP8_DEBUG_TXT_FRAME_INFO),
              ^
gstvpxdec.c:68:15: error: use of undeclared identifier 'VP8_DEBUG_TXT_MBLK_MODES'
    {C_FLAGS (VP8_DEBUG_TXT_MBLK_MODES),
              ^
gstvpxdec.c:71:15: error: use of undeclared identifier 'VP8_DEBUG_TXT_DC_DIFF'
    {C_FLAGS (VP8_DEBUG_TXT_DC_DIFF),
              ^
gstvpxdec.c:74:15: error: use of undeclared identifier 'VP8_DEBUG_TXT_RATE_INFO'
    {C_FLAGS (VP8_DEBUG_TXT_RATE_INFO),
              ^

--- ext/vpx/gstvpxdec.c.orig	2018-03-23 20:44:48 UTC
+++ ext/vpx/gstvpxdec.c
@@ -62,18 +62,6 @@ gst_vpx_dec_post_processing_flags_get_type (void)
     {C_FLAGS (VP8_DEBLOCK), "Deblock", "deblock"},
     {C_FLAGS (VP8_DEMACROBLOCK), "Demacroblock", "demacroblock"},
     {C_FLAGS (VP8_ADDNOISE), "Add noise", "addnoise"},
-    {C_FLAGS (VP8_DEBUG_TXT_FRAME_INFO),
-          "Print frame information",
-        "visualize-frame-info"},
-    {C_FLAGS (VP8_DEBUG_TXT_MBLK_MODES),
-          "Show macroblock mode selection overlaid on image",
-        "visualize-macroblock-modes"},
-    {C_FLAGS (VP8_DEBUG_TXT_DC_DIFF),
-          "Show dc diff for each macro block overlaid on image",
-        "visualize-dc-diff"},
-    {C_FLAGS (VP8_DEBUG_TXT_RATE_INFO),
-          "Print video rate info",
-        "visualize-rate-info"},
     {C_FLAGS (VP8_MFQE), "Multi-frame quality enhancement", "mfqe"},
     {0, NULL, NULL}
   };
