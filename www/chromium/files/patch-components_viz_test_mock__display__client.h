--- components/viz/test/mock_display_client.h.orig	2021-04-14 18:41:02 UTC
+++ components/viz/test/mock_display_client.h
@@ -39,7 +39,7 @@ class MockDisplayClient : public mojom::DisplayClient 
 #endif
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   MOCK_METHOD1(DidCompleteSwapWithNewSize, void(const gfx::Size&));
 #endif
 
