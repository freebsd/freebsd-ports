Fix build on 9.3

/wrkdirs/usr/ports/textproc/kf5-syntax-highlighting/work/syntax-highlighting-5.29.0/src/cli/kate-syntax-highlighter.cpp:121:35: error: 'stdout' was not declared in this scope

--- src/cli/kate-syntax-highlighter.cpp.orig	2016-12-13 11:57:30 UTC
+++ src/cli/kate-syntax-highlighter.cpp
@@ -28,6 +28,7 @@
 #include <QVector>
 
 #include <iostream>
+#include <cstdio>
 
 using namespace KSyntaxHighlighting;
 
