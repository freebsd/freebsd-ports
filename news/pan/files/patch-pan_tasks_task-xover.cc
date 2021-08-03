--- pan/tasks/task-xover.cc.orig	2021-08-03 02:05:38 UTC
+++ pan/tasks/task-xover.cc
@@ -21,14 +21,11 @@
 #include <cassert>
 #include <cerrno>
 
-extern "C"
-{
 #define PROTOTYPES
 #include <stdio.h>
 #include <uulib/uudeview.h>
 #include <glib/gi18n.h>
 #include <gmime/gmime-utils.h>
-}
 
 #include <fstream>
 #include <iostream>
