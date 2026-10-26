--- agent/azure_identity_adapter.py.orig	2026-10-26 16:08:51 UTC
+++ agent/azure_identity_adapter.py
@@ -311,16 +311,23 @@
 
 
 def build_bearer_http_client(
-    token_provider: Callable[[], str], *, sends_as_api_key: Callable[[str], bool] | None = None, **httpx_kwargs: Any
+    token_provider: Callable[[], str], *, httpx_mod: Any = None,
+    sends_as_api_key: Callable[[str], bool] | None = None, **httpx_kwargs: Any
 ) -> Any:
     """``httpx.Client`` minting a fresh Entra bearer JWT per outbound request. The Anthropic SDK computes
     ``Authorization`` once at construction, so per-request refresh needs a ``request`` hook: mint (cheap —
     azure-identity caches), strip pre-set auth headers, set ``Authorization: Bearer``. ``httpx_kwargs`` are
     forwarded verbatim (``timeout``, ``transport``...). ``sends_as_api_key(token)`` True puts the minted
-    token in ``x-api-key`` instead (a ``key_cmd`` printing a native Anthropic Console key)."""
+    token in ``x-api-key`` instead (a ``key_cmd`` printing a native Anthropic Console key).
+
+    ``httpx_mod`` lets the caller pass the httpx flavour its SDK is built against (anthropic 1.x
+    vendors ``httpx2``); the client object must come from that same module or the SDK rejects it.
+    Defaults to plain ``httpx``."""
     if not is_token_provider(token_provider):
         raise ValueError("build_bearer_http_client requires a zero-arg callable token provider")
-    import httpx
+    if httpx_mod is None:
+        import httpx as httpx_mod  # type: ignore[no-redef]
+    httpx = httpx_mod
 
     def _inject_auth(request: httpx.Request) -> None:
         try:
