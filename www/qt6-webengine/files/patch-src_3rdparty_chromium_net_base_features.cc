--- src/3rdparty/chromium/net/base/features.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/net/base/features.cc
@@ -28,7 +28,7 @@ BASE_FEATURE(kChromeStaticPinning,
              base::FEATURE_ENABLED_BY_DEFAULT);
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_ANDROID) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kAsyncDns,
              "AsyncDns",
              base::FEATURE_ENABLED_BY_DEFAULT
@@ -566,7 +566,12 @@ BASE_FEATURE(kSpdyHeadersToHttpResponseUseBuilder,
              "SpdyHeadersToHttpResponseUseBuilder",
              base::FEATURE_DISABLED_BY_DEFAULT);
 
+#if BUILDFLAG(IS_OPENBSD)
+// No IP_RECVTOS support
+BASE_FEATURE(kReportEcn, "ReportEcn", base::FEATURE_DISABLED_BY_DEFAULT);
+#else
 BASE_FEATURE(kReportEcn, "ReportEcn", base::FEATURE_ENABLED_BY_DEFAULT);
+#endif
 
 BASE_FEATURE(kUseNewAlpsCodepointHttp2,
              "UseNewAlpsCodepointHttp2",
