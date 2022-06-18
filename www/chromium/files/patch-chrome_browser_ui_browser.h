--- chrome/browser/ui/browser.h.orig	2022-06-17 14:20:10 UTC
+++ chrome/browser/ui/browser.h
@@ -734,7 +734,7 @@ class Browser : public TabStripModelObserver,
 
   StatusBubble* GetStatusBubbleForTesting();
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   void RunScreenAIAnnotator();
 #endif
 
