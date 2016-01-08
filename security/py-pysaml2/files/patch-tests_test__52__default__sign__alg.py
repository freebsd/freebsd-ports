--- tests/test_52_default_sign_alg.py.orig	2015-12-23 21:15:07 UTC
+++ tests/test_52_default_sign_alg.py
@@ -8,7 +8,8 @@ from saml2.samlp import response_from_st
 from saml2.server import Server
 from saml2 import client
 from saml2 import config
-from mock.mock import Mock, MagicMock
+# mock.mock seems to rely on pre-2.7 packaging
+from mock import Mock, MagicMock
 import saml2.xmldsig as ds
 
 nid = NameID(name_qualifier="foo", format=NAMEID_FORMAT_TRANSIENT,
