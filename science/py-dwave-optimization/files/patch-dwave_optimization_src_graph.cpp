--- dwave/optimization/src/graph.cpp.orig	2026-07-27 22:30:07 UTC
+++ dwave/optimization/src/graph.cpp
@@ -33,6 +33,10 @@ namespace dwave::optimization {
 
 namespace dwave::optimization {
 
+Node::~Node() { *expired_ptr_ = true; }
+Array::~Array() = default;
+ArrayNode::~ArrayNode() = default;
+
 void Graph::add_constraint(ArrayNode* constraint_ptr) {
     if (not constraint_ptr->logical()) {
         throw std::invalid_argument("constraint must have a logical output");
