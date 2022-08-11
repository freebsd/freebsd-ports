--- setup.py.orig	2022-08-02 13:44:06 UTC
+++ setup.py
@@ -149,7 +149,7 @@ install_requires = \
  'bcrypt>=3.1.0',
  'bleach>=1.4.3',
  'canonicaljson>=1.5.0,<2.0.0',
- 'cryptography>=3.4.7',
+ 'cryptography',
  'frozendict>=1,!=2.1.2',
  'ijson>=3.1.4',
  'jsonschema>=3.0.0',
