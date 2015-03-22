From c91f7bbf3e0eedb080319ba3cfed7b47597b5aeb Mon Sep 17 00:00:00 2001
From: Yawning Angel <yawning@torproject.org>
Date: Sun, 20 Apr 2014 16:52:06 +0000
Subject: Fix a potential bug found by clang's scan-build.

With all current uses of Ctr, the conditional I was missing is never
triggered since the paramenters are guaranteed to be sane, but this is
not guaranteed to be true in the future.

scan-build also points out a bunch of things in easylogging++ and gtest
but they don't look to be real problems.
---
 ChangeLog                     | 2 ++ [diff removed]
 src/schwanenlied/crypto/ctr.h | 5 ++++-
 2 files changed, 6 insertions(+), 1 deletion(-)

diff --git a/src/schwanenlied/crypto/ctr.h b/src/schwanenlied/crypto/ctr.h
index 79bb71b..92d932d 100644
--- src/schwanenlied/crypto/ctr.h
+++ src/schwanenlied/crypto/ctr.h
@@ -91,6 +91,8 @@ class Ctr {
       return false;
     if (ctr_len == 0)
       return false;
+    if ((iv == nullptr && iv_len != 0) || (iv != nullptr && iv_len == 0))
+      return false;
     if (ctr_len + iv_len != ecb_impl_.block_length())
       return false;
 
@@ -100,7 +102,8 @@ class Ctr {
       return false;
 
     iv_size_ = iv_len;
-    ::std::memcpy(&ctr_[0], iv, iv_len);
+    if (iv != nullptr)
+      ::std::memcpy(&ctr_[0], iv, iv_len);
     ::std::memcpy(&ctr_[iv_len], ctr, ctr_len);
 
     has_state_ = true;
-- 
2.3.0

