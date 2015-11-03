--- aux/broker/src/endpoint_impl.hh.orig	2015-09-06 19:43:53 UTC
+++ aux/broker/src/endpoint_impl.hh
@@ -12,7 +12,7 @@
 #include <caf/actor.hpp>
 #include <caf/spawn.hpp>
 #include <caf/send.hpp>
-#include <caf/sb_actor.hpp>
+#include <caf/event_based_actor.hpp>
 #include <caf/scoped_actor.hpp>
 #include <caf/io/remote_actor.hpp>
 #include <unordered_set>
@@ -62,8 +62,7 @@ static void ics_update(const caf::actor&
                        incoming_connection_status::tag t)
 	{ caf::anon_send(q, incoming_connection_status{t, std::move(name)}); }
 
-class endpoint_actor : public caf::sb_actor<endpoint_actor> {
-friend class caf::sb_actor<endpoint_actor>;
+class endpoint_actor : public caf::event_based_actor {
 
 public:
 
@@ -351,6 +350,11 @@ public:
 
 private:
 
+	caf::behavior make_behavior() override
+		{
+		return active;
+		}
+
 	std::string get_peer_name(const caf::actor_addr& a) const
 		{
 		auto it = peers.find(a);
@@ -473,7 +477,6 @@ private:
 	};
 
 	caf::behavior active;
-	caf::behavior& init_state = active;
 
 	std::string name;
 	int behavior_flags;
@@ -490,8 +493,7 @@ private:
  * Manages connection to a remote endpoint_actor including auto-reconnection
  * and associated peer/unpeer messages.
  */
-class endpoint_proxy_actor : public caf::sb_actor<endpoint_proxy_actor> {
-friend class caf::sb_actor<endpoint_proxy_actor>;
+class endpoint_proxy_actor : public caf::event_based_actor {
 
 public:
 
@@ -571,6 +573,11 @@ public:
 
 private:
 
+	caf::behavior make_behavior() override
+		{
+		return bootstrap;
+		}
+
 	std::string report_subtopic(const std::string& endpoint_name,
 	                            const std::string& addr, uint16_t port) const
 		{
@@ -615,7 +622,6 @@ private:
 	caf::behavior bootstrap;
 	caf::behavior disconnected;
 	caf::behavior connected;
-	caf::behavior& init_state = bootstrap;
 };
 
 static inline caf::actor& handle_to_actor(void* h)
