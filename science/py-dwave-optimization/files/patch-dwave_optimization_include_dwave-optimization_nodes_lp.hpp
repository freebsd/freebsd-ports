-- Add missing out-of-line destructor declarations for the LP node classes so
-- their type_info objects are emitted as strong (GLOBAL) symbols in
-- libdwave-optimization.so.  Without this, the Cython lp.so module emits its
-- own copies of the polymorphic base LinearProgramNodeBase type_info, which
-- breaks cross-DSO dynamic_cast from LinearProgramNode to LinearProgramNodeBase
-- on FreeBSD/Clang.

--- dwave/optimization/include/dwave-optimization/nodes/lp.hpp.orig	2026-09-07 15:29:23 UTC
+++ dwave/optimization/include/dwave-optimization/nodes/lp.hpp
@@ -27,6 +27,8 @@ class LinearProgramFeasibleNode : public ScalarOutputM
 /// A logical node that propagates whether or not its predecessor LinearProgram is feasible.
 class LinearProgramFeasibleNode : public ScalarOutputMixin<EqualityMixin<ArrayNode>, true> {
  public:
+    virtual ~LinearProgramFeasibleNode();
+
     explicit LinearProgramFeasibleNode(LinearProgramNodeBase* lp_ptr);
 
     /// @copydoc Node::initialize_state()
@@ -53,6 +55,8 @@ class LinearProgramNodeBase : public Node {
 
 class LinearProgramNodeBase : public Node {
  public:
+    virtual ~LinearProgramNodeBase();
+
     /// The default lower bound for variables
     static const double default_lower_bound();
 
@@ -102,6 +106,8 @@ class LinearProgramNode : public EqualityMixin<LinearP
 ///         callback=None, options=None, x0=None, integrality=None)
 class LinearProgramNode : public EqualityMixin<LinearProgramNodeBase, LinearProgramNode> {
  public:
+    virtual ~LinearProgramNode();
+
     using linprog_type = std::function<std::vector<double>(
         std::span<const double> c,
         std::span<const double> b_lb,
@@ -208,6 +214,8 @@ class LinearProgramObjectiveValueNode : public ScalarO
 /// LinearProgramNode. Note that the output is undefined if the solution is not feasible.
 class LinearProgramObjectiveValueNode : public ScalarOutputMixin<EqualityMixin<ArrayNode>, true> {
  public:
+    virtual ~LinearProgramObjectiveValueNode();
+
     explicit LinearProgramObjectiveValueNode(LinearProgramNodeBase* lp_ptr);
 
     /// @copydoc Node::initialize_state()
@@ -236,6 +244,8 @@ class LinearProgramSolutionNode : public ArrayOutputMi
 /// solution may not be feasible or optimial.
 class LinearProgramSolutionNode : public ArrayOutputMixin<EqualityMixin<ArrayNode>> {
  public:
+    virtual ~LinearProgramSolutionNode();
+
     explicit LinearProgramSolutionNode(LinearProgramNodeBase* lp_ptr);
 
     /// @copydoc Array::buff()
