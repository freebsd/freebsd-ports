--- pdf_viewer_build_config.pro.orig	2025-05-13 14:36:40 UTC
+++ pdf_viewer_build_config.pro
@@ -92,8 +92,6 @@ HEADERS += pdf_viewer/book.h \
            pdf_viewer/checksum.h \
            pdf_viewer/new_file_checker.h \
            pdf_viewer/coordinates.h \
-           pdf_viewer/sqlite3.h \
-           pdf_viewer/sqlite3ext.h \
            pdf_viewer/ui.h \
            pdf_viewer/path.h \
            pdf_viewer/utf8.h \
@@ -120,7 +118,6 @@ SOURCES += pdf_viewer/book.cpp \
            pdf_viewer/checksum.cpp \
            pdf_viewer/new_file_checker.cpp \
            pdf_viewer/coordinates.cpp \
-           pdf_viewer/sqlite3.c \
            pdf_viewer/ui.cpp \
            pdf_viewer/path.cpp \
            pdf_viewer/utils.cpp \
@@ -129,15 +126,6 @@ SOURCES += pdf_viewer/book.cpp \
            pdf_viewer/OpenWithApplication.cpp \
            fzf/fzf.c
 
-!android{
-           HEADERS += pdf_viewer/synctex/synctex_parser.h \
-           pdf_viewer/synctex/synctex_parser_utils.h
-           
-           SOURCES += pdf_viewer/synctex/synctex_parser.c \
-           pdf_viewer/synctex/synctex_parser_utils.c
-}
-
-
 win32{
 
     CONFIG(Debug){
@@ -179,7 +167,7 @@ unix:!mac:!android {
     } else {
         DEFINES += NON_PORTABLE
         DEFINES += LINUX_STANDARD_PATHS
-        LIBS += -ldl -lmupdf -lmupdf-third -lgumbo -lharfbuzz -lfreetype -ljbig2dec -ljpeg -lmujs -lopenjp2 -lz
+        LIBS += -ldl -lmupdf -lharfbuzz -lfreetype -ljbig2dec -ljpeg -lmujs -lopenjp2 -lz -lsqlite3 -lsynctex
     }
 
     isEmpty(PREFIX){
