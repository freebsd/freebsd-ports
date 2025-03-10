--- rinetd.c.orig	2024-12-09 14:53:18 UTC
+++ rinetd.c
@@ -12,6 +12,7 @@
 #include <netinet/in.h>
 #include <getopt.h>
 #include <errno.h>
+#include <poll.h>
 #define INVALID_SOCKET (-1)
 #include <sys/time.h>
 #endif /* WIN32 */
@@ -94,6 +95,7 @@ void Sleep(long ms)
 #include "match.h"
 
 SOCKET *seFds = 0;
+static int first_set = 0;
 /* In network order, for network purposes */
 struct in_addr *seLocalAddrs = 0;
 unsigned short *seLocalPorts = 0;
@@ -243,6 +245,7 @@ int main(int argc, char *argv[])
 			signal(SIGHUP, hup);
 #endif /* WIN32 */
 			signal(SIGTERM, term);
+			setsid();
 			initArrays();
 			readConfiguration();
 			RegisterPID();
@@ -646,6 +649,7 @@ void readConfiguration(void)
 			}
 		}
 	}
+	fclose(in);
 	/* Open the log file */
 	if (logFile) {
 		fclose(logFile);
@@ -750,15 +754,82 @@ void handleAccept(int i);
 void openLocalFd(int se, int i);
 int getAddress(char *host, struct in_addr *iaddr);
 
+inline void poll_init_fds(struct pollfd *pfds, int size) {
+	int i;
+
+	memset(pfds, 0, sizeof(struct pollfd) * size);
+	first_set = 1;
+	for(i = 0; i < size; i++) 
+		pfds[i].fd = -1;
+}
+
+inline int poll_set_fd(struct pollfd *pfds, int size, int count, 
+		 int fd, short int ev) {
+#ifdef _NEW_POLL_SET_FD
+	if(first_set) {
+		pfds[count].fd = fd;
+		pfds[count].events |= ev;
+		first_set = 0;
+		return 0;
+	}
+	if(pfds[count].fd != fd && !first_set) {
+		count++;
+	}
+
+	pfds[count].fd = fd;
+	pfds[count].events |= ev;
+	
+	return count;
+#else
+	int i;
+	
+	for(i = 0; i < size; i++) {
+		if(pfds[i].fd == -1) {
+			pfds[i].fd = fd;
+			pfds[i].events |= ev;
+			count++;
+			break;
+		}
+		if(pfds[i].fd == fd) {
+			pfds[i].events |= ev;
+			break;
+		}
+	}
+
+	return count;
+#endif
+}
+
+int poll_fd_isset(struct pollfd *pfds, int nfds, int fd, short event) {
+	int i;
+
+	for(i = 0; i < nfds; i++) {
+		if(pfds[i].fd == fd)
+			return pfds[i].revents & event;
+	}
+
+	return 0;
+}
+
 void selectPass(void) {
 	int i;
-	fd_set readfds, writefds;
-	FD_ZERO(&readfds);
-	FD_ZERO(&writefds);
+	int nfds = 0;
+	int total = 0;
+	static struct pollfd *pfds = NULL;
+	
 	/* Server sockets */
+	total = seTotal + (coTotal * 2);
+	
+	if(!pfds) {
+		pfds = malloc(sizeof(struct pollfd) * total);
+	}
+	
+	poll_init_fds(pfds, total);
+	
 	for (i = 0; (i < seTotal); i++) {
 		if (seFds[i] != INVALID_SOCKET) {
-			FD_SET(seFds[i], &readfds);
+			//FD_SET(seFds[i], &readfds)
+			nfds = poll_set_fd(pfds, total, nfds, seFds[i], POLLIN);
 		}
 	}
 	/* Connection sockets */
@@ -768,35 +839,47 @@ void selectPass(void) {
 		}
 		if (coClosing[i]) {
 			if (!reClosed[i]) {
-				FD_SET(reFds[i], &writefds);
+				//FD_SET(reFds[i], &writefds);
+				nfds = poll_set_fd(pfds, total, nfds, 
+					    reFds[i], POLLOUT);
 			}	
-			if (!loClosed[i]) {
-				FD_SET(loFds[i], &writefds);
-			}	
 		}
 		/* Get more input if we have room for it */
 		if ((!reClosed[i]) && (coInputRPos[i] < bufferSpace)) {
-			FD_SET(reFds[i], &readfds);
+			//FD_SET(reFds[i], &readfds);
+			nfds = poll_set_fd(pfds, total, nfds, reFds[i], POLLIN);
 		}
 		/* Send more output if we have any */	
 		if ((!reClosed[i]) && (coOutputWPos[i] < coOutputRPos[i])) {
-			FD_SET(reFds[i], &writefds);
+			//FD_SET(reFds[i], &writefds);
+			nfds = poll_set_fd(pfds, total, nfds, reFds[i], POLLOUT);
 		}	
+		if (coClosing[i]) {
+			if (!loClosed[i]) {
+				//FD_SET(loFds[i], &writefds);
+				nfds = poll_set_fd(pfds, total, nfds,
+					    loFds[i], POLLOUT);
+			}
+		}
 		/* Accept more output from the local 
 			server if there's room */
 		if ((!loClosed[i]) && (coOutputRPos[i] < bufferSpace)) {
-			FD_SET(loFds[i], &readfds);
+			//FD_SET(loFds[i], &readfds);
+			 nfds = poll_set_fd(pfds, total, nfds, loFds[i], POLLIN);
 		}
 		/* Send more input to the local server 
 			if we have any */
 		if ((!loClosed[i]) && (coInputWPos[i] < coInputRPos[i])) {
-			FD_SET(loFds[i], &writefds);
+			//FD_SET(loFds[i], &writefds);
+			nfds = poll_set_fd(pfds, total, nfds, loFds[i], POLLOUT);
 		}	
 	}
-	select(maxfd + 1, &readfds, &writefds, 0, 0);
+	//select(maxfd + 1, &readfds, &writefds, 0, 0);
+	poll(pfds, nfds + 1, -1);
 	for (i = 0; (i < seTotal); i++) {
 		if (seFds[i] != -1) {
-			if (FD_ISSET(seFds[i], &readfds)) {
+			//if (FD_ISSET(seFds[i], &readfds)) {
+			if (poll_fd_isset(pfds, nfds, seFds[i], POLLIN)) {
 				handleAccept(i);
 			}
 		}
@@ -806,22 +889,26 @@ void selectPass(void) {
 			continue;
 		}
 		if (!reClosed[i]) {
-			if (FD_ISSET(reFds[i], &readfds)) {
+			//if (FD_ISSET(reFds[i], &readfds)) {
+			if (poll_fd_isset(pfds, nfds, reFds[i], POLLIN)) {
 				handleRemoteRead(i);
 			}
 		}
 		if (!reClosed[i]) {
-			if (FD_ISSET(reFds[i], &writefds)) {
+			//if (FD_ISSET(reFds[i], &writefds)) {
+			if (poll_fd_isset(pfds, nfds, reFds[i], POLLOUT)) {
 				handleRemoteWrite(i);
 			}
 		}
 		if (!loClosed[i]) {
-			if (FD_ISSET(loFds[i], &readfds)) {
+			//if (FD_ISSET(loFds[i], &readfds)) {
+			if (poll_fd_isset(pfds, nfds, loFds[i], POLLIN)) {
 				handleLocalRead(i);
 			}
 		}
 		if (!loClosed[i]) {
-			if (FD_ISSET(loFds[i], &writefds)) {
+			//if (FD_ISSET(loFds[i], &writefds)) {
+			if (poll_fd_isset(pfds, nfds, loFds[i], POLLOUT)) {
 				handleLocalWrite(i);
 			}
 		}
