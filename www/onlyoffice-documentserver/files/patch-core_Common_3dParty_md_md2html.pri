--- core/Common/3dParty/md/md2html.pri.orig	2025-10-13 15:33:25 UTC
+++ core/Common/3dParty/md/md2html.pri
@@ -1,11 +1,7 @@
 DEFINES += MD4C_USE_UTF8
 
-HEADERS += $$PWD/md4c/src/md4c.h \
-           $$PWD/md4c/src/md4c-html.h \
-           $$PWD/md4c/src/entity.h \
-           $$PWD/md2html.h \
+HEADERS += $$PWD/md2html.h
+SOURCES += $$PWD/md2html.cpp
 
-SOURCES += $$PWD/md4c/src/md4c.c \
-           $$PWD/md4c/src/md4c-html.c \
-           $$PWD/md4c/src/entity.c \
-           $$PWD/md2html.cpp
+INCLUDEPATH += /usr/local/include
+LIBS        += -L%%LOCALBASE%%/lib -lmd4c -lmd4c-html
