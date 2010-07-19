--- pexpect.py.orig	2008-08-18 18:27:05.000000000 -0400
+++ pexpect.py	2010-06-24 15:15:26.000000000 -0400
@@ -1437,17 +1437,7 @@
         applications like vi or curses -- applications that respond to the
         SIGWINCH signal. """
 
-        # Check for buggy platforms. Some Python versions on some platforms
-        # (notably OSF1 Alpha and RedHat 7.1) truncate the value for
-        # termios.TIOCSWINSZ. It is not clear why this happens.
-        # These platforms don't seem to handle the signed int very well;
-        # yet other platforms like OpenBSD have a large negative value for
-        # TIOCSWINSZ and they don't have a truncate problem.
-        # Newer versions of Linux have totally different values for TIOCSWINSZ.
-        # Note that this fix is a hack.
-        TIOCSWINSZ = getattr(termios, 'TIOCSWINSZ', -2146929561)
-        if TIOCSWINSZ == 2148037735L: # L is not required in Python >= 2.2.
-            TIOCSWINSZ = -2146929561 # Same bits, but with sign.
+        TIOCSWINSZ = getattr(termios, 'TIOCSWINSZ', 2148037735L)
         # Note, assume ws_xpixel and ws_ypixel are zero.
         s = struct.pack('HHHH', r, c, 0, 0)
         fcntl.ioctl(self.fileno(), TIOCSWINSZ, s)
