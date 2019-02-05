--- Telegram/SourceFiles/storage/storage_encrypted_file_tests.cpp.orig	2019-02-01 12:51:46 UTC
+++ Telegram/SourceFiles/storage/storage_encrypted_file_tests.cpp
@@ -21,7 +21,7 @@ https://github.com/telegramdesktop/tdesktop/blob/maste
 #include <thread>
 #ifdef Q_OS_MAC
 #include <mach-o/dyld.h>
-#elif defined Q_OS_LINUX // Q_OS_MAC
+#elif defined Q_OS_LINUX || defined Q_OS_FREEBSD // Q_OS_MAC
 #include <unistd.h>
 #endif // Q_OS_MAC || Q_OS_LINUX
 
