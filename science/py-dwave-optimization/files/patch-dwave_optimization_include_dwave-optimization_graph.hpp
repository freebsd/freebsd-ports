--- dwave/optimization/include/dwave-optimization/graph.hpp.orig	2026-07-27 22:30:07 UTC
+++ dwave/optimization/include/dwave-optimization/graph.hpp
@@ -254,7 +254,7 @@ class Node {
     };
 
     Node() noexcept : expired_ptr_(new bool(false)) {}
-    virtual ~Node() { *expired_ptr_ = true; }
+    virtual ~Node();
 
     // Nodes cannot be moved or copied.
     Node(const Node&) = delete;
@@ -452,7 +452,10 @@ NodeType* Graph::emplace_node(Args&&... args) {
     return ptr;  // return the observing pointer
 }
 
-class ArrayNode : public Array, public virtual Node {};
+class ArrayNode : public Array, public virtual Node {
+ public:
+    ~ArrayNode() override;
+};
 class DecisionNode : public Decision, public virtual Node {
  public:
     /// Decision nodes by definition do not have a deterministic state.
