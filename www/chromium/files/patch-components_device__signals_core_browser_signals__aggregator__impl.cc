--- components/device_signals/core/browser/signals_aggregator_impl.cc.orig	2026-10-18 13:29:39 UTC
+++ components/device_signals/core/browser/signals_aggregator_impl.cc
@@ -67,7 +67,7 @@ SignalsAggregatorImpl::SignalsAggregatorImpl(
 
 SignalsAggregatorImpl::~SignalsAggregatorImpl() = default;
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void SignalsAggregatorImpl::GetSignalsForUser(
     const UserContext& user_context,
     const SignalsAggregationRequest& request,
