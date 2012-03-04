--- requests/models.py.orig	2011-12-28 09:56:17.000000000 +0100
+++ requests/models.py	2012-01-12 17:54:01.000000000 +0100
@@ -19,12 +19,12 @@
 from .status_codes import codes
 from .packages import oreos
 from .auth import HTTPBasicAuth, HTTPProxyAuth
-from .packages.urllib3.response import HTTPResponse
-from .packages.urllib3.exceptions import MaxRetryError
-from .packages.urllib3.exceptions import SSLError as _SSLError
-from .packages.urllib3.exceptions import HTTPError as _HTTPError
-from .packages.urllib3 import connectionpool, poolmanager
-from .packages.urllib3.filepost import encode_multipart_formdata
+from urllib3.response import HTTPResponse
+from urllib3.exceptions import MaxRetryError
+from urllib3.exceptions import SSLError as _SSLError
+from urllib3.exceptions import HTTPError as _HTTPError
+from urllib3 import connectionpool, poolmanager
+from urllib3.filepost import encode_multipart_formdata
 from .exceptions import (
     ConnectionError, HTTPError, RequestException, Timeout, TooManyRedirects,
     URLRequired, SSLError)
