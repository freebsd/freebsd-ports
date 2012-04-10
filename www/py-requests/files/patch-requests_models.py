--- requests/models.py.orig	2012-03-09 17:51:20.000000000 +0100
+++ requests/models.py	2012-03-19 17:49:25.000000000 +0100
@@ -15,12 +15,12 @@
 from .status_codes import codes
 
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
 from .defaults import SCHEMAS
 from .exceptions import (
     ConnectionError, HTTPError, RequestException, Timeout, TooManyRedirects,
