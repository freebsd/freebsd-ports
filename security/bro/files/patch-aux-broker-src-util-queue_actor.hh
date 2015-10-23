--- aux/broker/src/util/queue_actor.hh.orig	2015-09-06 19:43:53 UTC
+++ aux/broker/src/util/queue_actor.hh
@@ -3,7 +3,7 @@
 
 #include "../atoms.hh"
 #include "flare.hh"
-#include <caf/sb_actor.hpp>
+#include <caf/event_based_actor.hpp>
 #include <caf/scoped_actor.hpp>
 #include <deque>
 
@@ -15,9 +15,8 @@ namespace util {
  * a flare which signals when the queue is non-empty.  This makes it simple
  * to integrate in to traditional event loops.
  */
-template <typename Pattern, typename Message>
-class queue_actor : public caf::sb_actor<queue_actor<Pattern, Message>> {
-friend class caf::sb_actor<queue_actor<Pattern, Message>>;
+template <typename Message>
+class queue_actor : public caf::event_based_actor {
 
 public:
 
@@ -29,7 +28,7 @@ public:
 			{
 			[=](want_atom)
 				{ return pop(); },
-			Pattern() >> [=](Message& msg)
+			[=](Message& msg)
 				{
 				q.push_back(std::move(msg));
 				this->become(filled);
@@ -46,6 +45,11 @@ public:
 
 private:
 
+	caf::behavior make_behavior() override
+		{
+		return empty;
+		}
+
 	std::deque<Message> pop()
 		{
 		auto rval = std::move(q);
@@ -58,7 +62,6 @@ private:
 	flare ready_flare;
 	caf::behavior empty;
 	caf::behavior filled;
-	caf::behavior& init_state = empty;
 	std::deque<Message> q;
 };
 
