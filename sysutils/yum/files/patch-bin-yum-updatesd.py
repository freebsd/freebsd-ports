--- bin/yum-updatesd.py.orig	2010-08-22 12:58:40.000000000 +0200
+++ bin/yum-updatesd.py	2010-08-22 12:59:38.000000000 +0200
@@ -16,7 +16,7 @@
     os.dup2(fd, 2)
     os.close(fd)
 
-sys.path.insert(0, '/usr/share/yum-cli')
+sys.path.insert(0, '@PREFIX@/share/yum-cli')
 try:
     import yumupd
     yumupd.main(options)
