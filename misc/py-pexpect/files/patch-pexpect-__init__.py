--- pexpect/__init__.py.orig	2013-11-11 17:58:03.000000000 +0000
+++ pexpect/__init__.py	2013-12-26 08:28:18.423632870 +0000
@@ -1558,10 +1558,7 @@
         # TIOCSWINSZ and they don't have a truncate problem.
         # Newer versions of Linux have totally different values for TIOCSWINSZ.
         # Note that this fix is a hack.
-        TIOCSWINSZ = getattr(termios, 'TIOCSWINSZ', -2146929561)
-        if TIOCSWINSZ == 2148037735:
-            # Same bits, but with sign.
-            TIOCSWINSZ = -2146929561
+        TIOCSWINSZ = getattr(termios, 'TIOCSWINSZ', 2148037735L)
         # Note, assume ws_xpixel and ws_ypixel are zero.
         s = struct.pack('HHHH', rows, cols, 0, 0)
         fcntl.ioctl(self.fileno(), TIOCSWINSZ, s)
