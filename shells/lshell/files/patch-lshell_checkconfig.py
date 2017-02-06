--- lshell/checkconfig.py	2017-01-11 18:12:28 UTC
+++ lshell/checkconfig.py
@@ -238,7 +238,7 @@
             try:
                 if logfilename == "syslog":
                     from logging.handlers import SysLogHandler
-                    syslog = SysLogHandler(address='/dev/log')
+                    syslog = SysLogHandler(address='/var/run/log')
                     syslog.setFormatter(syslogformatter)
                     syslog.setLevel(self.levels[self.conf['loglevel']])
                     logger.addHandler(syslog)
