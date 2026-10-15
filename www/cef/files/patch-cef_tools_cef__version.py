--- cef/tools/cef_version.py.orig	2026-09-06 17:31:54 UTC
+++ cef/tools/cef_version.py
@@ -29,6 +29,11 @@ class VersionFormatter:
     self._old_format_default = \
         bool(int(os.environ.get('CEF_OLD_VERSION_FORMAT', '0')))
 
+    # When building from a source tarball there is no Git history to compute
+    # the version from, so it has to be passed in through the environment.
+    self._tarball = not git.is_checkout(self.cef_path) and \
+        'CEF_TARBALL_COMMIT_HASH' in os.environ
+
     self.reset()
 
   def reset(self):
@@ -64,8 +69,12 @@ class VersionFormatter:
   def get_cef_commit_components(self):
     """ Returns CEF commit components. """
     if not bool(self._cef_commit):
-      hash = git.get_hash(self.cef_path)
-      number = git.get_commit_number(self.cef_path)
+      if self._tarball:
+        hash = os.environ['CEF_TARBALL_COMMIT_HASH']
+        number = os.environ.get('CEF_TARBALL_COMMIT_NUMBER', '0')
+      else:
+        hash = git.get_hash(self.cef_path)
+        number = git.get_commit_number(self.cef_path)
       self._cef_commit = {'HASH': hash, 'NUMBER': number}
     return self._cef_commit
 
@@ -77,7 +86,12 @@ class VersionFormatter:
 
       # Retrieve the list of commits that have been applied on the current
       # branch since branching from origin/master.
-      hashes = git.get_branch_hashes(self.cef_path)
+      if self._tarball:
+        minor = int(os.environ.get('CEF_TARBALL_BRANCH_MINOR', '0'))
+        bugfix = int(os.environ.get('CEF_TARBALL_BRANCH_PATCH', '0'))
+        hashes = []
+      else:
+        hashes = git.get_branch_hashes(self.cef_path)
       for hash in hashes:
         # Determine if the API versions file was modified by the commit.
         found = False
@@ -189,7 +203,7 @@ class VersionFormatter:
     # Determine whether the current commit is on a release branch. For example,
     # if using Chrome build 3683, are we on CEF branch "3683" or "origin/3683"?
     release_branch = chrome_version['BUILD']
-    on_release_branch = (
+    on_release_branch = self._tarball or (
         git.is_ancestor(self.cef_path, 'HEAD', release_branch) or
         git.is_ancestor(self.cef_path, 'HEAD', 'origin/' + release_branch))
 
