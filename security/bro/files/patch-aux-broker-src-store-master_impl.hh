--- aux/broker/src/store/master_impl.hh.orig	2015-09-06 19:43:53 UTC
+++ aux/broker/src/store/master_impl.hh
@@ -9,7 +9,7 @@
 #include <caf/send.hpp>
 #include <caf/spawn.hpp>
 #include <caf/actor.hpp>
-#include <caf/sb_actor.hpp>
+#include <caf/event_based_actor.hpp>
 #include <caf/scoped_actor.hpp>
 #include <unordered_map>
 
@@ -18,8 +18,7 @@ namespace broker { namespace store {
 static inline double now()
 	{ return broker::time_point::now().value; }
 
-class master_actor : public caf::sb_actor<master_actor> {
-friend class caf::sb_actor<master_actor>;
+class master_actor : public caf::event_based_actor {
 
 public:
 
@@ -282,6 +281,11 @@ public:
 
 private:
 
+	caf::behavior make_behavior() override
+		{
+		return init_existing_expiry_reminders;
+		}
+
 	void expiry_reminder(const identifier& name, data key,
 	                     expiration_time expiry)
 		{
@@ -324,7 +328,6 @@ private:
 	std::unordered_map<caf::actor_addr, caf::actor> clones;
 	caf::behavior serving;
 	caf::behavior init_existing_expiry_reminders;
-	caf::behavior& init_state = init_existing_expiry_reminders;
 };
 
 class master::impl {
