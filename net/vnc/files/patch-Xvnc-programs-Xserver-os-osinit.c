--- Xvnc/programs/Xserver/os/osinit.c.orig	Thu Nov  7 22:41:44 2002
+++ Xvnc/programs/Xserver/os/osinit.c	Thu Nov  7 22:41:59 2002
@@ -48,6 +48,7 @@
 /* $XConsortium: osinit.c /main/45 1996/12/02 10:23:13 lehors $ */
 /* $XFree86: xc/programs/Xserver/os/osinit.c,v 3.12 1997/01/18 06:58:02 dawes Exp $ */
 
+#include <stdlib.h>
 #include <stdio.h>
 #include "X.h"
 #include "os.h"
