--- components/device_signals/core/browser/mock_signals_aggregator.h.orig	2025-12-10 15:04:57 UTC
+++ components/device_signals/core/browser/mock_signals_aggregator.h
@@ -17,7 +17,7 @@ class MockSignalsAggregator : public SignalsAggregator
   MockSignalsAggregator();
   ~MockSignalsAggregator() override;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   MOCK_METHOD(void,
               GetSignalsForUser,
               (const UserContext&,
