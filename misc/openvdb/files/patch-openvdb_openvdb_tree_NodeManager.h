--- openvdb/openvdb/tree/NodeManager.h.orig	2023-11-01 20:31:11 UTC
+++ openvdb/openvdb/tree/NodeManager.h
@@ -327,7 +327,7 @@ class NodeList (private)
         void operator()(const NodeRange& range) const
         {
             for (typename NodeRange::Iterator it = range.begin(); it; ++it) {
-                OpT::template eval(mNodeOp, it);
+                OpT::template eval<>(mNodeOp, it);
             }
         }
         const NodeOp mNodeOp;
@@ -347,7 +347,7 @@ class NodeList (private)
         void operator()(const NodeRange& range) const
         {
             for (typename NodeRange::Iterator it = range.begin(); it; ++it) {
-                OpT::template eval(mNodeOp, it);
+                OpT::template eval<>(mNodeOp, it);
             }
         }
         const NodeOp& mNodeOp;
@@ -372,7 +372,7 @@ class NodeList (private)
         void operator()(const NodeRange& range)
         {
             for (typename NodeRange::Iterator it = range.begin(); it; ++it) {
-                OpT::template eval(*mNodeOp, it);
+                OpT::template eval<>(*mNodeOp, it);
             }
         }
         void join(const NodeReducer& other)
