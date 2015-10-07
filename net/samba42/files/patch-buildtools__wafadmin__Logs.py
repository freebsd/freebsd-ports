--- buildtools/wafadmin/Logs.py.orig	2015-08-30 19:19:48.396822145 +0000
+++ buildtools/wafadmin/Logs.py	2015-08-30 20:14:54.119335271 +0000
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
