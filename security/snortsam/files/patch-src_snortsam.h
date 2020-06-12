Avoid redefining bool

snortsam.c:750:6: error: conflicting types for 'parseline'
void parseline(char *arg,bool first,char *file,unsigned long line)  
     ^
./snortsam.h:470:6: note: previous declaration is here
void parseline(char *arg,bool first,char *file,unsigned long line);
     ^

--- src/snortsam.h.orig	2020-03-30 10:54:24 UTC
+++ src/snortsam.h
@@ -59,6 +59,7 @@
 #endif
 
 
+#include <stdbool.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <time.h>
