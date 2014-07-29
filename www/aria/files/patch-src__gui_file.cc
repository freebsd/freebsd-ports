--- src/gui_file.cc.orig	Mon Sep 30 22:29:46 2002
+++ src/gui_file.cc	Thu Apr  8 22:58:36 2004
@@ -19,12 +19,12 @@
 
 // $Id: gui_file.cc,v 1.45 2002/09/30 13:29:46 tujikawa Exp $
 
-#include <fstream.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <sys/time.h>
 #include <sys/types.h>
 #include <sys/stat.h>
+#include <fstream>
 #include "aria.h"
 #include "ItemCell.h"
 #include "ListManager.h"
