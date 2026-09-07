--- src/kernel/actor/Simcall.cpp.orig	2026-09-07 22:55:16 UTC
+++ src/kernel/actor/Simcall.cpp
@@ -13,6 +13,9 @@
 #include "src/mc/mc_replay.hpp"
 #include "xbt/log.h"
 
+#include <boost/core/demangle.hpp>
+
+
 XBT_LOG_NEW_DEFAULT_SUBCATEGORY(ker_simcall, kernel, "transmuting from user request into kernel handlers");
 
 namespace simgrid::kernel::actor {
