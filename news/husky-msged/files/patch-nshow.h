--- ./nshow.h.orig	Fri Jan 24 15:28:13 2003
+++ ./nshow.h	Fri Jan 24 15:28:35 2003
@@ -11,7 +11,7 @@
 
 extern int groupmove;
 
-int InitScreen(void);
+int InitScreen(int draw_statbar);
 void AddHG(HotGroup * h, int num, int id, int x1, int y1, int x2, int y2);
 void BuildHotSpots(void);
 void KillHotSpots(void);
