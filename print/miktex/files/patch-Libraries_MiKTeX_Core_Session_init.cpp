--- Libraries/MiKTeX/Core/Session/init.cpp.orig	2021-02-20 10:38:14 UTC
+++ Libraries/MiKTeX/Core/Session/init.cpp
@@ -23,6 +23,7 @@
 
 #if defined(MIKTEX_UNIX)
 #  include <unistd.h>
+extern char** environ;
 #endif
 
 #if defined(MIKTEX_MACOS_BUNDLE)
