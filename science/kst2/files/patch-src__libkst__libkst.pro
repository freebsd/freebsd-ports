--- ./src/libkst/libkst.pro.orig	2010-04-27 16:37:12.000000000 +0400
+++ ./src/libkst/libkst.pro	2010-05-20 01:18:58.740810983 +0400
@@ -61,8 +61,8 @@
     vscalar.cpp
 	
 #!win32:SOURCES += stdinsource.cpp
-!macx:!win32:SOURCES += sysinfo.c \
-    psversion.c
+# !macx:!win32:SOURCES += sysinfo.c \
+#     psversion.c
 	
 HEADERS += builtindatasources.h \
     builtinprimitives.h \
