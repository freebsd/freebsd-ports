--- scripts/setup-seafile-mysql.py.orig	2018-08-19 23:40:51 UTC
+++ scripts/setup-seafile-mysql.py
@@ -19,6 +19,8 @@ from ConfigParser import ConfigParser
 
 import MySQLdb
 
+import pwd
+import grp
 
 try:
     import readline # pylint: disable=W0611
@@ -424,8 +426,6 @@ Please choose a way to initialize seafil
         if not re.match(r'^[a-zA-Z0-9_\-\.]+$', host):
             raise InvalidAnswer('%s is not a valid host' % Utils.highlight(host))
 
-        if host == 'localhost':
-            host = '127.0.0.1'
         return host
 
     def ask_mysql_host(self):
@@ -1209,17 +1209,23 @@ limit_request_line = 8190
 
 class UserManualHandler(object):
     def __init__(self):
-        self.src_docs_dir = os.path.join(env_mgr.install_path, 'seafile', 'docs')
+        self.src_docs_dir = os.path.join(env_mgr.install_path, 'seafile', 'share', 'doc', 'seafile')
         self.library_template_dir = None
 
     def copy_user_manuals(self):
         self.library_template_dir = os.path.join(seafile_config.seafile_dir, 'library-template')
         Utils.must_mkdir(self.library_template_dir)
 
+        uid = pwd.getpwnam("%%SEAFILE_USER%%").pw_uid
+        gid = grp.getgrnam("%%SEAFILE_GROUP%%").gr_gid
+        os.chown(self.library_template_dir, uid, gid)
+
         pattern = os.path.join(self.src_docs_dir, '*.doc')
 
         for doc in glob.glob(pattern):
             Utils.must_copy(doc, self.library_template_dir)
+            doc_full = os.path.join(self.library_template_dir, os.path.basename(doc))
+            os.chown(doc_full, uid, gid)
 
 def report_config():
     print
@@ -1284,6 +1290,8 @@ def create_seafile_server_symlink():
 def set_file_perm():
     filemode = 0600
     dirmode = 0700
+    uid = pwd.getpwnam("%%SEAFILE_USER%%").pw_uid
+    gid = grp.getgrnam("%%SEAFILE_GROUP%%").gr_gid
     files = [
         seahub_config.seahub_settings_py,
     ]
@@ -1295,8 +1303,10 @@ def set_file_perm():
     ]
     for fpath in files:
         os.chmod(fpath, filemode)
+        os.chown(fpath, uid, gid)
     for dpath in dirs:
         os.chmod(dpath, dirmode)
+        os.chown(dpath, uid, gid)
 
 env_mgr = EnvManager()
 ccnet_config = CcnetConfigurator()
@@ -1488,8 +1498,11 @@ def report_success():
 Your seafile server configuration has been finished successfully.
 -----------------------------------------------------------------
 
-run seafile server:     ./seafile.sh { start | stop | restart }
-run seahub  server:     ./seahub.sh  { start <port> | stop | restart <port> }
+run seafile server:     sysrc seafile_enable=YES
+                        service seafile { start | stop | restart }
+run seahub  server:     sysrc seahub_enable=YES
+                        service seahub { start | stop | restart }
+run reset-admin:        ./reset-admin.sh
 
 -----------------------------------------------------------------
 If you are behind a firewall, remember to allow input/output of these tcp ports:
