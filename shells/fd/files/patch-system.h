Taken from: [FDclone-users:00109]
diff -u FD-2.02a/system.h ./system.h
--- FD-2.02a/system.h	Wed Nov 20 09:44:57 2002
+++ ./system.h	Mon Feb 17 02:27:11 2003
@@ -47,15 +47,20 @@
 #define	Xsigblock(o,m)	((o) = sigblock(m))
 #endif	/* !USESIGPMASK */
 
+#ifdef	POSIX
+#define	gettcpgrp(f, g)	(g = tcgetpgrp(f))
+#define	settcpgrp(f, g)	tcsetpgrp(f, g)
+#else
 #ifdef	TIOCGPGRP
 #define	gettcpgrp(f, g)	((ioctl(f, TIOCGPGRP, &g) < 0) ? (g = -1) : g)
 #else
-#define	gettcpgrp(f, g)	(g = tcgetpgrp(f))
+#define	gettcpgrp(f, g)	(-1)
 #endif
 #ifdef	TIOCSPGRP
 #define	settcpgrp(f, g)	ioctl(f, TIOCSPGRP, &(g))
 #else
-#define	settcpgrp(f, g)	tcsetpgrp(f, g)
+#define	settcpgrp(f, g)	(-1)
+#endif
 #endif
 
 #if	!MSDOS
