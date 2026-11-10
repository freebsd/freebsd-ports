--- tests/test_newsunpack.py.orig	2026-09-21 21:39:06 UTC
+++ tests/test_newsunpack.py
@@ -843,7 +843,9 @@
                     st = os.stat(file_path)
                     assert st.st_mode & 0o777 == 0o666 & ~sabnzbd.ORG_UMASK
                     assert st.st_uid == os.getuid(), "%s has wrong owner" % file_path
-                    assert st.st_gid == os.getgid(), "%s has wrong group" % file_path
+                    # FreeBSD gives new files the directory's group, not the process's
+                    gid = os.stat(os.path.dirname(file_path)).st_gid
+                    assert st.st_gid == gid, "%s has wrong group" % file_path
 
             return error_code, extracted_files, complete_contents, download_contents, nzo, temp_complete_dir
 
