--- src/CmdLineParser.cpp.orig	2006-05-08 10:21:40 UTC
+++ src/CmdLineParser.cpp
@@ -31,6 +31,7 @@
 #include "CmdLineParser.h"
 #include "LogEntry.h"
 #include "StrTools.h"
+#include <netpfil/pf/pf.h>
 #include <unistd.h>
 #include <vector>
 
