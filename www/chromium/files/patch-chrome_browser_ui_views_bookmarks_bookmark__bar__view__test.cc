--- chrome/browser/ui/views/bookmarks/bookmark_bar_view_test.cc.orig	2020-09-08 19:14:01 UTC
+++ chrome/browser/ui/views/bookmarks/bookmark_bar_view_test.cc
@@ -1835,7 +1835,7 @@ class BookmarkBarViewTest20 : public BookmarkBarViewEv
   }
 
   void Step3() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     EXPECT_EQ(1, test_view_->press_count());
 #else
     EXPECT_EQ(2, test_view_->press_count());
