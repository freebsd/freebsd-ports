--- Telegram/SourceFiles/storage/storage_encrypted_file_tests.cpp.orig	2018-09-28 13:08:38 UTC
+++ Telegram/SourceFiles/storage/storage_encrypted_file_tests.cpp
@@ -21,7 +21,7 @@ https://github.com/telegramdesktop/tdesk
 #include <thread>
 #ifdef Q_OS_MAC
 #include <mach-o/dyld.h>
-#elif defined Q_OS_LINUX // Q_OS_MAC
+#elif defined Q_OS_LINUX || defined Q_OS_FREEBSD // Q_OS_MAC
 #include <unistd.h>
 #endif // Q_OS_MAC || Q_OS_LINUX
 
