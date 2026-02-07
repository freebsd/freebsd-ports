From 0f869da21f79bd15435418f32fa51f3f7ca86743 Mon Sep 17 00:00:00 2001
From: Daniel McCarney <daniel@binaryparadox.net>
Date: Thu, 6 Feb 2025 10:59:39 -0500
Subject: [PATCH] tls_cache: fix implicit conversion err on i386/i686

Previously on arch's where `apr_ssize_t` is an `int` (e.g. i386) the
`tls_cache_get()` function produced an implicit conversion error of the
form:

```
error: implicit conversion changes signedness: 'unsigned int' to 'apr_ssize_t' (aka 'int')
```

This commit resolves this error by:

1. Checking the two casts performed by this function are within the
   range of the types being cast to.
2. Making the cast to `apr_ssize_t` explicit.
---
 src/tls_cache.c | 6 +++++-
 1 file changed, 5 insertions(+), 1 deletion(-)

diff --git a/src/tls_cache.c b/src/tls_cache.c
index 5fc874f..428a59e 100644
--- src/tls_cache.c.orig
+++ src/tls_cache.c
@@ -231,6 +231,10 @@ static rustls_result tls_cache_get(
     unsigned int vlen, klen;
     const unsigned char *kdata;
 
+    if (key->len > UINT_MAX || key->len > SSIZE_MAX) {
+        return RUSTLS_RESULT_INVALID_PARAMETER;
+    }
+
     if (!sc->global->session_cache) goto not_found;
     tls_cache_lock(sc->global);
 
@@ -241,7 +245,7 @@ static rustls_result tls_cache_get(
         sc->global->session_cache, cc->server, kdata, klen, buf, &vlen, c->pool);
 
     if (APLOGctrace4(c)) {
-        apr_ssize_t n = klen;
+        apr_ssize_t n = (apr_ssize_t) klen;
         ap_log_cerror(APLOG_MARK, APLOG_TRACE4, rv, c, "retrieve key %d[%8x], found %d val",
             klen, apr_hashfunc_default((const char*)kdata, &n), vlen);
     }
