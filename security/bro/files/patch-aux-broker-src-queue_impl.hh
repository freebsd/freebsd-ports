--- aux/broker/src/queue_impl.hh.orig	2015-09-06 19:43:53 UTC
+++ aux/broker/src/queue_impl.hh
@@ -18,7 +18,7 @@ public:
 		util::flare f;
 		fd = f.fd();
 		actor = caf::spawn<
-		        broker::util::queue_actor<decltype(caf::on<T>()), T>,
+		        broker::util::queue_actor<T>,
 		        caf::priority_aware>(std::move(f));
 		self->planned_exit_reason(caf::exit_reason::user_defined);
 		actor->link_to(self);
