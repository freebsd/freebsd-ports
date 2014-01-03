--- ./libefont/t1interp.cc.orig	2013-08-13 20:18:57.000000000 +0000
+++ ./libefont/t1interp.cc	2014-01-03 11:42:48.000000000 +0000
@@ -30,6 +30,7 @@
 #define CHECK_PATH_START()	do { _state = S_PATH; } while (0)
 #define CHECK_PATH_END()	do { if (_state == S_PATH) { act_closepath(cmd); } _state = S_IPATH; } while (0)
 
+#undef static_assert
 #ifndef static_assert
 # define static_assert(c)	switch (c) case 0: case (c):
 #endif
