--- base/validation.py.orig	2022-02-23 07:41:04 UTC
+++ base/validation.py
@@ -61,7 +61,7 @@ class GPG_Verification(DigiSign_Verification):
         self.__change_owner()
     def __change_owner(self, Recursive = False):
         try:
-            os.umask(0)
+            os.umask(0o022)
             s = os.stat(self.__hplipdir)
             os_utils.changeOwner(self.__gpg_dir, s[stat.ST_UID], s[stat.ST_GID], Recursive)
 
