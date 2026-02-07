--- poller-wrapper.py.orig	2022-01-26 18:26:32 UTC
+++ poller-wrapper.py
@@ -40,6 +40,9 @@ if not config:
     logger = logging.getLogger(__name__)
     logger.critical("Could not run {} wrapper. Missing config".format(WRAPPER_TYPE))
     sys.exit(1)
+
+os.environ['PATH'] += ':%%LOCALBASE%%/sbin:%%LOCALBASE%%/bin'
+
 log_dir = config["log_dir"]
 log_file = os.path.join(log_dir, WRAPPER_TYPE + "_wrapper.log")
 logger = LibreNMS.logger_get_logger(log_file, debug=args.debug)
