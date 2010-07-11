--- ./modules/gui/qt4/util/customwidgets.cpp.orig	2010-06-22 02:57:13.000000000 -0400
+++ ./modules/gui/qt4/util/customwidgets.cpp	2010-06-22 02:57:45.000000000 -0400
@@ -380,7 +380,7 @@
 
     if( qtk <= 0xff )
         /* VLC and X11 use lowercase whereas Qt uses uppercase */
-#if defined( __STDC_ISO_10646__ ) || defined( _WIN32 )
+#if defined( __STDC_ISO_10646__ ) || defined( _WIN32 ) || defined(__FreeBSD__)
         i_vlck = towlower( qtk );
 #else
 # error FIXME
