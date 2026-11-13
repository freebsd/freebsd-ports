Description: Pass an 8-byte struct winsize to the TIOCGWINSZ ioctl, which
  Python 3.14 requires.
Issue ID: https://github.com/Snaipe/python-rst2ansi/issues/18
Changeset: https://github.com/Snaipe/python-rst2ansi/commit/3728e16
TODO: Drop when a release after 0.1.5 appears.

--- rst2ansi/get_terminal_size.py.orig	2026-10-11 21:18:05 UTC
+++ rst2ansi/get_terminal_size.py
@@ -72,10 +72,10 @@ except ImportError:

     def _get_terminal_size(fd):
         try:
-            res = fcntl.ioctl(fd, termios.TIOCGWINSZ, b"\x00" * 4)
+            res = fcntl.ioctl(fd, termios.TIOCGWINSZ, b"\x00" * 8)
         except IOError as e:
             raise OSError(e)
-        lines, columns = struct.unpack("hh", res)
+        lines, columns, *_ = struct.unpack("hhhh", res)
 
         return terminal_size(columns, lines)
 
