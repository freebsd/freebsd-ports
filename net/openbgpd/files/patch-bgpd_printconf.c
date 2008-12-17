--- bgpd/printconf.c	2008-03-18 15:24:06.000000000 +0100
+++ bgpd/printconf.c	2008-03-18 13:27:29.000000000 +0100
@@ -24,6 +24,8 @@
 #include "mrt.h"
 #include "session.h"
 
+#include <limits.h>
+
 void		 print_op(enum comp_ops);
 void		 print_community(int, int);
 void		 print_set(struct filter_set_head *);
