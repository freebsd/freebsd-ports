--- usr/libexec/privleap/shim.py.orig	2026-05-24 22:32:43 UTC
+++ usr/libexec/privleap/shim.py
@@ -100,7 +100,7 @@ action_env["LOGNAME"] = target_user_info.pw_name
 action_env: dict[str, str] = os.environ.copy()
 action_env["HOME"] = target_user_info.pw_dir
 action_env["LOGNAME"] = target_user_info.pw_name
-action_env["SHELL"] = "/usr/bin/bash"
+action_env["SHELL"] = "/bin/sh"
 action_env["PWD"] = target_user_info.pw_dir
 action_env["USER"] = target_user_info.pw_name
 action_env["LC_ALL"] = "C"
