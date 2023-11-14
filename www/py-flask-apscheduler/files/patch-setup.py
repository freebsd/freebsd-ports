--- setup.py.orig	2023-11-07 12:41:21 UTC
+++ setup.py
@@ -17,7 +17,6 @@ setup(
     keywords=["apscheduler", "scheduler", "scheduling", "cron"],
     python_requires=">=3.8",
     install_requires=["flask>=2.2.5,<4.0.0", "apscheduler>=3.2.0,<4.0.0", "python-dateutil>=2.4.2"],
-    package_data={"Flask-APScheduler": ["LICENSE"]},
     include_package_data=True,
     classifiers=[
         "Development Status :: 5 - Production/Stable",
