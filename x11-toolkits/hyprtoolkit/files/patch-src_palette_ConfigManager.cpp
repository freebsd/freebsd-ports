--- src/palette/ConfigManager.cpp.orig	2025-11-12 08:27:37 UTC
+++ src/palette/ConfigManager.cpp
@@ -4,6 +4,8 @@
 
 #include "../core/InternalBackend.hpp"
 
+#include <unistd.h>
+
 using namespace Hyprtoolkit;
 
 CConfigManager::CConfigManager() : m_inotifyFd(inotify_init()) {
