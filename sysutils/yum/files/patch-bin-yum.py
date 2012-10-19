--- bin/yum.py.orig	2010-05-06 16:54:46.000000000 +0200
+++ bin/yum.py	2010-08-22 12:55:43.000000000 +0200
@@ -23,7 +23,7 @@
 """ % (sys.exc_value, sys.version)
     sys.exit(1)
 
-sys.path.insert(0, '/usr/share/yum-cli')
+sys.path.insert(0, '@PREFIX@/share/yum-cli')
 try:
     import yummain
     yummain.user_main(sys.argv[1:], exit_code=True)
