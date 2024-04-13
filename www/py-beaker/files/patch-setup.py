--- setup.py.orig	2024-04-13 11:48:38 UTC
+++ setup.py
@@ -54,7 +54,7 @@ if not sys.platform.startswith('java') and not sys.pla
     TESTS_REQUIRE.extend(['pylibmc', 'python-memcached'])
 
 
-setup(name='Beaker',
+setup(name='beaker',
       version=VERSION,
       description="A Session and Caching library with WSGI Middleware",
       long_description=README,
