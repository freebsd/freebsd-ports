--- session.c.orig	Sat Aug  2 11:26:38 2003
+++ session.c	Thu Nov  2 13:35:27 2006
@@ -59,6 +59,7 @@
 	curr_session->method = template->method;
 	curr_session->sock = template->sock;
 	curr_session->peer = template->peer;
+	curr_session->me = template->me;
 	curr_session->timeout = template->timeout;
 	curr_session->retries = template->retries;
 	curr_session->connect = template->connect;
@@ -302,7 +303,6 @@
 	int active = 0, pending = 0;
 
 	timerclear(&earliest);
-
 	/*
 	 * For each request outstanding, add it's socket to the readfds,
 	 * and if it is the earliest timeout to expire, mark it as lowest.
@@ -352,7 +352,6 @@
 	int reqid;
 {
 	REQUEST *sr;
-
 	if (reqid == 0) /* for single request per session (like tcp or icmp) */
 		return sd->request;
 
@@ -443,7 +442,6 @@
 	int reqid;
 
 	gettimeofday(&now, NULL);
-
 	/*
 	 * For each request outstanding, check to see if it has expired.
 	 */
