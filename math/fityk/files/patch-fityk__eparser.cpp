--- fityk/eparser.cpp.orig	2015-05-25 17:42:29 UTC
+++ fityk/eparser.cpp
@@ -154,7 +154,7 @@ int get_function_narg(int op)
     }
 }
 
-bool is_function(int op)
+bool my_is_funcion(int op)
 {
     return get_function_narg(op) != 0;
 }
@@ -878,7 +878,7 @@ void ExpressionParser::parse_expr(Lexer&
                 // check if this is closing bracket of func()
                 if (!opstack_.empty()) {
                     int top = opstack_.back();
-                    if (is_function(top)) {
+                    if (my_is_funcion(top)) {
                         pop_onto_que();
                         int n = opstack_.back() + 1;
                         opstack_.pop_back();
@@ -911,7 +911,7 @@ void ExpressionParser::parse_expr(Lexer&
                     lex.throw_syntax_error("unexpected ',' after '?'");
                 // if we are here, opstack_.back() == OP_OPEN_ROUND
                 else if (opstack_.size() < 3 ||
-                         !is_function(*(opstack_.end() - 2)))
+                         !my_is_funcion(*(opstack_.end() - 2)))
                     lex.throw_syntax_error("',' outside of function");
                 else
                     // don't pop OP_OPEN_ROUND from the stack
