--- src/rpsl/gnu/std.h.orig	2002-03-27 12:33:00.000000000 +0100
+++ src/rpsl/gnu/std.h
@@ -19,7 +19,7 @@ Foundation, 59 Temple Place - Suite 330,
 #ifndef _std_h
 #define _std_h 1
 
-#include <_G_config.h>
+#include <config.h>
 #include <cstddef>
 #include <cstdlib>
 #include <cstring>
@@ -28,8 +28,10 @@ Foundation, 59 Temple Place - Suite 330,
 #include <cerrno>
 #include <fcntl.h>
 
+#ifndef HAVE_STRINGS_H
 extern "C" {
-int strcasecmp _G_ARGS((const char*, const char*));
+int strcasecmp __P((const char*, const char*));
 }
+#endif // HAVE_STRINGS_H
 
 #endif 
