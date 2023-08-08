--- chrome/browser/signin/bound_session_credentials/fake_bound_session_refresh_cookie_fetcher.cc.orig	2023-07-21 09:49:17 UTC
+++ chrome/browser/signin/bound_session_credentials/fake_bound_session_refresh_cookie_fetcher.cc
@@ -51,7 +51,11 @@ void FakeBoundSessionRefreshCookieFetcher::SimulateCom
     // Synchronous since tests use `BoundSessionTestCookieManager`.
     OnRefreshCookieCompleted(CreateFakeCookie(cookie_expiration.value()));
   } else {
+#if defined(__clang__) && (__clang_major__ >= 15)
     std::move(callback_).Run(Result(net::Error::OK, net::HTTP_FORBIDDEN));
+#else
+    std::move(callback_).Run(Result({net::Error::OK, net::HTTP_FORBIDDEN}));
+#endif
   }
 }
 
@@ -83,9 +87,17 @@ void FakeBoundSessionRefreshCookieFetcher::OnCookieSet
     net::CookieAccessResult access_result) {
   bool success = access_result.status.IsInclude();
   if (!success) {
+#if defined(__clang__) && (__clang_major__ >= 15)
     std::move(callback_).Run(Result(net::Error::OK, net::HTTP_FORBIDDEN));
+#else
+    std::move(callback_).Run(Result({net::Error::OK, net::HTTP_FORBIDDEN}));
+#endif
   } else {
+#if defined(__clang__) && (__clang_major__ >= 15)
     std::move(callback_).Run(Result(net::Error::OK, net::HTTP_OK));
+#else
+    std::move(callback_).Run(Result({net::Error::OK, net::HTTP_OK}));
+#endif
   }
   // |This| may be destroyed
 }
