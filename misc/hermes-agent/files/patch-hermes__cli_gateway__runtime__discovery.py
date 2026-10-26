--- hermes_cli/gateway_runtime_discovery.py.orig	2026-10-26 21:56:11 UTC
+++ hermes_cli/gateway_runtime_discovery.py
@@ -109,7 +109,8 @@ def socket_peer_uid(sock: socket.socket) -> int | None
     if hasattr(socket, "SO_PEERCRED"):
         import struct
         return struct.unpack("3i", sock.getsockopt(socket.SOL_SOCKET, socket.SO_PEERCRED, 12))[1]
-    if sys.platform != "darwin":
+    # FreeBSD libc has getpeereid(3) too.
+    if sys.platform != "darwin" and not sys.platform.startswith("freebsd"):
         return None
     import ctypes
     uid, gid = ctypes.c_uint(), ctypes.c_uint()
