--- src/jsregexp.cc.orig	2011-08-31 17:03:56.000000000 +0800
+++ src/jsregexp.cc	2011-09-23 20:41:09.000000000 +0800
@@ -2661,7 +2661,7 @@ int TextNode::GreedyLoopTextLength() {
 // this alternative and back to this choice node.  If there are variable
 // length nodes or other complications in the way then return a sentinel
 // value indicating that a greedy loop cannot be constructed.
-int ChoiceNode::GreedyLoopTextLength(GuardedAlternative* alternative) {
+int ChoiceNode::GreedyLoopTextLengthForAlternative(GuardedAlternative* alternative) {
   int length = 0;
   RegExpNode* node = alternative->node();
   // Later we will generate code for all these text nodes using recursion
@@ -2700,7 +2700,7 @@ void LoopChoiceNode::AddContinueAlternat
 void LoopChoiceNode::Emit(RegExpCompiler* compiler, Trace* trace) {
   RegExpMacroAssembler* macro_assembler = compiler->macro_assembler();
   if (trace->stop_node() == this) {
-    int text_length = GreedyLoopTextLength(&(alternatives_->at(0)));
+    int text_length = GreedyLoopTextLengthForAlternative(&(alternatives_->at(0)));
     ASSERT(text_length != kNodeIsTooComplexForGreedyLoops);
     // Update the counter-based backtracking info on the stack.  This is an
     // optimization for greedy loops (see below).
@@ -2893,7 +2893,7 @@ void ChoiceNode::Emit(RegExpCompiler* co
 
   Trace* current_trace = trace;
 
-  int text_length = GreedyLoopTextLength(&(alternatives_->at(0)));
+  int text_length = GreedyLoopTextLengthForAlternative(&(alternatives_->at(0)));
   bool greedy_loop = false;
   Label greedy_loop_label;
   Trace counter_backtrack_trace;
