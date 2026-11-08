-- Fix _is_localhost to not treat 0.0.0.0 from DNS as localhost.
-- On FreeBSD, socket.gethostbyname() returns "0.0.0.0" for NXDOMAIN instead of
-- raising socket.gaierror, causing non-existent domains to be misidentified as
-- localhost. The 0.0.0.0 case is already handled by the _LOCALHOST_NAMES check
-- above when it appears as a URL hostname, so the DNS resolution check for
-- 0.0.0.0 is unnecessary and harmful on FreeBSD.
--- src/langsmith/utils.py.orig	2026-10-18 22:15:42 UTC
+++ src/langsmith/utils.py
@@ -837,7 +837,7 @@ def _is_localhost(url: str) -> bool:
         if netloc in _LOCALHOST_NAMES:
             return True
         ip = socket.gethostbyname(netloc)
-        return ip == "127.0.0.1" or ip.startswith("0.0.0.0") or ip.startswith("::")
+        return ip == "127.0.0.1" or ip.startswith("::")
     except (socket.gaierror, RuntimeError):
         # RuntimeError catches pytest-socket's SocketBlockedError in test environments
         return False
