--- requests/models.py.orig	2012-05-08 07:13:56.000000000 +0200
+++ requests/models.py	2012-05-19 13:33:03.000000000 +0200
@@ -17,12 +17,6 @@
 
 from .auth import HTTPBasicAuth, HTTPProxyAuth
 from .cookies import cookiejar_from_dict, extract_cookies_to_jar, get_cookie_header
-from .packages.urllib3.response import HTTPResponse
-from .packages.urllib3.exceptions import MaxRetryError, LocationParseError
-from .packages.urllib3.exceptions import SSLError as _SSLError
-from .packages.urllib3.exceptions import HTTPError as _HTTPError
-from .packages.urllib3 import connectionpool, poolmanager
-from .packages.urllib3.filepost import encode_multipart_formdata
 from .defaults import SCHEMAS
 from .exceptions import (
     ConnectionError, HTTPError, RequestException, Timeout, TooManyRedirects,
