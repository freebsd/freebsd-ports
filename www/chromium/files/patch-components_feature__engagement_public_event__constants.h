--- components/feature_engagement/public/event_constants.h.orig	2019-07-24 18:58:19 UTC
+++ components/feature_engagement/public/event_constants.h
@@ -57,7 +57,7 @@ extern const char kFocusModeOpened[];
 extern const char kFocusModeConditionsMet[];
 #endif  // BUILDFLAG(ENABLE_DESKTOP_IN_PRODUCT_HELP)
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_IOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_IOS) || defined(OS_BSD)
 // This event is included in the deferred onboarding events for the New Tab
 // described above, but it is also used on iOS, so it must be compiled
 // separately.
@@ -65,7 +65,7 @@ extern const char kFocusModeConditionsMet[];
 // The user has explicitly opened a new tab via an entry point from inside of
 // Chrome.
 extern const char kNewTabOpened[];
-#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_IOS)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_IOS) || defined(OS_BSD)
 
 #if defined(OS_IOS)
 // The user has opened Chrome (cold start or from background).
