--- zart.pro.orig	2021-01-30 17:27:07 UTC
+++ zart.pro
@@ -29,7 +29,7 @@ greaterThan(QT_MAJOR_VERSION, 4): CONFIG += c++11
 CONFIG	+= warn_on
 QT_CONFIG -= no-pkg-config
 CONFIG += link_pkgconfig
-PKGCONFIG += opencv fftw3 zlib
+PKGCONFIG += opencv4 fftw3 zlib
 DEFINES += cimg_use_fftw3 cimg_use_zlib
 
 DEFINES += QT_DEPRECATED_WARNINGS
