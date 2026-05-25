--- usr/lib/python3/dist-packages/privleap/privleap.py.orig	2026-05-24 20:47:02 UTC
+++ usr/lib/python3/dist-packages/privleap/privleap.py
@@ -1020,7 +1020,6 @@ class PrivleapSession:
         """
 
         assert self.backend_socket is not None
-        self.backend_socket.shutdown(socket.SHUT_RDWR)
         self.backend_socket.close()
         self.is_session_open = False
 
@@ -1223,7 +1222,7 @@ class PrivleapCommon:
     Common constants and functions used throughout privleap.
     """
 
-    state_dir: Path = Path("/run/privleapd")
+    state_dir: Path = Path("/var/run/privleapd")
     control_path: Path = Path(state_dir, "control")
     comm_dir: Path = Path(state_dir, "comm")
     config_file_regex: re.Pattern[str] = re.compile(r"[-A-Za-z0-9_]+\.conf\Z")
