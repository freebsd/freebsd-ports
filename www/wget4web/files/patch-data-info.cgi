--- data/info.cgi.orig	Fri Mar 11 18:29:17 2005
+++ data/info.cgi	Fri Mar 11 18:30:05 2005
@@ -1,11 +1,11 @@
 # Directory for Wget logs
-$logsdir = "/home/download/logs";
+$logsdir = "%%LOGSDIR%%";
 
 # Directory for tasks for wget
-$tasksdir = "/home/download/tasks";
+$tasksdir = "%%TASKDIR%%";
 
 # There save downloading files
-$filesdir = "/home/download/files";
+$filesdir = "%%FILESDIR%%";
 
 # Perion of refresh statistic page (in second)
 $refreshstat = 30;
