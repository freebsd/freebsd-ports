--- latte-conf.h.orig	Tue Oct 26 02:52:03 1999
+++ latte-conf.h	Fri Mar 19 01:17:52 2004
@@ -30,7 +30,7 @@
 #define HAVE_VECTOR_RESIZE 1
 
 // Define if compiler chokes on shdeque.h
-/* #undef SHDEQUE_IS_BEYOND_ME */
+#define SHDEQUE_IS_BEYOND_ME 1
 
 // Define if string<> has no erase() but has remove()
 /* #undef USE_STRING_REMOVE */
