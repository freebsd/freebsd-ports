--- src/s4u/s4u_Mess.cpp.orig	2026-09-07 22:52:22 UTC
+++ src/s4u/s4u_Mess.cpp
@@ -10,6 +10,8 @@
 #include <simgrid/s4u/Engine.hpp>
 #include <simgrid/s4u/MessageQueue.hpp>
 
+#include <boost/core/demangle.hpp>
+
 #include "src/kernel/activity/MessImpl.hpp"
 #include "src/kernel/actor/ActorImpl.hpp"
 #include "src/kernel/actor/SimcallObserver.hpp"
