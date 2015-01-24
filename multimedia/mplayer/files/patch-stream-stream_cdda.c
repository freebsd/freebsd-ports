--- stream/stream_cdda.c.orig	2013-12-02 15:30:21.000000000 +0100
+++ stream/stream_cdda.c	2015-01-24 15:44:33.095742583 +0100
@@ -21,8 +21,8 @@
 #include <cdda_interface.h>
 #include <cdda_paranoia.h>
 #else
-#include <cdio/cdda.h>
-#include <cdio/paranoia.h>
+#include <cdio/paranoia/cdda.h>
+#include <cdio/paranoia/paranoia.h>
 #endif
 #include <stdio.h>
 #include <stdlib.h>
