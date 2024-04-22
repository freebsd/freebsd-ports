commit f4726b93e3cee3e81d241a5163541849d4f6851f
Author: Christoph Moench-Tegeder <cmt@burggraben.net>
Date:   Thu Jan 25 22:29:37 2024 +0100

    include sys/wait.h for pclose() return values

diff --git main/config.c main/config.c
index 49bbe6d95b..1cdd7c8b7b 100644
--- main/config.c
+++ main/config.c
@@ -44,6 +44,7 @@
 #include <libgen.h>
 #include <time.h>
 #include <sys/stat.h>
+#include <sys/wait.h>
 
 #include <math.h>	/* HUGE_VAL */
 #include <regex.h>
