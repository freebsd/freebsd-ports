--- usr/lib/python3/dist-packages/privleap/privleapd.py.orig	2026-10-09 23:29:38 UTC
+++ usr/lib/python3/dist-packages/privleap/privleapd.py
@@ -25,8 +25,6 @@ from dataclasses import dataclass
 from typing import cast, SupportsIndex, NoReturn, Any, IO
 from dataclasses import dataclass
 
-import sdnotify  # type: ignore
-
 from .privleap import (
     ConfigData,
     PrivleapAction,
@@ -108,9 +106,6 @@ class PrivleapdGlobal:
     allowed_gid_list: list[int] = []
     expected_disallowed_uid_list: list[int] = []
 
-    ## Readable and writable by main thread only
-    sdnotify_object: sdnotify.SystemdNotifier = sdnotify.SystemdNotifier()
-
     ## Thread IPC mechanisms
     ## control-to-main pipe read end, for main thread
     ctm_read_fd: int = 0
@@ -653,14 +648,13 @@ def run_action(
 
     action_process: subprocess.Popen[bytes] = subprocess.Popen(
         [
-            "/usr/libexec/privleap/shim.py",
+            f"{sys.prefix}/libexec/privleap/shim.py",
             str(calling_uid),
             str(target_uid),
             str(target_gid),
             str(PrivleapdGlobal.old_umask),
-            "/usr/bin/bash",
+            "/bin/sh",
             "-c",
-            "--",
             desired_action.action_command,
         ],
         stdout=subprocess.PIPE,
@@ -866,10 +860,10 @@ def send_action_results(
     assert action_process.stderr is not None
     assert comm_session.backend_socket is not None
 
-    epoll_obj: select.epoll = select.epoll()
-    epoll_obj.register(comm_session.backend_socket.fileno(), select.EPOLLIN)
-    epoll_obj.register(action_process.stdout.fileno(), select.EPOLLIN)
-    epoll_obj.register(action_process.stderr.fileno(), select.EPOLLIN)
+    epoll_obj: select.poll = select.poll()
+    epoll_obj.register(comm_session.backend_socket.fileno(), select.POLLIN)
+    epoll_obj.register(action_process.stdout.fileno(), select.POLLIN)
+    epoll_obj.register(action_process.stderr.fileno(), select.POLLIN)
 
     ## Comm threads that are currently streaming stdio from a process to a
     ## client may be stuck waiting for the process to write something to stdout
@@ -880,7 +874,7 @@ def send_action_results(
     ## written to this variable (it is always a single NULL byte), we just need
     ## to break the epoll_obj.poll() call.
     assert listen_socket_info.term_notify_read_fd != 0
-    epoll_obj.register(listen_socket_info.term_notify_read_fd, select.EPOLLIN)
+    epoll_obj.register(listen_socket_info.term_notify_read_fd, select.POLLIN)
 
     try:
         stdout_done: bool = False
@@ -931,7 +925,6 @@ def send_action_results(
         action_process.wait()
 
     finally:
-        epoll_obj.close()
         action_process.stdout.close()
         action_process.stderr.close()
         action_process.terminate()
@@ -1730,8 +1723,8 @@ def main_loop() -> NoReturn:
 
     assert PrivleapdGlobal.ctm_read_pipe is not None
     epoll_obj_list: list[PrivleapdSocketInfo] = []
-    epoll_obj: select.epoll = select.epoll()
-    epoll_obj.register(PrivleapdGlobal.ctm_read_fd, select.EPOLLIN)
+    epoll_obj: select.poll = select.poll()
+    epoll_obj.register(PrivleapdGlobal.ctm_read_fd, select.POLLIN)
     socket_list_changed: bool = True
 
     while True:
@@ -1745,13 +1738,12 @@ def main_loop() -> NoReturn:
                     )
                     epoll_obj.register(
                         current_socket.listen_socket.backend_socket.fileno(),
-                        select.EPOLLIN,
+                        select.POLLIN,
                     )
                 epoll_obj_list = copy.copy(PrivleapdGlobal.socket_list)
             socket_list_changed = False
 
         epoll_event_fd_list: list[int] = [x[0] for x in epoll_obj.poll(5)]
-        PrivleapdGlobal.sdnotify_object.notify("WATCHDOG=1")
 
         if PrivleapdGlobal.ctm_read_fd in epoll_event_fd_list:
             ## Connection change, i.e. adding or removing a socket. The
@@ -1865,8 +1857,6 @@ def main() -> NoReturn:
         target=control_handler_loop, daemon=True
     )
     control_handler_thread.start()
-    PrivleapdGlobal.sdnotify_object.notify("READY=1")
-    PrivleapdGlobal.sdnotify_object.notify("STATUS=Fully started")
     if PrivleapdGlobal.test_mode:
         Path("/tmp/privleapd-ready-for-test").touch()
     main_loop()
