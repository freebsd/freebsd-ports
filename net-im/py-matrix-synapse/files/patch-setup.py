--- setup.py.orig	2022-06-28 16:27:08 UTC
+++ setup.py
@@ -147,7 +147,7 @@ install_requires = \
  'bcrypt>=3.1.0',
  'bleach>=1.4.3',
  'canonicaljson>=1.4.0',
- 'cryptography>=3.4.7',
+ 'cryptography',
  'frozendict>=1,!=2.1.2',
  'ijson>=3.1.4',
  'jsonschema>=3.0.0',
