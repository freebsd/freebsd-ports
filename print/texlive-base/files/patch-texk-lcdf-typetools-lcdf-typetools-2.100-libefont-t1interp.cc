--- texk/lcdf-typetools/lcdf-typetools-2.100/libefont/t1interp.cc.orig	2014-01-09 21:51:50.000000000 +0900
+++ texk/lcdf-typetools/lcdf-typetools-2.100/libefont/t1interp.cc	2014-08-20 23:34:37.000000000 +0900
@@ -30,6 +30,7 @@
 #define CHECK_PATH_START()	do { _state = S_PATH; } while (0)
 #define CHECK_PATH_END()	do { if (_state == S_PATH) { act_closepath(cmd); } _state = S_IPATH; } while (0)
 
+#undef static_assert
 #ifndef static_assert
 # define static_assert(c, msg)	switch (c) case 0: case (c):
 #endif
