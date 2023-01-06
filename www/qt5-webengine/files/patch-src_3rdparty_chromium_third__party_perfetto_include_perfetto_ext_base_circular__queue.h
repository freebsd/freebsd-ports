commit c81e804f8d37823aac9cf9d6d4ca92363284bf3b
Author: Lalit Maganti <lalitm@google.com>
Date:   Tue Apr 7 21:13:02 2020 +0100

    base: attempt to fix compile on vs2019
    
    Bug: 153189621
    Change-Id: Ie93cd0d6e4e128c5402539dac15507d4aed22edd

--- src/3rdparty/chromium/third_party/perfetto/include/perfetto/ext/base/circular_queue.h.orig	2020-11-07 01:22:36 UTC
+++ src/3rdparty/chromium/third_party/perfetto/include/perfetto/ext/base/circular_queue.h
@@ -52,8 +52,8 @@ class CircularQueue {
    public:
     using difference_type = ptrdiff_t;
     using value_type = T;
-    using pointer = const T*;
-    using reference = const T&;
+    using pointer = T*;
+    using reference = T&;
     using iterator_category = std::random_access_iterator_tag;
 
     Iterator(CircularQueue* queue, uint64_t pos, uint32_t generation)
