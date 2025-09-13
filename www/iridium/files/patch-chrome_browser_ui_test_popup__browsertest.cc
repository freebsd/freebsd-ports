--- chrome/browser/ui/test/popup_browsertest.cc.orig	2025-09-11 13:19:19 UTC
+++ chrome/browser/ui/test/popup_browsertest.cc
@@ -76,7 +76,7 @@ IN_PROC_BROWSER_TEST_F(PopupTest, OpenLeftAndTopZeroCo
   const display::Display display = GetDisplayNearestBrowser(popup);
   gfx::Rect expected(popup->window()->GetBounds().size());
   expected.AdjustToFit(display.work_area());
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // TODO(crbug.com/40815883) Desktop Linux window bounds are inaccurate.
   expected.Outset(50);
   EXPECT_TRUE(expected.Contains(popup->window()->GetBounds()))
@@ -108,7 +108,7 @@ IN_PROC_BROWSER_TEST_F(PopupTest, OpenClampedToCurrent
     // The popup should be constrained to the opener's available display space.
     EXPECT_EQ(display, GetDisplayNearestBrowser(popup));
     gfx::Rect work_area(display.work_area());
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     // TODO(crbug.com/40815883) Desktop Linux bounds flakily extend outside the
     // work area on trybots, when opening with excessive width and height, e.g.:
     // width=${screen.availWidth+300},height=${screen.availHeight+300} yields:
