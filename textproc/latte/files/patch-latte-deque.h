--- latte-deque.h.orig	Fri Oct 22 13:03:19 1999
+++ latte-deque.h	Fri Mar 19 01:17:52 2004
@@ -26,13 +26,13 @@
 #include <deque>
 
 template <class T>
-class latte_deque : public deque<T> {
+class latte_deque : public std::deque<T> {
  public:
   latte_deque() {}
 
 #ifdef HAVE_NOV96_DEQUE
   latte_deque(const const_iterator &a,
-	      const const_iterator &b) : deque<T>(a, b) {}
+	      const const_iterator &b) : std::deque<T>(a, b) {}
 #else // HAVE_NOV96_DEQUE
   latte_deque(const const_iterator &a,
 	      const const_iterator &b) {
