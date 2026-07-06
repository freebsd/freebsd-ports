--- test/gtest/ucs/test_event_set.cc.orig	2026-02-04 09:52:47 UTC
+++ test/gtest/ucs/test_event_set.cc
@@ -8,7 +8,11 @@ extern "C" {
 extern "C" {
 #include <ucs/sys/event_set.h>
 #include <pthread.h>
+#ifdef __linux__
 #include <sys/epoll.h>
+#else
+#include <sys/event.h>
+#endif
 }
 
 #define MAX_BUF_LEN        255
@@ -40,8 +44,12 @@ class test_event_set : public ucs::test_base, (protect
 protected:
     void init() {
         if (GetParam() & UCS_EVENT_SET_EXTERNAL_FD) {
+#ifdef __linux__
             m_ext_fd = epoll_create(1);
-            ASSERT_TRUE(m_ext_fd > 0);
+#else
+            m_ext_fd = kqueue();
+#endif
+	    ASSERT_TRUE(m_ext_fd > 0);
         } else {
             m_ext_fd = -1;
         }
