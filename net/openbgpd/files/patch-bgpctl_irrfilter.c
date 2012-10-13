Index: bgpctl/irrfilter.c
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpctl/irrfilter.c,v
retrieving revision 1.1.1.1
retrieving revision 1.3
diff -u -p -r1.1.1.1 -r1.3
--- bgpctl/irrfilter.c	30 Jun 2009 05:46:15 -0000	1.1.1.1
+++ bgpctl/irrfilter.c	13 Oct 2012 18:35:56 -0000	1.3
@@ -1,4 +1,4 @@
-/*	$OpenBSD: irrfilter.c,v 1.4 2007/05/28 23:31:53 henning Exp $ */
+/*	$OpenBSD: irrfilter.c,v 1.3 2007/03/06 16:45:34 henning Exp $ */
 
 /*
  * Copyright (c) 2007 Henning Brauer <henning@openbsd.org>
@@ -15,6 +15,9 @@
  * AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT
  * OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
  */
+#if defined(__FreeBSD__)	/* compat */
+#include "openbsd-compat.h"
+#endif /* defined(__FreeBSD__) */
 
 #include <sys/types.h>
 #include <sys/param.h>
