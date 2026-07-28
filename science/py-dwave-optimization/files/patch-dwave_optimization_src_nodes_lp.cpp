-- Define out-of-line destructors for the LP node classes so their type_info
-- objects are emitted as strong (GLOBAL) symbols in libdwave-optimization.so,
-- matching the header declarations.  This fixes cross-DSO dynamic_cast failures
-- on FreeBSD/Clang where each shared library otherwise gets its own copy of the
-- base LinearProgramNodeBase type_info.

--- dwave/optimization/src/nodes/lp.cpp.orig	2026-07-23 12:58:12 UTC
+++ dwave/optimization/src/nodes/lp.cpp
@@ -22,6 +22,12 @@
 #include "dwave-optimization/graph.hpp"

 namespace dwave::optimization {
+
+LinearProgramFeasibleNode::~LinearProgramFeasibleNode() = default;
+LinearProgramNodeBase::~LinearProgramNodeBase() = default;
+LinearProgramNode::~LinearProgramNode() = default;
+LinearProgramObjectiveValueNode::~LinearProgramObjectiveValueNode() = default;
+LinearProgramSolutionNode::~LinearProgramSolutionNode() = default;

 static constexpr double FEASIBILITY_TOLERANCE = 1e-07;
