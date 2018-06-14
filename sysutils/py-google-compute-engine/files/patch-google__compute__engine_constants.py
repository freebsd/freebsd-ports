--- google_compute_engine/constants.py.orig	2018-06-11 23:51:09 UTC
+++ google_compute_engine/constants.py
@@ -18,7 +18,7 @@
 import platform
 
 OSLOGIN_CONTROL_SCRIPT = 'google_oslogin_control'
-OSLOGIN_NSS_CACHE = '/etc/oslogin_passwd.cache'
+OSLOGIN_NSS_CACHE = '/usr/local/etc/oslogin_passwd.cache'
 OSLOGIN_NSS_CACHE_SCRIPT = 'google_oslogin_nss_cache'
 
 if platform.system() == 'FreeBSD':
