--- base/common/python/pki/__init__.py.orig	2025-08-05 19:20:05 UTC
+++ base/common/python/pki/__init__.py
@@ -40,8 +40,8 @@ import requests
 import six
 
 
-CONF_DIR = '/etc/pki'
-SHARE_DIR = '/usr/share/pki'
+CONF_DIR = '/usr/local/etc/pki'
+SHARE_DIR = '/usr/local/share/pki'
 BASE_DIR = '/var/lib'
 LOG_DIR = '/var/log/pki'
 
