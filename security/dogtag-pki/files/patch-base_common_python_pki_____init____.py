--- base/common/python/pki/__init__.py.orig	2026-07-28 16:37:15 UTC
+++ base/common/python/pki/__init__.py
@@ -37,8 +37,8 @@ import requests
 import requests
 
 
-CONF_DIR = '/etc/pki'
-SHARE_DIR = '/usr/share/pki'
+CONF_DIR = '/usr/local/etc/pki'
+SHARE_DIR = '/usr/local/share/pki'
 BASE_DIR = '/var/lib'
 LOG_DIR = '/var/log/pki'
 
