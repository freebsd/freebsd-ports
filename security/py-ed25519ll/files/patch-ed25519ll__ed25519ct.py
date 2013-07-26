--- ./ed25519ll/ed25519ct.py.orig	2013-07-26 11:26:29.000000000 +0200
+++ ./ed25519ll/ed25519ct.py	2013-07-26 11:26:43.000000000 +0200
@@ -15,9 +15,8 @@
 __all__ = ['crypto_sign', 'crypto_sign_open', 'crypto_sign_keypair', 'Keypair',
            'PUBLICKEYBYTES', 'SECRETKEYBYTES', 'SIGNATUREBYTES']
 
-plat_name = get_platform().replace('-', '_')
 so_suffix = sysconfig.get_config_var('SO')
-lib_filename = '_ed25519_%s%s' % (plat_name, so_suffix)
+lib_filename = '_ed25519%s' % (so_suffix)
 
 try:
     _ed25519 = ctypes.cdll.LoadLibrary(
