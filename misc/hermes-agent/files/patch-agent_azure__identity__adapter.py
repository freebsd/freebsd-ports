--- agent/azure_identity_adapter.py.orig	2026-09-05 11:44:04 UTC
+++ agent/azure_identity_adapter.py
@@ -475,7 +475,12 @@ def materialize_bearer_for_http(value: Any) -> str:
     raise ValueError("no usable api_key / token provider")
 
 
-def build_bearer_http_client(token_provider: Callable[[], str], **httpx_kwargs: Any) -> Any:
+def build_bearer_http_client(
+    token_provider: Callable[[], str],
+    *,
+    httpx_mod: Any = None,
+    **httpx_kwargs: Any,
+) -> Any:
     """Return an ``httpx.Client`` that mints a fresh Entra bearer JWT
     per outbound request.
 
@@ -511,14 +516,19 @@ def build_bearer_http_client(token_provider: Callable[
             "token provider"
         )
 
-    try:
-        import httpx
-    except ImportError as exc:  # pragma: no cover — httpx ships with openai/anthropic
-        raise ImportError(
-            "httpx is required for Entra ID bearer auth on Microsoft Foundry "
-            "Anthropic-style endpoints. It is normally a transitive "
-            "dependency of the openai/anthropic SDKs."
-        ) from exc
+    # ``httpx_mod`` lets the caller pin the flavour its SDK expects: anthropic
+    # 1.x is on httpx2 while openai 2.x is still on httpx.  Defaults to httpx.
+    if httpx_mod is not None:
+        httpx = httpx_mod
+    else:
+        try:
+            import httpx
+        except ImportError as exc:  # pragma: no cover — httpx ships with openai/anthropic
+            raise ImportError(
+                "httpx is required for Entra ID bearer auth on Microsoft Foundry "
+                "Anthropic-style endpoints. It is normally a transitive "
+                "dependency of the openai/anthropic SDKs."
+            ) from exc
 
     def _inject_bearer(request: "httpx.Request") -> None:
         try:
