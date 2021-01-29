--- web2ldap/app/core.py.orig	2020-05-04 11:51:59 UTC
+++ web2ldap/app/core.py
@@ -19,12 +19,6 @@ import time
 import web2ldap.__about__
 from web2ldap.log import logger
 
-# prefixes considered to indicate system-wide installation outside a venv
-OS_SYS_PREFIXES = {
-    '/usr',
-    '/usr/local',
-}
-
 logger.info('Starting web2ldap %s', web2ldap.__about__.__version__)
 # this has to be done before import module package ldap0
 os.environ['LDAPNOINIT'] = '1'
@@ -39,11 +33,9 @@ check_inst()
 if 'WEB2LDAP_HOME' in os.environ:
     # env var points to web2ldap root directory
     etc_dir = os.path.join(os.environ['WEB2LDAP_HOME'], 'etc', 'web2ldap')
-elif os.name == 'posix' and sys.prefix in OS_SYS_PREFIXES:
-    # assume OS-wide installation on POSIX platform (Linux, BSD, etc.)
-    etc_dir = '/etc/web2ldap'
 else:
-    # virtual env
+    # assume OS-wide installation on POSIX platform (Linux, BSD, etc.)
+    # or virtual env
     etc_dir = os.path.join(sys.prefix, 'etc', 'web2ldap')
 
 # Default directory for [web2ldap]/etc/web2ldap/templates
