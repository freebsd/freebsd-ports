--- engine/Engine.cpp.orig	2018-03-28 11:56:15 UTC
+++ engine/Engine.cpp
@@ -50,7 +50,8 @@ __declspec(dllimport) BOOL WINAPI SHGetS
 #include <sys/wait.h>
 #include <sys/resource.h>
 typedef void* HMODULE;
-#define sig_func_t sighandler_t
+//#define sig_func_t sighandler_t
+#define sig_func_t sig_t
 #define PATH_SEP "/"
 #ifndef CFG_DIR
 #ifdef HAVE_MACOSX_SUPPORT
