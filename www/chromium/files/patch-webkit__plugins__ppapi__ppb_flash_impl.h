--- webkit/plugins/ppapi/ppb_flash_impl.h.orig	2011-03-15 06:28:40.000000000 +0200
+++ webkit/plugins/ppapi/ppb_flash_impl.h	2011-03-15 06:28:59.000000000 +0200
@@ -33,7 +33,7 @@
                             uint32_t glyph_count,
                             const uint16_t glyph_indices[],
                             const PP_Point glyph_advances[])
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_FREEBSD)
       ;
 #else
       { return PP_FALSE; }
