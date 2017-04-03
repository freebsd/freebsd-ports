--- eventlet/support/greendns.py.orig	2017-03-29 21:00:19 UTC
+++ eventlet/support/greendns.py
@@ -79,8 +79,14 @@ DNS_QUERY_TIMEOUT = 10.0
 HOSTS_TTL = 10.0
 
 EAI_EAGAIN_ERROR = socket.gaierror(socket.EAI_AGAIN, 'Lookup timed out')
-EAI_NODATA_ERROR = socket.gaierror(socket.EAI_NODATA, 'No address associated with hostname')
 EAI_NONAME_ERROR = socket.gaierror(socket.EAI_NONAME, 'Name or service not known')
+# EAI_NODATA was removed from RFC3493, it's now replaced with EAI_NONAME
+# socket.EAI_NODATA is not defined on FreeBSD, probably on some other platforms too.
+# https://lists.freebsd.org/pipermail/freebsd-ports/2003-October/005757.html
+EAI_NODATA_ERROR = EAI_NONAME_ERROR
+if (os.environ.get('EVENTLET_DEPRECATED_EAI_NODATA', '').lower() in ('1', 'y', 'yes')
+        and hasattr(socket, 'EAI_NODATA')):
+    EAI_NODATA_ERROR = socket.gaierror(socket.EAI_NODATA, 'No address associated with hostname')
 
 
 def is_ipv4_addr(host):
@@ -448,7 +454,7 @@ def _getaddrinfo_lookup(host, family, fl
             try:
                 answer = resolve(host, qfamily, False)
             except socket.gaierror as e:
-                if e.errno not in (socket.EAI_AGAIN, socket.EAI_NODATA):
+                if e.errno not in (socket.EAI_AGAIN, EAI_NONAME_ERROR.errno, EAI_NODATA_ERROR.errno):
                     raise
                 err = e
             else:
