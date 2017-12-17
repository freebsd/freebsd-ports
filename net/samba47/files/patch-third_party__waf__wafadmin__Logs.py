--- third_party/waf/wafadmin/Logs.py.orig	2017-07-04 10:05:26 UTC
+++ third_party/waf/wafadmin/Logs.py
@@ -23,6 +23,9 @@ colors_lst = {
 'cursor_off' :'\x1b[?25l',
 }
 
+WAF_LOG_FORMAT = os.environ.get('WAF_LOG_FORMAT', LOG_FORMAT)
+WAF_HOUR_FORMAT = os.environ.get('WAF_HOUR_FORMAT', HOUR_FORMAT)
+
 got_tty = False
 term = os.environ.get('TERM', 'dumb')
 if not term in ['dumb', 'emacs']:
@@ -84,7 +87,7 @@ class log_filter(logging.Filter):
 
 class formatter(logging.Formatter):
 	def __init__(self):
-		logging.Formatter.__init__(self, LOG_FORMAT, HOUR_FORMAT)
+		logging.Formatter.__init__(self, WAF_LOG_FORMAT, WAF_HOUR_FORMAT)
 
 	def format(self, rec):
 		if rec.levelno >= logging.WARNING or rec.levelno == logging.INFO:
