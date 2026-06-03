Obtained from:	https://github.com/Azure/azure-cli/commit/c8b2de89e8b77aeee5908b5d2623a65bd36f9ebf

--- setup.py.orig	2023-07-27 07:10:05 UTC
+++ setup.py
@@ -40,7 +40,7 @@ setup(
     classifiers=CLASSIFIERS,
     install_requires=[
         'applicationinsights>=0.11.1,<0.12',
-        'portalocker>=1.6,<3',
+        'portalocker>=1.6,<4',
     ],
     packages=[
         'azure.cli.telemetry',
