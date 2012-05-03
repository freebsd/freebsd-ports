--- requests/models.py.orig	2012-04-23 04:13:53.000000000 +0200
+++ requests/models.py	2012-04-23 18:22:55.000000000 +0200
@@ -15,12 +15,12 @@
 from .status_codes import codes
 
 from .auth import HTTPBasicAuth, HTTPProxyAuth
-from .packages.urllib3.response import HTTPResponse
-from .packages.urllib3.exceptions import MaxRetryError, LocationParseError
-from .packages.urllib3.exceptions import SSLError as _SSLError
-from .packages.urllib3.exceptions import HTTPError as _HTTPError
-from .packages.urllib3 import connectionpool, poolmanager
-from .packages.urllib3.filepost import encode_multipart_formdata
+from urllib3.response import HTTPResponse
+from urllib3.exceptions import MaxRetryError, LocationParseError
+from urllib3.exceptions import SSLError as _SSLError
+from urllib3.exceptions import HTTPError as _HTTPError
+from urllib3 import connectionpool, poolmanager
+from urllib3.filepost import encode_multipart_formdata
 from .defaults import SCHEMAS
 from .exceptions import (
     ConnectionError, HTTPError, RequestException, Timeout, TooManyRedirects,
