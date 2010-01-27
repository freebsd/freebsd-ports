--- tty.sh.orig	2003-09-08 07:24:25.000000000 -0700
+++ tty.sh	2010-01-26 15:56:56.000000000 -0800
@@ -76,7 +76,7 @@
 #endif
 
 #include "config.h"
-#ifdef SVR4
+#if defined(SVR4) && !defined(__FreeBSD_cc_version)
 #include <sys/stropts.h>	/* for I_POP */
 #endif
 
@@ -562,7 +562,9 @@
 XIF{VLNEXT}	np->tio.c_cc[VLNEXT] = VDISABLE;
 XIF{VSTATUS}	np->tio.c_cc[VSTATUS] = VDISABLE;
 XIF{VSUSP}	np->tio.c_cc[VSUSP] = VDISABLE;
-XIF{VERASE}	np->tio.c_cc[VERASE] = VDISABLE;
+ /* Set VERASE to DEL, rather than VDISABLE, to avoid libvte
+    "autodetect" issues. */
+XIF{VERASE}	np->tio.c_cc[VERASE] = 0x7f;
 XIF{VKILL}	np->tio.c_cc[VKILL] = VDISABLE;
 # ifdef HPUX_LTCHARS_HACK
   np->m_ltchars.t_suspc  = VDISABLE;
