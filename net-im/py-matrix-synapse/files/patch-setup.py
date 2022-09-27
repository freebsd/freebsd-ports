--- setup.py.orig	1970-01-01 00:00:00 UTC
+++ setup.py
@@ -149,7 +149,7 @@ install_requires = \
  'bcrypt>=3.1.7',
  'bleach>=1.4.3',
  'canonicaljson>=1.5.0,<2.0.0',
- 'cryptography>=3.4.7',
+ 'cryptography',
  'frozendict>=1,!=2.1.2',
  'ijson>=3.1.4',
  'jsonschema>=3.0.0',
@@ -165,7 +165,6 @@ install_requires = \
  'pydantic>=1.7.4',
  'pymacaroons>=0.13.0',
  'service-identity>=18.1.0',
- 'setuptools_rust>=1.3',
  'signedjson>=1.1.0,<2.0.0',
  'sortedcontainers>=1.4.4',
  'treq>=15.1',
