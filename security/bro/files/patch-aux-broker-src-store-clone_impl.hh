--- aux/broker/src/store/clone_impl.hh.orig	2015-09-06 19:43:53 UTC
+++ aux/broker/src/store/clone_impl.hh
@@ -10,13 +10,12 @@
 #include <caf/spawn.hpp>
 #include <caf/send.hpp>
 #include <caf/actor.hpp>
-#include <caf/sb_actor.hpp>
+#include <caf/event_based_actor.hpp>
 #include <caf/scoped_actor.hpp>
 
 namespace broker { namespace store {
 
-class clone_actor : public caf::sb_actor<clone_actor> {
-friend class caf::sb_actor<clone_actor>;
+class clone_actor : public caf::event_based_actor {
 
 public:
 
@@ -320,6 +319,11 @@ public:
 
 private:
 
+	caf::behavior make_behavior() override
+		{
+		return bootstrap;
+		}
+
 	void error(std::string master_name, std::string method_name,
 	           std::string err_msg, bool fatal = false)
 		{
@@ -359,7 +363,6 @@ private:
 	caf::behavior synchronizing;
 	caf::behavior active;
 	caf::behavior dead;
-	caf::behavior& init_state = bootstrap;
 };
 
 
