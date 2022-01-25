--- setup.py.orig	2021-12-18 09:30:38 UTC
+++ setup.py
@@ -16,7 +16,6 @@ setup(
     long_description_content_type='text/x-rst',
     keywords=['apscheduler', 'scheduler', 'scheduling', 'cron'],
     install_requires=['flask>=0.10.1', 'apscheduler>=3.2.0,<4.0.0', 'python-dateutil>=2.4.2'],
-    package_data={'Flask-APScheduler': ['LICENSE']},
     include_package_data=True,
     classifiers=[
         'Development Status :: 5 - Production/Stable',
