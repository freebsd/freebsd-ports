--- puppetboard/app.py.orig	2017-10-16 10:44:29 UTC
+++ puppetboard/app.py
@@ -25,7 +25,7 @@ from puppetboard.utils import (get_or_abort, yield_or_
 from puppetboard.dailychart import get_daily_reports_chart
 
 import werkzeug.exceptions as ex
-import CommonMark
+import commonmark
 
 from puppetboard.core import get_app, get_puppetdb, environments
 import puppetboard.errors
@@ -546,7 +546,7 @@ def report(env, node_name, report_id):
     except StopIteration:
         abort(404)
 
-    report.version = CommonMark.commonmark(report.version)
+    report.version = commonmark.commonmark(report.version)
 
     return render_template(
         'report.html',
