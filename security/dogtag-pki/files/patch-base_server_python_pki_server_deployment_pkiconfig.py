--- base/server/python/pki/server/deployment/pkiconfig.py.orig	2025-08-05 19:20:05 UTC
+++ base/server/python/pki/server/deployment/pkiconfig.py
@@ -47,7 +47,7 @@ PKI_DEPLOYMENT_INTERRUPT_BANNER = "-+-+-+-+-+-+-+-+-+-
 PKI_DEPLOYMENT_INTERRUPT_BANNER = "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"\
                                   "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"
 
-PKI_DEPLOYMENT_SOURCE_ROOT = "/usr/share/pki"
+PKI_DEPLOYMENT_SOURCE_ROOT = "/usr/local/share/pki"
 # NOTE: Top-level "/etc/pki" is owned by the "filesystem" package!
 PKI_DEPLOYMENT_CONFIGURATION_ROOT = "/etc/pki"
 PKI_DEPLOYMENT_LOG_ROOT = "/var/log/pki"
