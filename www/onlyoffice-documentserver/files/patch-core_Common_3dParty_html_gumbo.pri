--- core/Common/3dParty/html/gumbo.pri.orig	2025-10-13 15:33:25 UTC
+++ core/Common/3dParty/html/gumbo.pri
@@ -1,10 +1,11 @@
 INCLUDEPATH += $$PWD
 DEPENDPATH += $$PWD
 
+core_freebsd:QMAKE_CFLAGS += -std=c99
 core_linux:QMAKE_CFLAGS += -std=c99
 core_windows:INCLUDEPATH += $$PWD/gumbo-parser/visualc/include
 
-HEADERS += $$files($$PWD/gumbo-parser/src/*.h, true) \
-           $$PWD/htmltoxhtml.h
+HEADERS += $$PWD/htmltoxhtml.h
 
-SOURCES += $$files($$PWD/gumbo-parser/src/*.c, true)
+INCLUDEPATH += %%LOCALBASE%%/include
+LIBS        += -L%%LOCALBASE%%/lib -lgumbo
