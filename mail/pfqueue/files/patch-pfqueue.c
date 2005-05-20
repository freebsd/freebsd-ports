--- pfqueue.c.orig	Fri May 20 12:26:17 2005
+++ pfqueue.c	Fri May 20 19:21:56 2005
@@ -562,9 +562,10 @@
 
 // Sets the list window title
 void win_listtitle() {
+	char buf[BUF_SIZE];
+
 	wattron ( lwnd, A_BOLD );
 
-	char buf[BUF_SIZE];
 	sprintf ( buf, "Queue: '%s', %d message%s, %d tagged %s %s %s",
 			q_names[CURQ], NUMMSG, 
 			( NUMMSG != 1 ? "s" : "" ),
