--- spf_engine/milter_spf.py.orig	2023-01-11 14:35:12 UTC
+++ spf_engine/milter_spf.py
@@ -211,7 +211,7 @@ class spfMilter(Milter.Base):
 def main():
     # Ugh, but there's no easy way around this.
     global milterconfig
-    configFile = '/usr/local/etc/python-policyd-spf/policyd-spf.conf'
+    configFile = '%%PREFIX%%/etc/python-policyd-spf/policyd-spf.conf'
     if len(sys.argv) > 1:
         if sys.argv[1] in ('-?', '--help', '-h'):
             print('usage: pyspf-milter [<configfilename>]')
