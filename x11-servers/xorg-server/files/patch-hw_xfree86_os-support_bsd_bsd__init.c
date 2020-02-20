--- hw/xfree86/os-support/bsd/bsd_init.c.orig	2017-03-15 18:05:25 UTC
+++ hw/xfree86/os-support/bsd/bsd_init.c
@@ -48,6 +48,8 @@ static int devConsoleFd = -1;
 #if defined (SYSCONS_SUPPORT) || defined (PCVT_SUPPORT)
 static int VTnum = -1;
 static int initialVT = -1;
+static struct termios tty_attr;	/* tty state to restore */
+static int tty_mode;		/* kbd mode to restore */
 #endif
 
 #ifdef PCCONS_SUPPORT
@@ -230,6 +232,9 @@ xf86OpenConsole()
              * Add cases for other *BSD that behave the same.
              */
 #if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
+#if defined(__sparc64__)
+	    pci_system_init_dev_mem(fd);
+#endif
             uname(&uts);
             i = atof(uts.release) * 100;
             if (i >= 310)
@@ -253,6 +258,7 @@ xf86OpenConsole()
 #endif
  acquire_vt:
             if (!xf86Info.ShareVTs) {
+                struct termios nTty;
                 /*
                  * now get the VT
                  */
@@ -287,6 +293,26 @@ xf86OpenConsole()
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
@@ -594,6 +620,8 @@ xf86CloseConsole()
     case SYSCONS:
     case PCVT:
         ioctl(xf86Info.consoleFd, KDSETMODE, KD_TEXT);  /* Back to text mode */
+        ioctl(xf86Info.consoleFd, KDSKBMODE, tty_mode);
+        tcsetattr(xf86Info.consoleFd, TCSANOW, &tty_attr);
         if (ioctl(xf86Info.consoleFd, VT_GETMODE, &VT) != -1) {
             VT.mode = VT_AUTO;
             ioctl(xf86Info.consoleFd, VT_SETMODE, &VT); /* dflt vt handling */
