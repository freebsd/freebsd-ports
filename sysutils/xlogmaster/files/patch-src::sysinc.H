--- src/sysinc.H.orig	Thu Apr  1 01:00:29 1999
+++ src/sysinc.H	Thu Feb  5 22:12:43 2004
@@ -20,8 +20,9 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <fcntl.h>
-#include <fstream.h>
-#include <strstream.h>
+#include <fstream>
+#include <strstream>
+using namespace std;
 #include <unistd.h>
 #include <string.h>
 #include <time.h>
