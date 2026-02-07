--- setup.py.orig	2023-11-07 12:41:21 UTC
+++ setup.py
@@ -4,7 +4,7 @@ setup(
     long_description = fh.read()
 
 setup(
-    name="Flask-APScheduler",
+    name="flask-apscheduler",
     version="1.13.1",
     packages=["flask_apscheduler"],
     url="https://github.com/viniciuschiele/flask-apscheduler",
@@ -17,7 +17,6 @@ setup(
     keywords=["apscheduler", "scheduler", "scheduling", "cron"],
     python_requires=">=3.8",
     install_requires=["flask>=2.2.5,<4.0.0", "apscheduler>=3.2.0,<4.0.0", "python-dateutil>=2.4.2"],
-    package_data={"Flask-APScheduler": ["LICENSE"]},
     include_package_data=True,
     classifiers=[
         "Development Status :: 5 - Production/Stable",
