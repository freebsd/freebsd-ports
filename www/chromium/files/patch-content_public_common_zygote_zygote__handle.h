--- content/public/common/zygote/zygote_handle.h.orig	2026-10-18 13:29:39 UTC
+++ content/public/common/zygote/zygote_handle.h
@@ -11,7 +11,7 @@
 #include "content/common/content_export.h"
 #include "content/public/common/zygote/zygote_buildflags.h"
 
-#if !BUILDFLAG(USE_ZYGOTE)
+#if !BUILDFLAG(USE_ZYGOTE) && !BUILDFLAG(IS_BSD)
 #error "Can not use zygote without USE_ZYGOTE"
 #endif
 
