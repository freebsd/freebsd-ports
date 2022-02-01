--- chrome/browser/ui/views/bookmarks/bookmark_bar_view_test.cc.orig	2021-12-14 11:44:59 UTC
+++ chrome/browser/ui/views/bookmarks/bookmark_bar_view_test.cc
@@ -1865,7 +1865,7 @@ class BookmarkBarViewTest20 : public BookmarkBarViewEv
   }
 
   void Step3() {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
     EXPECT_EQ(1, test_view_->press_count());
 #else
     EXPECT_EQ(2, test_view_->press_count());
