--- pexpect/__init__.py.orig	2014-04-15 03:31:01.000000000 +0200
+++ pexpect/__init__.py	2014-05-12 14:41:21.690335992 +0200
@@ -1562,7 +1562,7 @@
         # termios.TIOCSWINSZ to be truncated. There was a hack here to work
         # around this, but it caused problems with newer platforms so has been
         # removed. For details see https://github.com/pexpect/pexpect/issues/39
-        TIOCSWINSZ = getattr(termios, 'TIOCSWINSZ', -2146929561)
+        TIOCSWINSZ = getattr(termios, 'TIOCSWINSZ', 2148037735)
         # Note, assume ws_xpixel and ws_ypixel are zero.
         s = struct.pack('HHHH', rows, cols, 0, 0)
         fcntl.ioctl(self.fileno(), TIOCSWINSZ, s)
