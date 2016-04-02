--- deps/v8/src/compiler/js-type-feedback.h.orig	2016-03-16 21:22:58.000000000 +0100
+++ deps/v8/src/compiler/js-type-feedback.h	2016-03-24 22:54:54.529827000 +0100
@@ -33,9 +33,10 @@ class JSTypeFeedbackTable : public ZoneO
  private:
   friend class JSTypeFeedbackSpecializer;
   typedef std::map<NodeId, TypeFeedbackId, std::less<NodeId>,
-                   zone_allocator<TypeFeedbackId> > TypeFeedbackIdMap;
+                   zone_allocator<std::pair<const NodeId, TypeFeedbackId> > >
+      TypeFeedbackIdMap;
   typedef std::map<NodeId, FeedbackVectorICSlot, std::less<NodeId>,
-                   zone_allocator<FeedbackVectorICSlot> >
+                   zone_allocator<std::pair<const NodeId, FeedbackVectorICSlot> > >
       FeedbackVectorICSlotMap;
 
   TypeFeedbackIdMap type_feedback_id_map_;
