--- ./setup.py.orig	2013-07-26 11:26:23.000000000 +0200
+++ ./setup.py	2013-07-26 11:27:07.000000000 +0200
@@ -10,8 +10,6 @@
 README = open(os.path.join(here, 'README.txt')).read()
 CHANGES = open(os.path.join(here, 'CHANGES.txt')).read()
 
-plat_name = get_platform().replace('-', '_')
-
 setup(name='ed25519ll',
       version='0.6',
       description='A low-level ctypes wrapper for Ed25519 digital signatures.',
@@ -33,7 +31,7 @@
       tests_require=['nose'],
       test_suite='nose.collector',
       ext_modules=[
-               Extension('ed25519ll._ed25519_%s' % plat_name,
+               Extension('ed25519ll._ed25519',
                          sources=[
                              'ed25519-supercop-ref10/ge_frombytes.c',
                              'ed25519-supercop-ref10/fe_frombytes.c',
