--- tosh_bios.cpp.orig
+++ tosh_bios.cpp
@@ -23,11 +23,12 @@
 static const char PROGRAM_ID[]="$Id: tosh_bios.cpp,v 1.4 2003/07/29 01:43:38 cws Exp $";
 
 #include "tosh_utils.h"
-#include <ctype.h>
-#include <stdio.h>
+#include <cctype>
+#include <cstdio>
+#include <cstring>
 #include <sys/types.h>
 #include <sys/mman.h>
-#include <time.h>
+#include <ctime>
 
 #include "toshibaIDs.hh"
 #include "tosh_vars.h"
