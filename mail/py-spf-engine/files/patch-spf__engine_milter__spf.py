--- spf_engine/milter_spf.py.orig	2024-07-06 22:24:06 UTC
+++ spf_engine/milter_spf.py
@@ -152,8 +152,12 @@
             h = fold(str(h))
             if milterconfig.get('debugLevel') >= 2:
                 syslog.syslog(str(h))
-            name, val = str(h).split(': ', 1)
-            self.addheader(name, val, 0)
+            name, sep, val = str(h).partition(': ')
+            if sep:
+                self.addheader(name, val, 0)
+            else:
+                syslog.syslog(syslog.LOG_WARNING,
+                    "pyspf-milter: malformed AR result, header not added: %r" % h)
         return Milter.CONTINUE
 
 
@@ -223,7 +227,7 @@
 def main():
     # Ugh, but there's no easy way around this.
     global milterconfig
-    configFile = '/usr/local/etc/python-policyd-spf/policyd-spf.conf'
+    configFile = '%%PREFIX%%/etc/python-policyd-spf/policyd-spf.conf'
     if len(sys.argv) > 1:
         if sys.argv[1] in ('-?', '--help', '-h'):
             print('usage: pyspf-milter [<configfilename>]')
