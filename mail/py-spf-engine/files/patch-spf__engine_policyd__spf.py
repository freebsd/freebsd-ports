--- spf_engine/policyd_spf.py.orig	2022-09-05 15:47:42 UTC
+++ spf_engine/policyd_spf.py
@@ -46,7 +46,7 @@ def main():
 
     #  load config file  {{{1
     #  Default location:
-    configFile = '/etc/python-policyd-spf/policyd-spf.conf'
+    configFile = '%%PREFIX%%/etc/python-policyd-spf/policyd-spf.conf'
     if len(sys.argv) > 1:
         if sys.argv[1] in ( '-?', '--help', '-h' ):
             print('usage: policyd-spf [<configfilename>]')
