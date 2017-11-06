From 8d1228cd1943bfe89ffaae32e15b2feb3f8479f5 Mon Sep 17 00:00:00 2001
From: Cory Benfield <lukasaoz@gmail.com>
Date: Thu, 20 Jul 2017 10:08:50 +0100
Subject: [PATCH] Allow urllib3 1.22

---
 setup.py | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)

# pytest-cov and its dependencies are not compulsory

--- setup.py.orig	2017-06-14 17:44:15 UTC
+++ setup.py
@@ -44,11 +44,11 @@ packages = ['requests']
 requires = [
     'chardet>=3.0.2,<3.1.0',
     'idna>=2.5,<2.6',
-    'urllib3>=1.21.1,<1.22',
+    'urllib3>=1.21.1,<1.23',
     'certifi>=2017.4.17'
 
 ]
-test_requirements = ['pytest-httpbin==0.0.7', 'pytest-cov', 'pytest-mock', 'pytest-xdist', 'PySocks>=1.5.6, !=1.5.7', 'pytest>=2.8.0']
+test_requirements = ['pytest-httpbin==0.0.7', 'pytest-mock', 'pytest-xdist', 'PySocks>=1.5.6, !=1.5.7', 'pytest>=2.8.0']
 
 about = {}
 with open(os.path.join(here, 'requests', '__version__.py'), 'r', 'utf-8') as f:
