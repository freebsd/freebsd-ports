--- components/viz/test/mock_display_client.h.orig	2020-07-07 21:57:37 UTC
+++ components/viz/test/mock_display_client.h
@@ -36,7 +36,7 @@ class MockDisplayClient : public mojom::DisplayClient 
   MOCK_METHOD1(SetWideColorEnabled, void(bool enabled));
   MOCK_METHOD1(SetPreferredRefreshRate, void(float refresh_rate));
 #endif
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   MOCK_METHOD1(DidCompleteSwapWithNewSize, void(const gfx::Size&));
 #endif
 
