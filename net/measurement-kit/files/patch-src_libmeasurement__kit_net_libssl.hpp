--- src/libmeasurement_kit/net/libssl.hpp.orig	2021-03-04 14:14:57 UTC
+++ src/libmeasurement_kit/net/libssl.hpp
@@ -156,7 +156,7 @@ class Context : public NonCopyable, public NonMovable 
                 SSL_CTX_free(ctx);
                 return {SslCtxLoadVerifyLocationsError(), {}};
             }
-        } else {
+        } else if (!SSL_CTX_set_default_verify_paths(ctx)) {
             SSL_CTX_free(ctx);
             return {MissingCaBundlePathError(), {}};
         }
