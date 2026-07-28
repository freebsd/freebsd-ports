-- Make the LP node destructors out-of-line so their type_info objects are
-- emitted as strong (GLOBAL) symbols in libdwave-optimization.so.  Without
-- this, the Cython lp.so module emits its own copies of the polymorphic base
-- LinearProgramNodeBase type_info, which breaks cross-DSO dynamic_cast from
-- LinearProgramNode to LinearProgramNodeBase on FreeBSD/Clang.

--- dwave/optimization/include/dwave-optimization/nodes/lp.hpp.orig	2026-07-23 12:58:12 UTC
+++ dwave/optimization/include/dwave-optimization/nodes/lp.hpp
@@ -27,6 +27,8 @@
 /// A logical node that propagates whether or not its predecessor LinearProgram is feasible.
 class LinearProgramFeasibleNode : public ScalarOutputMixin<EqualityMixin<ArrayNode>, true> {
  public:
+    virtual ~LinearProgramFeasibleNode();
+
     explicit LinearProgramFeasibleNode(LinearProgramNodeBase* lp_ptr);

     /// @copydoc Node::initialize_state()
@@ -53,6 +55,8 @@

 class LinearProgramNodeBase : public Node {
  public:
+    virtual ~LinearProgramNodeBase();
+
     /// The default lower bound for variables
     static const double default_lower_bound();

@@ -102,6 +106,8 @@
 ///         callback=None, options=None, x0=None, integrality=None)
 class LinearProgramNode : public EqualityMixin<LinearProgramNodeBase, LinearProgramNode> {
  public:
+    virtual ~LinearProgramNode();
+
     /// Construct a LinearProgramNode
     ///
     /// Note: parameter names are chosen to match scipy.optimize.lingprog()
@@ -194,6 +200,8 @@
 /// LinearProgramNode. Note that the output is undefined if the solution is not feasible.
 class LinearProgramObjectiveValueNode : public ScalarOutputMixin<EqualityMixin<ArrayNode>, true> {
  public:
+    virtual ~LinearProgramObjectiveValueNode();
+
     explicit LinearProgramObjectiveValueNode(LinearProgramNodeBase* lp_ptr);

     /// @copydoc Node::initialize_state()
@@ -222,6 +230,8 @@
 /// solution may not be feasible or optimial.
 class LinearProgramSolutionNode : public ArrayOutputMixin<EqualityMixin<ArrayNode>> {
  public:
+    virtual ~LinearProgramSolutionNode();
+
     explicit LinearProgramSolutionNode(LinearProgramNodeBase* lp_ptr);

     /// @copydoc Array::buff()
