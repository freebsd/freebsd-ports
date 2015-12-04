--- third_party/waf/wafadmin/Logs.py.orig	2015-07-21 09:47:50.000000000 +0000
+++ third_party/waf/wafadmin/Logs.py	2015-10-05 18:46:33.937351181 +0000
@@ -23,6 +23,9 @@
 'cursor_off' :'\x1b[?25l',
 }
 
+WAF_LOG_FORMAT = os.environ.get('WAF_LOG_FORMAT', LOG_FORMAT)
+WAF_HOUR_FORMAT = os.environ.get('WAF_HOUR_FORMAT', HOUR_FORMAT)
+
 got_tty = False
 term = os.environ.get('TERM', 'dumb')
 if not term in ['dumb', 'emacs']:
@@ -84,7 +87,7 @@
 
 class formatter(logging.Formatter):
 	def __init__(self):
-		logging.Formatter.__init__(self, LOG_FORMAT, HOUR_FORMAT)
+		logging.Formatter.__init__(self, WAF_LOG_FORMAT, WAF_HOUR_FORMAT)
 
 	def format(self, rec):
 		if rec.levelno >= logging.WARNING or rec.levelno == logging.INFO:
