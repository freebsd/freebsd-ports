--- rawGnu.cpp.orig	Wed Jan  7 22:24:01 1998
+++ rawGnu.cpp	Wed Mar 17 15:43:43 2004
@@ -54,7 +54,7 @@
   QString command = rawCommand->text();
 
   string temp;
-  temp = command;
+  temp = command.ascii();
 
   // issue command
   gnuInt->doRawCommand(temp);
