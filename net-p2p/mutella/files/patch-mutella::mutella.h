--- mutella/mutella.h.orig      Sat Dec 21 04:06:30 2002
+++ mutella/mutella.h   Sat Dec 21 04:09:31 2002
@@ -70,6 +70,7 @@
 // declare namespaces
 using std::min;
 using std::max;
+using std::find;
 using std::swap;
 //using std::queue;
 //using std::deque;
@@ -80,7 +81,11 @@
 #ifdef NAVE_NO_SLIST
 #  define slist list
 #else
+#ifdef HAVE_EXT_SLIST
+  using __gnu_cxx::slist;
+#else
   using std::slist;
+#endif
 #endif

 #endif /*__cplusplus*/
