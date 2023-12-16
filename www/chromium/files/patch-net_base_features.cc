--- net/base/features.cc.orig	2023-12-10 06:10:27 UTC
+++ net/base/features.cc
@@ -468,7 +468,12 @@ BASE_FEATURE(kSpdyHeadersToHttpResponseUseBuilder,
              "SpdyHeadersToHttpResponseUseBuilder",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
+#if BUILDFLAG(IS_OPENBSD)
+// No IP_RECVTOS support
 BASE_FEATURE(kReceiveEcn, "ReceiveEcn", base::FEATURE_DISABLED_BY_DEFAULT);
+#else
+BASE_FEATURE(kReceiveEcn, "ReceiveEcn", base::FEATURE_DISABLED_BY_DEFAULT);
+#endif
 
 // TODO(crbug.com/634470): Remove this feature flag in January 2024 if the new
 // limit sticks.
