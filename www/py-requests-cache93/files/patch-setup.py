--- setup.py.orig	2025-10-09 14:35:58 UTC
+++ setup.py
@@ -12,11 +12,11 @@ install_requires = \
 
 install_requires = \
 ['appdirs>=1.4.4,<2.0.0',
- 'attrs>=21.2,<22.0',
+ 'attrs>=21.2',
  'cattrs>=1.8,<23.3',
  'requests>=2.22,<3.0',
  'url-normalize>=1.4,<2.0',
- 'urllib3>=1.25.5,<2.0.0']
+ 'urllib3>=1.25.5,<3.0.0']
 
 extras_require = \
 {'all': ['boto3>=1.15,<2.0',
