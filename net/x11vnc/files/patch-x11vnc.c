--- src/x11vnc.c.orig	2019-01-05 13:22:11 UTC
+++ src/x11vnc.c
@@ -186,6 +186,10 @@ static void tsdo_timeout (int sig) {
 static pid_t ts_tasks[TASKMAX];
 static int ts_taskn = -1;
 
+MUTEX(clientMutex);
+MUTEX(inputMutex);
+MUTEX(pointerMutex);
+
 int tsdo(int port, int lsock, int *conn) {
 	int csock, rsock, i, db = 1;
 	pid_t pid;
