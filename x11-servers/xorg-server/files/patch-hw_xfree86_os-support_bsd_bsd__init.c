--- hw/xfree86/os-support/bsd/bsd_init.c.orig	2023-10-25 01:40:28 UTC
+++ hw/xfree86/os-support/bsd/bsd_init.c
@@ -48,6 +48,8 @@ static int initialVT = -1;
 #if defined (SYSCONS_SUPPORT) || defined (PCVT_SUPPORT)
 static int VTnum = -1;
 static int initialVT = -1;
+static struct termios tty_attr;	/* tty state to restore */
+static int tty_mode;		/* kbd mode to restore */
 #endif
 
 #ifdef PCCONS_SUPPORT
@@ -253,6 +255,7 @@ xf86OpenConsole()
 #endif
  acquire_vt:
             if (!xf86Info.ShareVTs) {
+                struct termios nTty;
                 /*
                  * now get the VT
                  */
@@ -287,6 +290,26 @@ xf86OpenConsole()
                 if (ioctl(xf86Info.consoleFd, KDSETMODE, KD_GRAPHICS) < 0) {
                     FatalError("xf86OpenConsole: KDSETMODE KD_GRAPHICS failed");
                 }
+
+                tcgetattr(xf86Info.consoleFd, &tty_attr);
+                ioctl(xf86Info.consoleFd, KDGKBMODE, &tty_mode);
+
+                /* disable special keys */
+                if (ioctl(xf86Info.consoleFd, KDSKBMODE, K_RAW) < 0) {
+                    FatalError("xf86OpenConsole: KDSKBMODE K_RAW failed (%s)",
+                               strerror(errno));
+                }
+
+                nTty = tty_attr;
+                nTty.c_iflag = IGNPAR | IGNBRK;
+                nTty.c_oflag = 0;
+                nTty.c_cflag = CREAD | CS8;
+                nTty.c_lflag = 0;
+                nTty.c_cc[VTIME] = 0;
+                nTty.c_cc[VMIN] = 1;
+                cfsetispeed(&nTty, 9600);
+                cfsetospeed(&nTty, 9600);
+                tcsetattr(xf86Info.consoleFd, TCSANOW, &nTty);
             }
             else {              /* xf86Info.ShareVTs */
                 close(xf86Info.consoleFd);
@@ -303,7 +326,7 @@ xf86OpenConsole()
     else {
         /* serverGeneration != 1 */
 #if defined (SYSCONS_SUPPORT) || defined (PCVT_SUPPORT)
-        if (!xf86Info.ShareVTs &&
+        if (!xf86Info.ShareVTs && xf86Info.autoVTSwitch &&
             (xf86Info.consType == SYSCONS || xf86Info.consType == PCVT)) {
             if (ioctl(xf86Info.consoleFd, VT_ACTIVATE, xf86Info.vtno) != 0) {
                 xf86Msg(X_WARNING, "xf86OpenConsole: VT_ACTIVATE failed\n");
@@ -594,6 +617,8 @@ xf86CloseConsole()
     case SYSCONS:
     case PCVT:
         ioctl(xf86Info.consoleFd, KDSETMODE, KD_TEXT);  /* Back to text mode */
+        ioctl(xf86Info.consoleFd, KDSKBMODE, tty_mode);
+        tcsetattr(xf86Info.consoleFd, TCSANOW, &tty_attr);
         if (ioctl(xf86Info.consoleFd, VT_GETMODE, &VT) != -1) {
             VT.mode = VT_AUTO;
             ioctl(xf86Info.consoleFd, VT_SETMODE, &VT); /* dflt vt handling */
@@ -604,7 +629,7 @@ xf86CloseConsole()
                            strerror(errno));
         }
 #endif
-        if (initialVT != -1)
+        if (xf86Info.autoVTSwitch && initialVT != -1)
             ioctl(xf86Info.consoleFd, VT_ACTIVATE, initialVT);
         break;
 #endif                          /* SYSCONS_SUPPORT || PCVT_SUPPORT */
