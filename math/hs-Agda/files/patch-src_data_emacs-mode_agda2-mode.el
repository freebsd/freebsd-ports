--- src/data/emacs-mode/agda2-mode.el.orig	2001-09-09 01:46:40 UTC
+++ src/data/emacs-mode/agda2-mode.el
@@ -1306,7 +1306,8 @@ top-level scope."
 
 (agda2-maybe-normalised
  agda2-elaborate-give
- "Elaborate check the given expression against the hole's type and fill in hole with the elaborated term"
+ "Elaborate check the given expression against the hole's type and fill
+in hole with the elaborated term"
  "Cmd_elaborate_give"
  "expression to elaborate and give")
 
@@ -1324,7 +1325,8 @@ top-level scope."
 
 (agda2-maybe-normalised
  agda2-goal-and-context-and-checked
- "Shows the context, the goal and check the given expression's against the hole's type"
+ "Shows the context, the goal and check the given expression's against
+the hole's type"
  "Cmd_goal_type_context_check"
  "expression to type")
 
