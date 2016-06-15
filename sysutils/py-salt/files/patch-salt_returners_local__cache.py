# Issue #33554
# https://github.com/saltstack/salt/issues/33554
--- salt/returners/local_cache.py.orig	2016-05-25 22:30:31 UTC
+++ salt/returners/local_cache.py
@@ -407,14 +407,14 @@ def clean_old_jobs():
             for final in t_path_dirs:
                 f_path = os.path.join(t_path, final)
                 jid_file = os.path.join(f_path, 'jid')
-                if not os.path.isfile(jid_file):
+                if not os.path.isfile(jid_file) and os.path.exists(t_path):
                     # No jid file means corrupted cache entry, scrub it
                     # by removing the entire t_path directory
                     shutil.rmtree(t_path)
-                else:
+                elif os.path.isfile(jid_file):
                     jid_ctime = os.stat(jid_file).st_ctime
                     hours_difference = (cur - jid_ctime) / 3600.0
-                    if hours_difference > __opts__['keep_jobs']:
+                    if hours_difference > __opts__['keep_jobs'] and os.path.exists(t_path):
                         # Remove the entire t_path from the original JID dir
                         shutil.rmtree(t_path)
 
