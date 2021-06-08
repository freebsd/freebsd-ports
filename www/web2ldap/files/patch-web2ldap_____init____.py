--- web2ldap/__init__.py.orig	2021-05-14 15:57:24 UTC
+++ web2ldap/__init__.py
@@ -20,21 +20,13 @@ import time
 from .log import logger, LogHelper
 from .__about__ import __version__
 
-# prefixes considered to indicate system-wide installation outside a venv
-OS_SYS_PREFIXES = {
-    '/usr',
-    '/usr/local',
-}
-
 # Path name of [web2ldap]/etc/web2ldap
 if 'WEB2LDAP_HOME' in os.environ:
     # env var points to web2ldap root directory
     ETC_DIR = os.path.join(os.environ['WEB2LDAP_HOME'], 'etc', 'web2ldap')
-elif os.name == 'posix' and sys.prefix in OS_SYS_PREFIXES:
-    # assume OS-wide installation on POSIX platform (Linux, BSD, etc.)
-    ETC_DIR = '/etc/web2ldap'
 else:
-    # virtual env
+    # assume OS-wide installation on POSIX platform (Linux, BSD, etc.)
+    # or virtual env
     ETC_DIR = os.path.join(sys.prefix, 'etc', 'web2ldap')
 sys.path.append(ETC_DIR)
 
