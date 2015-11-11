--- aux/broker/src/store/frontend_impl.hh.orig	2015-09-06 19:43:53 UTC
+++ aux/broker/src/store/frontend_impl.hh
@@ -3,13 +3,12 @@
 
 #include "broker/store/frontend.hh"
 #include <caf/actor.hpp>
-#include <caf/sb_actor.hpp>
+#include <caf/event_based_actor.hpp>
 #include <caf/scoped_actor.hpp>
 
 namespace broker { namespace store {
 
-class requester : public caf::sb_actor<requester> {
-friend class caf::sb_actor<requester>;
+class requester : public caf::event_based_actor {
 
 public:
 
@@ -46,9 +45,13 @@ public:
 
 private:
 
+	caf::behavior make_behavior() override
+		{
+		return bootstrap;
+		}
+
 	caf::behavior bootstrap;
 	caf::behavior awaiting_response;
-	caf::behavior& init_state = bootstrap;
 	query request;
 };
 
