--- texk/lcdf-typetools/lcdf-typetools-src/libefont/t1interp.cc.orig	2022-01-29 16:26:32 UTC
+++ texk/lcdf-typetools/lcdf-typetools-src/libefont/t1interp.cc
@@ -30,6 +30,7 @@
 #define CHECK_PATH_START()      do { _state = S_PATH; } while (0)
 #define CHECK_PATH_END()        do { if (_state == S_PATH) { act_closepath(cmd); } _state = S_IPATH; } while (0)
 
+#undef static_assert
 #ifndef static_assert
 # define static_assert(c, msg)  switch ((int) (c)) case 0: case (c):
 #endif
