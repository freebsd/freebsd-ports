--- module-dvbapi.c.orig	2015-10-10 17:22:23 UTC
+++ module-dvbapi.c
@@ -3,7 +3,6 @@
 #include "globals.h"
 
 #ifdef HAVE_DVBAPI
-
 #include "module-dvbapi.h"
 #include "module-cacheex.h"
 #include "module-dvbapi-azbox.h"
@@ -4290,6 +4289,7 @@ static void *dvbapi_main_local(void *cli
 {
 	int32_t i, j;
 	struct s_client *client = (struct s_client *) cli;
+	const char pmt_server_socket[]="/tmp/.listen.camd.socket";
 	client->thread = pthread_self();
 	SAFE_SETSPECIFIC(getclient, cli);
 
@@ -4298,11 +4298,9 @@ static void *dvbapi_main_local(void *cli
 	int32_t maxpfdsize = (MAX_DEMUX * maxfilter) + MAX_DEMUX + 2;
 	struct pollfd pfd2[maxpfdsize];
 	struct timeb start, end;  // start time poll, end time poll
-#define PMT_SERVER_SOCKET "/tmp/.listen.camd.socket"
 	struct sockaddr_un saddr;
 	saddr.sun_family = AF_UNIX;
-	strncpy(saddr.sun_path, PMT_SERVER_SOCKET, 107);
-	saddr.sun_path[107] = '\0';
+	strncpy(saddr.sun_path, pmt_server_socket, sizeof(saddr.sun_path)/sizeof(saddr.sun_path[0]));
 
 	int32_t rc, pfdcount, g, connfd, clilen;
 	int32_t ids[maxpfdsize], fdn[maxpfdsize], type[maxpfdsize];
@@ -4366,13 +4364,15 @@ static void *dvbapi_main_local(void *cli
 		signal_action.sa_flags = SA_RESTART;
 		sigaction(SIGRTMIN + 1, &signal_action, NULL);
 
+        /*
 		dir_fd = open(TMPDIR, O_RDONLY);
 		if(dir_fd >= 0)
 		{
 			fcntl(dir_fd, F_SETSIG, SIGRTMIN + 1);
 			fcntl(dir_fd, F_NOTIFY, DN_MODIFY | DN_CREATE | DN_DELETE | DN_MULTISHOT);
 			event_handler(SIGRTMIN + 1);
-		}
+		}*/
+        cs_log("Only PMT 4-6 supported on FreeBSD, sorry...");
 	}
 	else
 	{
