--- FreeBSD/ProcessList.h	2011-03-17 20:50:04.000000000 +0200
+++ FreeBSD/ProcessList.h	2011-01-30 11:06:11.000000000 +0200
@@ -1,6 +1,7 @@
 /*
     KSysGuard, the KDE System Guard
    
+	Copyright (c) 2011 David Naylor <naylor.b.david@gmail.com>
 	Copyright (c) 1999 Chris Schlaeger <cs@kde.org>
     
     This program is free software; you can redistribute it and/or modify
@@ -22,15 +23,23 @@
 #ifndef _process_list_h_
 #define _process_list_h_
 
-void initProcessList(struct SensorModul* sm);
+struct SensorModul;
+
+void initProcessList(struct SensorModul *);
 void exitProcessList(void);
 
 int updateProcessList(void);
 
-void printProcessList(const char*);
-void printProcessListInfo(const char*);
-void printProcessCount(const char* cmd);
-void printProcessCountInfo(const char* cmd);
+void printProcessList(const char *);
+void printProcessListInfo(const char *);
+void printThreadList(const char *);
+void printThreadListInfo(const char *);
+
+void printProcessCount(const char *);
+void printProcessCountInfo(const char *);
+
+void printLastPID(const char *);
+void printLastPIDInfo(const char *);
 
 void killProcess(const char* cmd);
 void setPriority(const char* cmd);
