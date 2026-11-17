--- src/components/device_signals/core/browser/signals_aggregator_impl.h.orig	2026-10-18 18:43:23 UTC
+++ src/components/device_signals/core/browser/signals_aggregator_impl.h
@@ -30,7 +30,7 @@ class SignalsAggregatorImpl : public Sig
   ~SignalsAggregatorImpl() override;
 
   // SignalsAggregator:
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void GetSignalsForUser(const UserContext& user_context,
                          const SignalsAggregationRequest& request,
                          GetSignalsCallback callback) override;
