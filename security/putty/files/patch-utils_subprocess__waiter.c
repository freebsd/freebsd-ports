--- unix/utils/subprocess_waiter.c.orig	2026-05-14 19:28:47 UTC
+++ unix/utils/subprocess_waiter.c
@@ -9,6 +9,7 @@
 #include "tree234.h"
 
 #include <unistd.h>
+#include <signal.h>
 #include <sys/wait.h>
 
 struct SubprocessWaiter {
