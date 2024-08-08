diff --git gfx/skia/skia/src/core/SkRasterPipeline.h gfx/skia/skia/src/core/SkRasterPipeline.h
index 2475ea0d398d..67967483656d 100644
--- gfx/skia/skia/src/core/SkRasterPipeline.h
+++ gfx/skia/skia/src/core/SkRasterPipeline.h
@@ -27,7 +27,7 @@ struct SkImageInfo;
 struct skcms_TransferFunction;
 
 #if __has_cpp_attribute(clang::musttail) && !defined(__EMSCRIPTEN__) && !defined(SK_CPU_ARM32) && \
-        !defined(SK_CPU_LOONGARCH)
+        !defined(SK_CPU_LOONGARCH) && !defined(__powerpc__)
     #define SK_HAS_MUSTTAIL 1
 #else
     #define SK_HAS_MUSTTAIL 0
