--- usr/lib/python3/dist-packages/privleap/privleapd.py.orig	2026-07-03 19:48:15 UTC
+++ usr/lib/python3/dist-packages/privleap/privleapd.py
@@ -28,8 +28,6 @@ from dataclasses import dataclass
 from typing import cast, SupportsIndex, NoReturn, Any, IO
 from dataclasses import dataclass
 
-import sdnotify  # type: ignore
-
 from .privleap import (
     ConfigData,
     PrivleapAction,
@@ -116,9 +114,6 @@ class PrivleapdGlobal:
     allowed_group_list: list[str] = []
     expected_disallowed_user_list: list[str] = []
 
-    # Readable and writable by main thread only
-    sdnotify_object: sdnotify.SystemdNotifier = sdnotify.SystemdNotifier()
-
     # Thread IPC mechanisms
     # control-to-main pipe read end, for main thread
     ctm_read_fd: int = 0
@@ -609,7 +604,7 @@ def run_action(
     if target_user is None and target_group is None:
         # Both user and group are unset, default to "root" for both.
         target_user = "root"
-        target_group = "root"
+        target_group = "wheel"
     elif target_group is None:
         # Target user is set but group is unset, set the group to the target
         # user's default group.
@@ -629,14 +624,13 @@ def run_action(
 
     action_process: subprocess.Popen[bytes] = subprocess.Popen(
         [
-            "/usr/libexec/privleap/shim.py",
+            f"{sys.prefix}/libexec/privleap/shim.py",
             calling_user,
             target_user,
             target_group,
             str(PrivleapdGlobal.old_umask),
-            "/usr/bin/bash",
+            "/bin/sh",
             "-c",
-            "--",
             desired_action.action_command,
         ],
         stdout=subprocess.PIPE,
@@ -841,10 +835,10 @@ def send_action_results(
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
 
     # Comm threads that are currently streaming stdio from a process to a
     # client may be stuck waiting for the process to write something to stdout
@@ -855,7 +849,7 @@ def send_action_results(
     # written to this variable (it is always a single NULL byte), we just need
     # to break the epoll_obj.poll() call.
     assert listen_socket_info.term_notify_read_fd != 0
-    epoll_obj.register(listen_socket_info.term_notify_read_fd, select.EPOLLIN)
+    epoll_obj.register(listen_socket_info.term_notify_read_fd, select.POLLIN)
 
     try:
         stdout_done: bool = False
@@ -899,7 +893,6 @@ def send_action_results(
         action_process.wait()
 
     finally:
-        epoll_obj.close()
         action_process.stdout.close()
         action_process.stderr.close()
         action_process.terminate()
@@ -1673,8 +1666,8 @@ def main_loop() -> NoReturn:
 
     assert PrivleapdGlobal.ctm_read_pipe is not None
     epoll_fd_set: set[int] = set()
-    epoll_obj: select.epoll = select.epoll()
-    epoll_obj.register(PrivleapdGlobal.ctm_read_fd, select.EPOLLIN)
+    epoll_obj: select.poll = select.poll()
+    epoll_obj.register(PrivleapdGlobal.ctm_read_fd, select.POLLIN)
     socket_list_changed: bool = True
 
     while True:
@@ -1688,14 +1681,13 @@ def main_loop() -> NoReturn:
             ]
             read_sock_fileno_set: set[int] = set(read_sock_fileno_list)
             for register_fileno in read_sock_fileno_set - epoll_fd_set:
-                epoll_obj.register(register_fileno, select.EPOLLIN)
+                epoll_obj.register(register_fileno, select.POLLIN)
             epoll_fd_set.update(read_sock_fileno_set)
             for remove_fileno in epoll_fd_set - read_sock_fileno_set:
                 epoll_fd_set.remove(remove_fileno)
             socket_list_changed = False
 
         epoll_event_fd_list: list[int] = [x[0] for x in epoll_obj.poll(5)]
-        PrivleapdGlobal.sdnotify_object.notify("WATCHDOG=1")
 
         if PrivleapdGlobal.ctm_read_fd in epoll_event_fd_list:
             # Connection change, i.e. adding or removing a socket. The
@@ -1723,8 +1715,7 @@ def main_loop() -> NoReturn:
                         ready_sock_info_obj = sock_info_obj
                         break
                 if ready_sock_info_obj is None:
-                    logging.critical("privleapd lost track of a socket!")
-                    sys.exit(1)
+                    continue
                 if ready_sock_info_obj.listen_socket.socket_type == (
                     PrivleapSocketType.CONTROL
                 ):
@@ -1804,8 +1795,6 @@ def main() -> NoReturn:
         target=control_handler_loop, daemon=True
     )
     control_handler_thread.start()
-    PrivleapdGlobal.sdnotify_object.notify("READY=1")
-    PrivleapdGlobal.sdnotify_object.notify("STATUS=Fully started")
     if PrivleapdGlobal.test_mode:
         Path("/tmp/privleapd-ready-for-test").touch()
     main_loop()
