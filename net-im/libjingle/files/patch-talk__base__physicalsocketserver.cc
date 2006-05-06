--- talk/base/physicalsocketserver.cc.orig	Thu May  4 10:51:48 2006
+++ talk/base/physicalsocketserver.cc	Fri May  5 16:16:16 2006
@@ -222,6 +222,11 @@
     return ::setsockopt(
         s_, IPPROTO_IP, IP_MTU_DISCOVER, &value, sizeof(value));
 #endif
+#ifdef __FreeBSD__
+    value = (value == 0) ? 0 : 1;
+    return ::setsockopt(
+        s_, IPPROTO_IP, IP_DONTFRAG, &value, sizeof(value));
+#endif
 #ifdef OSX
     // This is not possible on OSX.
     return -1;
