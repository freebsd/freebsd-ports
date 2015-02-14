--- lshell/checkconfig.py.orig	2013-08-19 19:59:37 UTC
+++ lshell/checkconfig.py
@@ -307,7 +307,7 @@ class CheckConfig:
             try:
                 if logfilename == "syslog":
                     from logging.handlers import SysLogHandler
-                    syslog = SysLogHandler(address='/dev/log')
+                    syslog = SysLogHandler(address='/var/run/log')
                     syslog.setFormatter(syslogformatter)
                     syslog.setLevel(self.levels[self.conf['loglevel']])
                     logger.addHandler(syslog)
