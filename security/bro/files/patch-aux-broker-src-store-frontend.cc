--- aux/broker/src/store/frontend.cc.orig	2015-09-06 19:43:53 UTC
+++ aux/broker/src/store/frontend.cc
@@ -1,7 +1,6 @@
 #include "frontend_impl.hh"
 #include "../atoms.hh"
 #include <caf/send.hpp>
-#include <caf/sb_actor.hpp>
 #include <caf/spawn.hpp>
 
 static inline caf::actor& handle_to_actor(void* h)
