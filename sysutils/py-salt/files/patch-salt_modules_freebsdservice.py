--- salt/modules/freebsdservice.py.orig	2017-08-15 15:26:36 UTC
+++ salt/modules/freebsdservice.py
@@ -16,7 +16,6 @@ import os
 
 # Import salt libs
 import salt.utils
-import salt.utils.decorators as decorators
 from salt.exceptions import CommandNotFoundError
 
 __func_alias__ = {
@@ -39,7 +38,6 @@ def __virtual__():
     return (False, 'The freebsdservice execution module cannot be loaded: only available on FreeBSD systems.')
 
 
-@decorators.memoize
 def _cmd(jail=None):
     '''
     Return full path to service command
