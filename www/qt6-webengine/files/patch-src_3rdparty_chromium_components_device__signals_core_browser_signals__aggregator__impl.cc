--- src/3rdparty/chromium/components/device_signals/core/browser/signals_aggregator_impl.cc.orig	2023-07-16 15:47:57 UTC
+++ src/3rdparty/chromium/components/device_signals/core/browser/signals_aggregator_impl.cc
@@ -65,7 +65,7 @@ SignalsAggregatorImpl::SignalsAggregatorImpl(
 
 SignalsAggregatorImpl::~SignalsAggregatorImpl() = default;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void SignalsAggregatorImpl::GetSignalsForUser(
     const UserContext& user_context,
     const SignalsAggregationRequest& request,
