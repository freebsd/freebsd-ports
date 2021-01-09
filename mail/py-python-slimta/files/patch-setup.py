--- setup.py.orig	2021-01-08 23:33:01 UTC
+++ setup.py
@@ -40,7 +40,7 @@ setup(name='python-slimta',
       packages=find_packages(),
       namespace_packages=['slimta'],
       install_requires=['gevent >= 1.1rc',
-                        'pysasl >= 0.4.0, < 0.5',
+                        'pysasl >= 0.4.0',
                         'pycares < 3.0.0; python_version < "3.0"',
                         'pycares >= 1; python_version >= "3.0"'],
       extras_require={'spf': ['pyspf', 'py3dns; python_version >= "3.0"',
