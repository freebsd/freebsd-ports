--- mplayerxp/sig_hand.c.orig	Thu Dec  5 13:48:53 2002
+++ mplayerxp/sig_hand.c	Thu Dec  5 13:49:32 2002
@@ -5,10 +5,11 @@
 #include <string.h>
 #include <stdio.h>
 #include <signal.h>
+#include <sys/types.h>
+#include <sys/time.h>
 #include <sys/resource.h>
 #include "sig_hand.h"
 #include "mp_msg.h"
-#include <sys/types.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include "dec_ahead.h"
