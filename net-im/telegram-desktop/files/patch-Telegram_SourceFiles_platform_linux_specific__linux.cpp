--- Telegram/SourceFiles/platform/linux/specific_linux.cpp.orig	2021-07-17 09:47:10 UTC
+++ Telegram/SourceFiles/platform/linux/specific_linux.cpp
@@ -48,7 +48,7 @@ https://github.com/telegramdesktop/tdesktop/blob/maste
 #include <gio/gio.h>
 #include <glibmm.h>
 #include <giomm.h>
-#include <jemalloc/jemalloc.h>
+#include <malloc_np.h>
 
 #include <sys/stat.h>
 #include <sys/types.h>
