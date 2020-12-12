--- tls/datadog_checks/tls/tls.py.orig	2020-10-29 10:25:06 UTC
+++ tls/datadog_checks/tls/tls.py
@@ -294,7 +294,7 @@ class TLSCheck(AgentCheck):
                 raise socket.error('No valid addresses found, try checking your IPv6 connectivity')  # noqa: G
         except socket.gaierror as e:
             err_code, message = e.args
-            if err_code == socket.EAI_NODATA or err_code == socket.EAI_NONAME:
+            if err_code == socket.EAI_NONAME:
                 raise socket.error('Unable to resolve host, check your DNS: {}'.format(message))  # noqa: G

             raise
