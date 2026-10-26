--- agent/anthropic_adapter.py.orig	2026-10-23 02:24:27 UTC
+++ agent/anthropic_adapter.py
@@ -375,9 +375,37 @@ def _attribution_headers() -> dict[str, str]:
     }
 
 
+_SDK_HTTPX_MOD = None
+
+
+def _sdk_httpx():
+    """The httpx module the installed anthropic SDK is built against.
+
+    anthropic 1.x moved its HTTP stack to ``httpx2``; objects crossing the SDK boundary
+    (``Timeout``, ``http_client``) must come from the same module or the SDK rejects them at
+    request time. Same split ``tools/mcp_tool.py:sdk_httpx()`` handles for mcp 1.x/2.x.
+    """
+    global _SDK_HTTPX_MOD
+    if _SDK_HTTPX_MOD is not None:
+        return _SDK_HTTPX_MOD
+    try:
+        from anthropic import _base_client as _bc
+        _SDK_HTTPX_MOD = getattr(_bc, "httpx2", None) or getattr(_bc, "httpx", None)
+    except ImportError:
+        _SDK_HTTPX_MOD = None
+    if _SDK_HTTPX_MOD is None:
+        try:
+            import httpx2 as _fallback
+        except ImportError:
+            import httpx as _fallback  # type: ignore[no-redef]
+        _SDK_HTTPX_MOD = _fallback
+    return _SDK_HTTPX_MOD
+
+
 def _client_timeout(timeout):
-    """httpx.Timeout with the caller's read timeout (default 900s) and a 10s connect."""
-    from httpx import Timeout
+    """httpx.Timeout with the caller's read timeout (default 900s) and a 10s connect.
+    Timeout comes from the SDK's own httpx flavour (see ``_sdk_httpx``)."""
+    Timeout = _sdk_httpx().Timeout
     read = timeout if (isinstance(timeout, (int, float)) and timeout > 0) else 900.0
     return Timeout(timeout=float(read), connect=10.0)
 
@@ -414,7 +442,7 @@ def _build_anthropic_client_with_bearer_hook(
     # auth header follows each mint, the OAuth identity below the first one: a key_cmd switching
     # between OAuth and a Console key mid-session needs a client rebuild.
     kwargs["http_client"] = build_bearer_http_client(
-        token_provider, timeout=kwargs["timeout"],
+        token_provider, httpx_mod=_sdk_httpx(), timeout=kwargs["timeout"],
         sends_as_api_key=(lambda token: not _is_oauth_token(token)) if is_native_anthropic_host(base_url) else None,
     )
     kwargs["auth_token"] = "entra-id-bearer-via-http-hook"
