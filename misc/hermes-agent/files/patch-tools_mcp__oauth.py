--- tools/mcp_oauth.py.orig	2026-11-17 09:39:49 UTC
+++ tools/mcp_oauth.py
@@ -727,7 +727,7 @@ def _make_callback_handler() -> tuple[type, dict]:
     return _Handler, result
 
 
-def _paste_callback_reader(result: dict, lock: threading.Lock | None = None) -> None:
+def _paste_callback_reader(result: dict, lock: "threading.Lock | None" = None) -> None:
     """Read one stdin line as an OAuth redirect (full URL, bare query, or a ``_SKIP_TOKENS`` word that
     exits without auth) into *result*. Parse failures, EOF and interrupts are swallowed — best-effort
     fallback racing the HTTP listener, which stays primary. *lock* is the flow's handler ``result_lock``."""
