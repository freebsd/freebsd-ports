--- setup.py.orig	2019-08-08 10:01:14 UTC
+++ setup.py
@@ -14,7 +14,7 @@ setup(
     author_email="maic@siemering.tech",
     license="MIT",
     description="A python package for the V2 CF Service Broker API and Open Broker API (version 2.13+)",
-    long_description=open('README.rst').read(),
+    long_description=open('README.rst', encoding="utf-8").read(),
     url="https://github.com/eruvanos/openbrokerapi",
     keywords=["cloudfoundry", "cfbrokerapi", "openbrokerapi", "openservicebrokerapi", "servicebroker", "flask"],
     classifiers=[
