--- src/sessionLock/WaylandSessionLock.cpp.orig	2025-12-01 05:05:45 UTC
+++ src/sessionLock/WaylandSessionLock.cpp
@@ -3,6 +3,8 @@
 #include "../core/platforms/WaylandPlatform.hpp"
 #include "../window/WaylandLockSurface.hpp"
 
+#include <algorithm>
+
 using namespace Hyprtoolkit;
 
 CWaylandSessionLockState::CWaylandSessionLockState(SP<CCExtSessionLockV1> lock) : m_lock(lock) {
