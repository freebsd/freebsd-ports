--- belgolib/dirs_core.c.orig	Sun Dec 15 15:02:19 2002
+++ belgolib/dirs_core.c	Sun Dec 15 15:02:25 2002
@@ -1,6 +1,6 @@
 #include "dirs_core.h"
 
-Oinfo::Oinfo(const string& fname, int fmode=0) 
+Oinfo::Oinfo(const string& fname, int fmode) 
 {
     stat_info = new struct stat;
 
