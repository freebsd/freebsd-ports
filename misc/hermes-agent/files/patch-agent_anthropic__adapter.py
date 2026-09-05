--- agent/anthropic_adapter.py.orig	2026-09-05 11:43:11 UTC
+++ agent/anthropic_adapter.py
@@ -560,6 +560,34 @@ def _common_betas_for_base_url(
     return betas
 
 
+_SDK_HTTPX_MOD = None
+
+
+def _sdk_httpx():
+    """Return the httpx module the installed anthropic SDK is built against.
+
+    anthropic 1.x moved its HTTP stack to ``httpx2``; objects crossing the SDK
+    boundary (``Timeout``, ``http_client``) must come from the same module or
+    the SDK rejects them at request time.  Same split as
+    ``tools/mcp_tool.py:sdk_httpx()`` handles for mcp 1.x/2.x.
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
 def _build_anthropic_client_with_bearer_hook(
     token_provider,
     base_url: str = None,
@@ -592,7 +620,7 @@ def _build_anthropic_client_with_bearer_hook(
 
     normalize_proxy_env_vars()
 
-    from httpx import Timeout
+    Timeout = _sdk_httpx().Timeout
     from agent.azure_identity_adapter import build_bearer_http_client
 
     _read_timeout = timeout if (isinstance(timeout, (int, float)) and timeout > 0) else 900.0
@@ -604,7 +632,9 @@ def _build_anthropic_client_with_bearer_hook(
         import re as _re
         normalized_base_url = _re.sub(r"/v1/?$", "", normalized_base_url.rstrip("/"))
 
-    http_client = build_bearer_http_client(token_provider, timeout=timeout_obj)
+    http_client = build_bearer_http_client(
+        token_provider, httpx_mod=_sdk_httpx(), timeout=timeout_obj
+    )
 
     kwargs = {
         "timeout": timeout_obj,
@@ -691,7 +721,7 @@ def build_anthropic_client(
 
     normalize_proxy_env_vars()
 
-    from httpx import Timeout
+    Timeout = _sdk_httpx().Timeout
 
     normalized_base_url = _normalize_base_url_text(base_url)
     if normalized_base_url:
@@ -823,7 +853,7 @@ def build_anthropic_bedrock_client(region: str):
             "anthropic.AnthropicBedrock not available. "
             "Upgrade with: pip install 'anthropic>=0.39.0'"
         )
-    from httpx import Timeout
+    Timeout = _sdk_httpx().Timeout
 
     return _anthropic_sdk.AnthropicBedrock(
         aws_region=region,
