--- third_party/blink/common/features.cc.orig	2023-01-13 08:56:02 UTC
+++ third_party/blink/common/features.cc
@@ -1759,9 +1759,10 @@ BASE_FEATURE(kSplitUserMediaQueues,
              "SplitUserMediaQueues",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
+// XXX https://crbug.com/1382032
 BASE_FEATURE(kTextCodecCJKEnabled,
              "TextCodecCJKEnabled",
-             base::FEATURE_ENABLED_BY_DEFAULT);
+             base::FEATURE_DISABLED_BY_DEFAULT);
 
 }  // namespace features
 }  // namespace blink
