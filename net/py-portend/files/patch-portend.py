--- portend.py.orig	2026-09-18 00:11:34 UTC
+++ portend.py
@@ -65,7 +65,7 @@ class Checker:
         """
         if port is None and isinstance(host, abc.Sequence):
             host, port = host[:2]
-        if platform.system() == 'Windows':
+        if platform.system() == 'Windows' or platform.system() == 'FreeBSD':
             host = client_host(host)  # pragma: nocover
         info = socket.getaddrinfo(host, port, socket.AF_UNSPEC, socket.SOCK_STREAM)
         list(itertools.starmap(self._connect, info))
