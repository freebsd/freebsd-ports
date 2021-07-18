--- poller-wrapper.py.orig	2021-01-14 02:21:36 UTC
+++ poller-wrapper.py
@@ -44,6 +44,8 @@ except ImportError as exc:
     print('ERROR: %s' % exc)
     sys.exit(2)
 
+os.environ['PATH'] += ':%%LOCALBASE%%/sbin:%%LOCALBASE%%/bin'
+
 
 APP_NAME = "poller_wrapper"
 LOG_FILE = "logs/" + APP_NAME + ".log"
