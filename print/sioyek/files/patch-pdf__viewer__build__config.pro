--- pdf_viewer_build_config.pro.orig	2022-12-16 16:06:01 UTC
+++ pdf_viewer_build_config.pro
@@ -28,8 +28,6 @@ HEADERS += pdf_viewer/book.h \
            pdf_viewer/checksum.h \
            pdf_viewer/new_file_checker.h \
            pdf_viewer/coordinates.h \
-           pdf_viewer/sqlite3.h \
-           pdf_viewer/sqlite3ext.h \
            pdf_viewer/ui.h \
            pdf_viewer/path.h \
            pdf_viewer/utf8.h \
@@ -55,7 +53,6 @@ SOURCES += pdf_viewer/book.cpp \
            pdf_viewer/checksum.cpp \
            pdf_viewer/new_file_checker.cpp \
            pdf_viewer/coordinates.cpp \
-           pdf_viewer/sqlite3.c \
            pdf_viewer/ui.cpp \
            pdf_viewer/path.cpp \
            pdf_viewer/utils.cpp \
@@ -82,7 +79,7 @@ unix:!mac {
     } else {
         DEFINES += NON_PORTABLE
         DEFINES += LINUX_STANDARD_PATHS
-        LIBS += -ldl -lmupdf -lmupdf-third -lgumbo -lharfbuzz -lfreetype -ljbig2dec -ljpeg -lmujs -lopenjp2 -lz
+        LIBS += -ldl -lmupdf -lmupdf-third -lharfbuzz -lfreetype -ljbig2dec -ljpeg -lmujs -lopenjp2 -lz -lsqlite3
     }
 
     isEmpty(PREFIX){
