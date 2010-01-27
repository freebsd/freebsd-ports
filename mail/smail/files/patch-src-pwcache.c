--- src/pwcache.c.orig	2010-01-25 17:52:32.000000000 -0800
+++ src/pwcache.c	2010-01-25 17:53:42.000000000 -0800
@@ -29,7 +29,6 @@
 #include <limits.h>
 #include <grp.h>
 #include <pwd.h>
-#include <utmp.h>
 
 #ifdef STDC_HEADERS
 # include <stdlib.h>
