Description: Make the crypt import optional; crypt was removed in Python
  3.13.  Without it the 'crypt' userPassword scheme is not offered (it is
  dropped from AVAIL_USERPASSWORD_SCHEMES, which the scheme menus and the
  passwd_hashtypes setting are built from); the hashlib-based schemes are
  unaffected.
Issue ID: none (upstream inactive)
Changeset: none
TODO: Drop once a release no longer imports crypt.

--- web2ldap/ldaputil/passwd.py.orig	2022-01-10 16:14:39 UTC
+++ web2ldap/ldaputil/passwd.py
@@ -14,9 +14,14 @@ https://www.apache.org/licenses/LICENSE-
 
 import base64
 import hashlib
-import crypt
 import secrets
 
+try:
+    import crypt
+except ImportError:
+    # removed in Python 3.13: the 'crypt' scheme is not offered there
+    crypt = None
+
 from ldap0.pw import random_string, PWD_UNIX_CRYPT_ALPHABET
 
 AVAIL_USERPASSWORD_SCHEMES = {
@@ -33,6 +38,8 @@ AVAIL_USERPASSWORD_SCHEMES = {
     'ssha512': 'salted SHA-512',
     '': 'plain text',
 }
+if crypt is None:
+    del AVAIL_USERPASSWORD_SCHEMES['crypt']
 
 
 SALTED_USERPASSWORD_SCHEMES = {
