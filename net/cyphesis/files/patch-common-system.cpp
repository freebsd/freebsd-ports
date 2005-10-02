--- common/system.cpp.orig	Sun Oct  2 17:42:56 2005
+++ common/system.cpp	Sun Oct  2 17:43:29 2005
@@ -74,6 +74,14 @@
 #endif
 }
 
+#ifndef SA_ONESHOT
+# ifdef SA_RESETHAND
+#  define SA_ONESHOT SA_RESETHAND
+# else
+#  define SA_ONESHOT 0
+# endif
+#endif
+
 void interactive_signals()
 {
 #if defined(HAVE_SIGACTION)
