--- ./libefont/otf.cc.orig	2013-08-13 20:23:45.000000000 +0000
+++ ./libefont/otf.cc	2014-01-03 11:41:56.000000000 +0000
@@ -26,6 +26,7 @@
 #include <efont/otfdata.hh>	// for ntohl()
 #include <efont/otfname.hh>
 
+#undef static_assert
 #ifndef static_assert
 #define static_assert(c) switch (c) case 0: case (c):
 #endif
