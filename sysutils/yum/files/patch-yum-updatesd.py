--- yum-updatesd.py.orig	2010-05-06 16:54:46.000000000 +0200
+++ yum-updatesd.py	2010-08-22 13:29:51.000000000 +0200
@@ -53,10 +53,10 @@
 from yum.update_md import UpdateMetadata
 
 # FIXME: is it really sane to use this from here?
-sys.path.append('/usr/share/yum-cli')
+sys.path.append('@PREFIX@/share/yum-cli')
 import callback
 
-config_file = '/etc/yum/yum-updatesd.conf'
+config_file = '@PREFIX@/etc/yum/yum-updatesd.conf'
 initial_directory = os.getcwd()
 
 class UpdateEmitter(object):
