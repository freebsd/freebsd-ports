--- src/jsregexp.h.orig	2011-09-23 16:55:52.000000000 +0800
+++ src/jsregexp.h	2011-09-23 16:56:04.000000000 +0800
@@ -1071,7 +1071,7 @@ class ChoiceNode: public RegExpNode {
   virtual bool try_to_emit_quick_check_for_alternative(int i) { return true; }
 
  protected:
-  int GreedyLoopTextLength(GuardedAlternative* alternative);
+  int GreedyLoopTextLengthForAlternative(GuardedAlternative* alternative);
   ZoneList<GuardedAlternative>* alternatives_;
 
  private:
