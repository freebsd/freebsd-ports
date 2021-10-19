--- components/feature_engagement/public/feature_constants.h.orig	2021-09-24 04:26:03 UTC
+++ components/feature_engagement/public/feature_constants.h
@@ -19,7 +19,7 @@ extern const base::Feature kIPHSnooze;
 // A feature to ensure all arrays can contain at least one feature.
 extern const base::Feature kIPHDummyFeature;
 
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
 extern const base::Feature kIPHDesktopTabGroupsNewGroupFeature;
 extern const base::Feature kIPHFocusModeFeature;
@@ -35,7 +35,7 @@ extern const base::Feature kIPHDesktopSnoozeFeature;
 extern const base::Feature kIPHDesktopPwaInstallFeature;
 extern const base::Feature kIPHProfileSwitchFeature;
 extern const base::Feature kIPHUpdatedConnectionSecurityIndicatorsFeature;
-#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
 
 // All the features declared for Android below that are also used in Java,
@@ -126,7 +126,7 @@ extern const base::Feature kIPHBadgedTranslateManualTr
 extern const base::Feature kIPHDiscoverFeedHeaderFeature;
 #endif  // defined(OS_IOS)
 
-#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_APPLE) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS) || defined(OS_ANDROID) || defined(OS_FUCHSIA)
 extern const base::Feature kIPHUpdatedConnectionSecurityIndicatorsFeature;
 #endif
