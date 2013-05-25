--- util/iopl.h.orig	2013-03-25 20:48:15.486758154 +0100
+++ util/iopl.h	2013-03-25 20:47:56.000000000 +0100
@@ -0,0 +1,60 @@
+#ifdef __NetBSD__
+#  include <sys/types.h>
+#  include <machine/pio.h>
+#  include <machine/sysarch.h>
+#else
+#  if defined(__linux__)
+/* Can't because <sys/iopl.h> provides conflicting inb, outb, etc
+ * #    include <sys/io.h>
+ */
+int iopl(int level);
+#  endif
+#  if defined(SVR4) && defined(i386)
+#    include <sys/types.h>
+#    ifdef NCR
+       /* broken NCR <sys/sysi86.h> */
+#      define __STDC
+#      include <sys/sysi86.h>
+#      undef __STDC
+#    else
+#      include <sys/sysi86.h>
+#    endif
+#    ifdef SVR4
+#      if !defined(sun)
+#        include <sys/seg.h>
+#      endif
+#    endif
+#    include <sys/v86.h>
+#    if defined(sun)
+#      include <sys/psw.h>
+#    endif
+#  endif
+#  include "AsmMacros.h"
+#endif /* NetBSD */
+
+#include <unistd.h>
+#include <stdio.h>
+#include <stdlib.h>
+
+#ifdef __NetBSD__
+#  define SET_IOPL() i386_iopl(3)
+#  define RESET_IOPL() i386_iopl(0)
+#else
+#  if defined(SVR4) && defined(i386)
+#    ifndef SI86IOPL
+#      define SET_IOPL() sysi86(SI86V86,V86SC_IOPL,PS_IOPL)
+#      define RESET_IOPL() sysi86(SI86V86,V86SC_IOPL,0)
+#    else
+#      define SET_IOPL() sysi86(SI86IOPL,3)
+#      define RESET_IOPL() sysi86(SI86IOPL,0)
+#    endif
+#  else
+#    ifdef linux
+#      define SET_IOPL() iopl(3)
+#      define RESET_IOPL() iopl(0)
+#    else
+#      define SET_IOPL() (void)0
+#      define RESET_IOPL() (void)0
+#    endif
+#  endif
+#endif
