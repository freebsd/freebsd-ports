--- src/zyGrib.pro.orig	2018-07-14 08:35:01 UTC
+++ src/zyGrib.pro
@@ -8,7 +8,7 @@ TEMPLATE = app
 TARGET   = zyGrib
 
 DEPENDPATH  += . util map GUI
-INCLUDEPATH += . util map GUI curvedrawer qwt-6.1.3/src g2clib
+INCLUDEPATH += . util map GUI curvedrawer $$(PREFIX)/include/qt5/qwt6 g2clib
 
 # ----------------------------------------------------
 # platform specific
@@ -35,7 +35,7 @@ else {
 }
 }
 
-LIBS += -lbz2 -lz -lproj -lnova -Lqwt-6.1.3/lib/ -lqwt
+LIBS += -lbz2 -lz -lproj -lnova -L$$(PREFIX)/lib/qt5/libqwt -lqwt6
 LIBS +=  -Lg2clib -lg2c -lpng -ljasper  # respect order!
 
 # ----------------------------------------------------
