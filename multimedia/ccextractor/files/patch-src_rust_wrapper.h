--- src/rust/wrapper.h.orig	2026-01-20 14:53:33 UTC
+++ src/rust/wrapper.h
@@ -14,3 +14,7 @@
 #include "../lib_ccx/ccx_gxf.h"
 #include "../lib_ccx/ccx_demuxer_mxf.h"
 #include "../lib_ccx/cc_bitstream.h"
+#ifdef iconv_t
+#undef iconv_t
+typedef libiconv_t iconv_t;
+#endif
