--- ./src/eparser.cpp.orig	2011-06-03 19:15:42.000000000 +0200
+++ ./src/eparser.cpp	2014-04-08 14:55:51.807605460 +0200
@@ -139,7 +139,7 @@
     }
 }
 
-bool is_function(int op)
+bool my_is_function(int op)
 {
     return (bool) get_function_narg(op);
 }
@@ -812,7 +812,7 @@
                 // check if this is closing bracket of func()
                 if (!opstack_.empty()) {
                     int top = opstack_.back();
-                    if (is_function(top)) {
+                    if (my_is_function(top)) {
                         pop_onto_que();
                         int n = arg_cnt_.back() + 1;
                         int expected_n = get_function_narg(top);
@@ -846,7 +846,7 @@
                     lex.throw_syntax_error("unexpected ',' after '?'");
                 // if we are here, opstack_.back() == OP_OPEN_ROUND
                 else if (opstack_.size() < 2 ||
-                         !is_function(*(opstack_.end() - 2)))
+                         !my_is_function(*(opstack_.end() - 2)))
                     lex.throw_syntax_error("',' outside of function");
                 else
                     // don't pop OP_OPEN_ROUND from the stack
