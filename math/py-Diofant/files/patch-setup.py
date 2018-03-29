--- setup.py.orig	2018-03-29 22:06:10 UTC
+++ setup.py
@@ -20,7 +20,7 @@ with open('diofant/__init__.py') as f:
         if m:
             __version__ = m.group(1)
 
-setup_reqs = ['setuptools>=5.5.1', 'pip>=6.0', 'pytest-runner', 'isort']
+setup_reqs = ['setuptools>=5.5.1', 'pytest-runner', 'isort']
 extra_reqs = {'exports': ['numpy>=1.12.1', 'scipy', 'Theano>=0.9.0'],
               'gmpy': ['gmpy2>=2.0.8'],
               'plot': ['pyparsing!=2.1.2', 'matplotlib!=2.1.1'],
