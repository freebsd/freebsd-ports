--- chrome/browser/signin/bound_session_credentials/bound_session_refresh_cookie_fetcher_impl.cc.orig	2023-07-21 09:49:17 UTC
+++ chrome/browser/signin/bound_session_credentials/bound_session_refresh_cookie_fetcher_impl.cc
@@ -103,6 +103,6 @@ void BoundSessionRefreshCookieFetcherImpl::OnURLLoader
   net::Error net_error = static_cast<net::Error>(url_loader_->NetError());
 
   std::move(callback_).Run(
-      Result(net_error, headers ? absl::optional<int>(headers->response_code())
-                                : absl::nullopt));
+      Result({net_error, headers ? absl::optional<int>(headers->response_code())
+                                : absl::nullopt}));
 }
