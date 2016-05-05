--- deps/v8/src/compiler/js-type-feedback.h.orig	2016-04-21 17:45:24 UTC
+++ deps/v8/src/compiler/js-type-feedback.h
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
