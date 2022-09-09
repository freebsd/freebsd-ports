--- spf_engine/milter_spf.py.orig	2022-09-05 15:47:42 UTC
+++ spf_engine/milter_spf.py
@@ -207,7 +207,7 @@ class spfMilter(Milter.Base):
 def main():
     # Ugh, but there's no easy way around this.
     global milterconfig
-    configFile = '/usr/local/etc/python-policyd-spf/policyd-spf.conf'
+    configFile = '%%PREFIX%%/etc/python-policyd-spf/policyd-spf.conf'
     if len(sys.argv) > 1:
         if sys.argv[1] in ('-?', '--help', '-h'):
             print('usage: pyspf-milter [<configfilename>]')
