Index: kadu-core/main.cpp
===================================================================
--- kadu-core/main.cpp	2008-02-26 01:07:33.000000000 +0100
+++ kadu-core/main.cpp	2008-03-12 10:55:42.000000000 +0100
@@ -50,6 +50,9 @@
 #ifdef HAVE_EXECINFO
 #include <execinfo.h>
 #endif
+#ifdef __FreeBSD__
+typedef union sigval sigval_t;
+#endif /* __FreeBSD__ */
 #define OPEN_CHAT_SIGNAL (SIGRTMIN + 7)
 
 static int sigsegvCount = 0;
