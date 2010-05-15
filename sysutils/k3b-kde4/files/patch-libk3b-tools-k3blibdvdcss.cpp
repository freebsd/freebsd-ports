--- libk3b/tools/k3blibdvdcss.cpp.orig	2010-02-08 18:49:23.016438402 +0000
+++ libk3b/tools/k3blibdvdcss.cpp	2010-02-08 18:49:35.965396300 +0000
@@ -283,7 +283,7 @@
 K3bLibDvdCss* K3bLibDvdCss::create()
 {
   if( s_libDvdCss == 0 ) {
-    s_libDvdCss = dlopen( "libdvdcss.so.2", RTLD_LAZY|RTLD_GLOBAL );
+    s_libDvdCss = dlopen( "libdvdcss.so", RTLD_LAZY|RTLD_GLOBAL );
     if( s_libDvdCss ) {
       k3b_dvdcss_open = (dvdcss_t (*)(char*))dlsym( s_libDvdCss, "dvdcss_open" );
       k3b_dvdcss_close = (int (*)( dvdcss_t ))dlsym( s_libDvdCss, "dvdcss_close" );
