--- setup.py.orig	2019-11-12 12:54:56 UTC
+++ setup.py
@@ -23,19 +23,19 @@ setuptools.setup(
         # This list must be kept in sync with requirements.txt version-wise,
         # but should not include packages used for testing, generating docs
         # or packages.
-        'python-gnupg==0.4.4',
-        'passlib==1.7.1',
-        'IPy==1.0.0',
-        'dataclasses==0.6',
-        'ordered-set==3.1.1',
-        'dotted==0.1.8',
-        'beautifultable==0.7.0',
-        'PyYAML==5.1',
-        'psycopg2-binary==2.8.2',
-        'SQLAlchemy==1.3.3',
-        'alembic==1.0.10',
-        'ujson==1.35',
-        'twisted==19.2.1',
+        'python-gnupg>=0.4.3',
+        'passlib>=1.7.1',
+        'IPy>=1.0.0',
+        'dataclasses==0.6; python_version<"3.7"',
+        'ordered-set>=3.1.1',
+        'dotted>=0.1.8',
+        'beautifultable>=0.7.0',
+        'PyYAML>=5.1',
+        'psycopg2>=2.8.2',
+        'SQLAlchemy>=1.2.19',
+        'alembic>=1.0.10',
+        'ujson>=1.35',
+        'twisted>=18.9.0',
     ],
     entry_points={
         'console_scripts': [
