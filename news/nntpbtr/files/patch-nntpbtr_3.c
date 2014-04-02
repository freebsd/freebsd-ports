--- nntpbtr.c.orig	2014-03-29 11:51:17.000000000 -0400
+++ nntpbtr.c	2014-03-29 11:55:16.000000000 -0400
@@ -88,6 +88,14 @@
 char *mktemp();
 char *malloc();
 
+void qsaveunread();
+void readarticle();
+void getnewnews();
+void goodbye();
+void get_time();
+void getlock();
+void unlock();
+
 int  rnum = 0, anum = 0;
 
 #ifdef SIGTTIN
@@ -106,7 +114,7 @@
  *	Save all unreaded articles in art. list file.
  */
 
-qsaveunread()
+void qsaveunread()
 {
 	if( intflag++ )
 		return;
@@ -381,7 +389,7 @@
  *	Then get implicit lock of host...
  */
 
-getlock(host,oldtime)
+void getlock(host,oldtime)
 	char *host, *oldtime;
 {
 	time_t tim;
@@ -428,7 +436,7 @@
 }
 
 
-unlock(host)
+void unlock(host)
 	char *host;
 {
 	int i;
@@ -453,7 +461,7 @@
 }
 
 
-get_time(host,newtime)
+void get_time(host,newtime)
 	char *host, *newtime;
 {
 	int server, i;
@@ -520,7 +528,7 @@
 /*	Normal goodbye talk
  */
 
-goodbye()
+void goodbye()
 {
 	char string[NNTP_STRLEN+1];
 
@@ -741,7 +749,7 @@
  *	If channel fail - reconnect.
  */
 
-readarticle()
+void readarticle()
 {
 	int incore, n;
 	char *endart, *line;
@@ -914,7 +922,7 @@
  *	from time of last session.
  */
 
-getnewnews()
+void getnewnews()
 {
 	int n;
 	char string[NNTP_STRLEN+1];
