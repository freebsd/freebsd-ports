--- latte-stack.h.orig	Fri Oct 22 13:03:40 1999
+++ latte-stack.h	Fri Mar 19 01:17:52 2004
@@ -28,7 +28,7 @@
 
 # include <stack>
 template <class T>
-class latte_stack : public stack<T> {
+class latte_stack : public std::stack<T> {
   // empty (I wish there were template typedefs)
 };
 
@@ -37,7 +37,7 @@
 # include <deque>
 # include <stack>
 template <class T>
-class latte_stack : public stack< deque<T> > {
+class latte_stack : public std::stack< std::deque<T> > {
   // empty (I wish there were template typedefs)
 };
 
