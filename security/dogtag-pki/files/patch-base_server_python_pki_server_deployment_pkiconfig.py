--- base/server/python/pki/server/deployment/pkiconfig.py.orig	2026-07-28 16:37:15 UTC
+++ base/server/python/pki/server/deployment/pkiconfig.py
@@ -44,7 +44,7 @@ PKI_DEPLOYMENT_INTERRUPT_BANNER = "-+-+-+-+-+-+-+-+-+-
 PKI_DEPLOYMENT_INTERRUPT_BANNER = "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"\
                                   "-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-"
 
-PKI_DEPLOYMENT_SOURCE_ROOT = "/usr/share/pki"
+PKI_DEPLOYMENT_SOURCE_ROOT = "/usr/local/share/pki"
 # NOTE: Top-level "/etc/pki" is owned by the "filesystem" package!
 PKI_DEPLOYMENT_CONFIGURATION_ROOT = "/etc/pki"
 # NOTE:  Well-known 'registry root', default 'instance', and default
