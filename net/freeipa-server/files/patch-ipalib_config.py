--- ipalib/config.py.orig	2026-08-11 07:29:25 UTC
+++ ipalib/config.py
@@ -495,7 +495,10 @@ class Env:
             elif self.in_tree:
                 self.confdir = self.dot_ipa
             else:
-                self.confdir = path.join('/', 'etc', 'ipa')
+                # FreeBSD: honour the platform confdir (paths.ETC_IPA)
+                # instead of the hard-coded Linux /etc/ipa.
+                from ipaplatform.paths import paths as _ipaplatform_paths
+                self.confdir = _ipaplatform_paths.ETC_IPA
 
         # Set conf (config file for this context):
         if 'conf' not in self:
