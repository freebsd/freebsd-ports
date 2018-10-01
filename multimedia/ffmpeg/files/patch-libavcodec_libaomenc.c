https://git.ffmpeg.org/gitweb/ffmpeg.git/commitdiff/b69ea742ab23

--- libavcodec/libaomenc.c.orig	2018-07-18 13:52:00 UTC
+++ libavcodec/libaomenc.c
@@ -697,10 +697,6 @@ static const AVOption options[] = {
                          "alternate reference frame selection",    OFFSET(lag_in_frames),   AV_OPT_TYPE_INT, {.i64 = -1},      -1,      INT_MAX, VE},
     { "error-resilience", "Error resilience configuration", OFFSET(error_resilient), AV_OPT_TYPE_FLAGS, {.i64 = 0}, INT_MIN, INT_MAX, VE, "er"},
     { "default",         "Improve resiliency against losses of whole frames", 0, AV_OPT_TYPE_CONST, {.i64 = AOM_ERROR_RESILIENT_DEFAULT}, 0, 0, VE, "er"},
-    { "partitions",      "The frame partitions are independently decodable "
-                         "by the bool decoder, meaning that partitions can be decoded even "
-                         "though earlier partitions have been lost. Note that intra predicition"
-                         " is still done over the partition boundary.",       0, AV_OPT_TYPE_CONST, {.i64 = AOM_ERROR_RESILIENT_PARTITIONS}, 0, 0, VE, "er"},
     { "crf",              "Select the quality for constant quality mode", offsetof(AOMContext, crf), AV_OPT_TYPE_INT, {.i64 = -1}, -1, 63, VE },
     { "static-thresh",    "A change threshold on blocks below which they will be skipped by the encoder", OFFSET(static_thresh), AV_OPT_TYPE_INT, { .i64 = 0 }, 0, INT_MAX, VE },
     { "drop-threshold",   "Frame drop threshold", offsetof(AOMContext, drop_threshold), AV_OPT_TYPE_INT, {.i64 = 0 }, INT_MIN, INT_MAX, VE },
