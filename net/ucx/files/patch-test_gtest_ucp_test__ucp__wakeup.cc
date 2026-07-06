--- test/gtest/ucp/test_ucp_wakeup.cc.orig	2026-05-07 22:24:17 UTC
+++ test/gtest/ucp/test_ucp_wakeup.cc
@@ -7,7 +7,11 @@
 #include "ucp_test.h"
 
 #include <algorithm>
+#ifdef __linux__
 #include <sys/epoll.h>
+#else
+#include <sys/event.h>
+#endif
 #include <sys/poll.h>
 
 
@@ -195,7 +199,11 @@ class test_ucp_wakeup_external_epollfd : public test_u
     static void* const USER_DATA;
 
     virtual void init() {
+#ifdef __linux__
         m_epfd = epoll_create(1);
+#else
+        m_epfd = kqueue();
+#endif
         ASSERT_GE(m_epfd, 0);
         test_ucp_wakeup::init();
     }
@@ -248,6 +256,7 @@ UCS_TEST_P(test_ucp_wakeup_external_epollfd, epoll_wai
         }
         ASSERT_UCS_OK(status);
 
+#ifdef __linux__
         struct epoll_event event;
         int ret;
         do {
@@ -258,6 +267,18 @@ UCS_TEST_P(test_ucp_wakeup_external_epollfd, epoll_wai
         }
         ASSERT_EQ(1, ret);
         EXPECT_EQ(USER_DATA, event.data.ptr);
+#else
+        struct kevent event;
+        int ret;
+        do {
+            ret = kevent(m_epfd, NULL, 0, &event, 1, NULL);
+        } while ((ret < 0) && (errno == EINTR));
+        if (ret < 0) {
+            UCS_TEST_MESSAGE << "kevent() failed: " << strerror(errno);
+        }
+        ASSERT_EQ(1, ret);
+        EXPECT_EQ(USER_DATA, event.udata);
+#endif
     }
 
     ucp_request_release(req);
