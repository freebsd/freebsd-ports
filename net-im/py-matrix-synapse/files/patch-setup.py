--- setup.py.orig	1970-01-01 00:00:00 UTC
+++ setup.py
@@ -154,8 +154,8 @@ install_requires = \
  'bcrypt>=3.1.7',
  'bleach>=1.4.3',
  'canonicaljson>=1.5.0,<2.0.0',
- 'cryptography>=3.4.7',
- 'frozendict>=1,!=2.1.2,<2.3.5',
+ 'cryptography',
+ 'frozendict>=1',
  'ijson>=3.1.4',
  'jsonschema>=3.0.0',
  'matrix-common>=1.3.0,<2.0.0',
@@ -170,7 +170,6 @@ install_requires = \
  'pydantic>=1.7.4',
  'pymacaroons>=0.13.0',
  'service-identity>=18.1.0',
- 'setuptools_rust>=1.3',
  'signedjson>=1.1.0,<2.0.0',
  'sortedcontainers>=1.5.2',
  'treq>=15.1',
