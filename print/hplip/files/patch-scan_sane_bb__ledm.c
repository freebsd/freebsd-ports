--- scan/sane/bb_ledm.c.orig	2023-06-02 08:02:36 UTC
+++ scan/sane/bb_ledm.c
@@ -16,6 +16,7 @@
 # include <string.h>
 # include <fcntl.h>
 # include <math.h>
+# include <unistd.h>
 # include "sane.h"
 # include "saneopts.h"
 # include "hpmud.h"
