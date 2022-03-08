https://github.com/Trim21/transmission-rpc/commit/af38c4faf685
https://github.com/Trim21/transmission-rpc/commit/9dafcea404b9

--- setup.py.orig	2021-09-29 06:26:44 UTC
+++ setup.py
@@ -8,7 +8,7 @@ package_data = \
 {'': ['*']}
 
 install_requires = \
-['requests>=2.23.0,<3.0.0', 'typing_extensions>=3.7.4.2,<4.0.0.0']
+['requests>=2.23.0,<3.0.0', 'typing_extensions>=3.7.4.2,<4.2.0.0']
 
 extras_require = \
 {'docs': ['sphinx==4.2.0', 'sphinx-rtd-theme==1.0.0']}
