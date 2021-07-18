--- setup.py.orig	1970-01-01 00:00:00 UTC
+++ setup.py
@@ -15,7 +15,7 @@ package_data = \
 
 install_requires = \
 ['starlette ==0.14.2',
- 'pydantic >=1.6.2,!=1.7,!=1.7.1,!=1.7.2,!=1.7.3,!=1.8,!=1.8.1,<2.0.0']
+ 'pydantic >=1.6.2,<2.0.0']
 
 extras_require = \
 {'all': ['requests >=2.24.0,<3.0.0',
