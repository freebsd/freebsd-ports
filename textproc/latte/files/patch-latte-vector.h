--- latte-vector.h.orig	Fri Oct 22 13:04:00 1999
+++ latte-vector.h	Fri Mar 19 01:17:52 2004
@@ -28,14 +28,14 @@
 #ifdef HAVE_VECTOR_RESIZE
 
 template <class T>
-class latte_vector : public vector<T> {
+class latte_vector : public std::vector<T> {
   // empty (I wish there were template typedefs)
 };
 
 #else // HAVE_VECTOR_RESIZE
 
 template <class T>
-class latte_vector : public vector<T> {
+class latte_vector : public std::vector<T> {
  public:
   void resize(size_t n, const T &obj) {
     if (n > size())
