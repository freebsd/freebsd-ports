--- src/s4u/s4u_Comm.cpp.orig	2026-09-07 22:51:10 UTC
+++ src/s4u/s4u_Comm.cpp
@@ -11,6 +11,8 @@
 #include <simgrid/s4u/Engine.hpp>
 #include <simgrid/s4u/Mailbox.hpp>
 
+#include <boost/core/demangle.hpp>
+
 #include "src/kernel/activity/CommImpl.hpp"
 #include "src/kernel/actor/ActorImpl.hpp"
 #include "src/kernel/actor/SimcallObserver.hpp"
