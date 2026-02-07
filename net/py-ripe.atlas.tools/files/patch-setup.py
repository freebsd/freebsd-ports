--- setup.py.orig	2025-04-05 17:55:07 UTC
+++ setup.py
@@ -47,12 +47,6 @@ setup(
         "fast": ["ujson"],
     },
     scripts=[
-        "scripts/aping",
-        "scripts/atraceroute",
-        "scripts/adig",
-        "scripts/asslcert",
-        "scripts/ahttp",
-        "scripts/antp",
         "scripts/ripe-atlas",
     ],
     keywords=["RIPE", "RIPE NCC", "RIPE Atlas", "Command Line"],
@@ -65,6 +59,7 @@ setup(
         "Programming Language :: Python :: 3.8",
         "Programming Language :: Python :: 3.9",
         "Programming Language :: Python :: 3.10",
+        "Programming Language :: Python :: 3.11",
         "Topic :: Internet :: WWW/HTTP",
     ],
 )
