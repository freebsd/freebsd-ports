--- src/api/app/rate_limit.py.orig	2026-05-10 11:25:04 UTC
+++ src/api/app/rate_limit.py
@@ -10,8 +10,15 @@ from regex import compile as regex_compile, Pattern, e
 from fastapi.responses import Response
 
 from regex import compile as regex_compile, Pattern, escape, fullmatch, search, split
-from slowapi import Limiter, _rate_limit_exceeded_handler
-from slowapi.errors import RateLimitExceeded
+try:
+    from slowapi import Limiter, _rate_limit_exceeded_handler
+    from slowapi.errors import RateLimitExceeded
+    _SLOWAPI_AVAILABLE = True
+except ModuleNotFoundError:
+    Limiter = None  # type: ignore[assignment]
+    _rate_limit_exceeded_handler = None  # type: ignore[assignment]
+    RateLimitExceeded = Exception  # type: ignore[assignment]
+    _SLOWAPI_AVAILABLE = False
 from yaml import safe_load
 
 from .config import api_config
@@ -533,6 +540,10 @@ def setup_rate_limiter(app) -> None:
 def setup_rate_limiter(app) -> None:
     if not api_config.rate_limit_enabled:
         LOGGER.info("API rate limiting disabled by configuration")
+        return
+
+    if not _SLOWAPI_AVAILABLE:
+        LOGGER.warning("API rate limiting requested but slowapi is unavailable; disabling rate limiting on this platform")
         return
 
     global _limiter, _enabled, _rules, _base_limits, _exempt_networks, _auth_limit
