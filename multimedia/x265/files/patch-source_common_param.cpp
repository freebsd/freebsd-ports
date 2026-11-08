Tolerate a NULL argument, as free(3) does.  With SVT-HEVC enabled the
function dereferences p->svtHevcParam, so every CLI error exit crashed:
CLIOptions::destroy() already frees the param and sets it to NULL, and
main() then calls param_free() on it again.

--- source/common/param.cpp	2026-07-31 07:16:44.000000000 -0400
+++ source/common/param.cpp	2026-10-05 23:03:50.000000000 -0400
@@ -104,4 +104,6 @@
 void x265_param_free(x265_param* p)
 {
+    if (!p)
+        return;
     x265_zone_free(p);
 #ifdef SVT_HEVC
