https://github.com/PressLabs/gitfs/issues/258
https://github.com/PressLabs/gitfs/issues/257

--- gitfs/utils/args.py.orig	2016-10-19 15:12:59 UTC
+++ gitfs/utils/args.py
@@ -43,7 +43,7 @@ class Args(object):
             ("foreground", (False, "bool")),
             ("branch", ("master", "string")),
             ("allow_other", (False, "bool")),
-            ("allow_root", (True, "bool")),
+            ("allow_root", (False, "bool")),
             ("commiter_name", (self.get_commiter_user, "string")),
             ("commiter_email", (self.get_commiter_email, "string")),
             ("max_size", (10, "float")),
@@ -71,12 +71,6 @@ class Args(object):
         return self.check_args(self.set_defaults(args))
 
     def check_args(self, args):
-        # check allow_other and allow_root
-        if args.allow_other:
-            args.allow_root = False
-        else:
-            args.allow_root = True
-
         # check log_level
         if args.debug:
             args.log_level = 'debug'
@@ -169,7 +163,7 @@ class Args(object):
         return "{}@{}".format(args.user, socket.gethostname())
 
     def get_repo_path(self, args):
-        return tempfile.mkdtemp(dir="/var/lib/gitfs")
+        return tempfile.mkdtemp(prefix="gitfs")
 
     def get_ssh_key(self, args):
         return os.environ["HOME"] + "/.ssh/id_rsa"
