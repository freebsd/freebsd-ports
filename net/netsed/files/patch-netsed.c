--- netsed.c.orig	Fri Jan  5 18:58:22 2001
+++ netsed.c	Sun Aug 11 14:32:29 2002
@@ -2,6 +2,7 @@
 #include <unistd.h>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <sys/wait.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
 #include <fcntl.h>
@@ -45,11 +46,11 @@
   ERR("This will replace all occurences of pat1 with pat2 in matching packets.\n");
   ERR("Additional parameter (count) can be used to expire rule after 'count'\n");
   ERR("succesful substitutions. Eight-bit characters, including NULL and '/', can\n");
-  ERR("be passed using HTTP-alike hex escape sequences (eg. %%0a%%0d). Single '%%'\n");
-  ERR("can be reached by using '%%%%'. Examples:\n\n");
-  ERR("  's/anrew/mike/1'   - replace 'andrew' with 'mike' (once)\n");
-  ERR("  's/anrew/mike'     - replace all occurences of 'andrew' with 'mike'\n");
-  ERR("  's/anrew/mike%%00'  - replace 'andrew' with 'mike\\x00' (to keep orig. size)\n");
+  ERR("be passed using HTTP-alike hex escape sequences (eg. CRLF -> %%0a%%0d).\n");
+  ERR("Single '%%' can be reached by using '%%%%'. Examples:\n\n");
+  ERR("  's/andrew/mike/1'   - replace 'andrew' with 'mike' (once)\n");
+  ERR("  's/andrew/mike'     - replace all occurences of 'andrew' with 'mike'\n");
+  ERR("  's/andrew/mike%%00'  - replace 'andrew' with 'mike\\x00' (to keep orig. size)\n");
   ERR("  's/%%%%/%%2f/20'      - replace '%%' with '/' in first 20 packets\n\n");
   ERR("Rules are not working on cross-packet boundaries and are evaluated from\n");
   ERR("first to last not expired rule.\n");
@@ -134,8 +135,10 @@
 
 
 void bind_and_listen(int tcp,int port) {
+  int on=1;
   struct sockaddr_in laddr;
   lsock=socket(PF_INET,tcp ? SOCK_STREAM:SOCK_DGRAM,0);
+  setsockopt(lsock, SOL_SOCKET, SO_REUSEADDR, (char *)&on, sizeof(on));
   fcntl(lsock,F_SETFL,O_NONBLOCK);
   laddr.sin_family = PF_INET;
   laddr.sin_port = htons (port);
@@ -186,7 +189,6 @@
   rd=read(s1,buf,sizeof(buf));
   if (rd<0 && errno!=EAGAIN) return 0; // s1 not connected
   if (rd>0) {
-    fcntl(s2,F_SETFL,O_SYNC);
     printf("[+] Caught server -> client packet.\n");
     rd=sed_the_buffer(rd);
     if (write(s2,b2,rd)<=0) return 0; // not able to send
@@ -195,7 +197,6 @@
   rd=read(s2,buf,sizeof(buf));
   if (rd<0 && errno!=EAGAIN) return 0; // s2 not connected
   if (rd>0) {
-    fcntl(s1,F_SETFL,O_SYNC);
     printf("[+] Caught client -> server packet.\n");
     rd=sed_the_buffer(rd);
     if (write(s1,b2,rd)<=0) return 0; // not able to send
@@ -204,6 +205,14 @@
   return 1;
 }
 
+void sig_chld(int signo)
+{
+    pid_t  pid;
+    int    stat;
+    while ( (pid = waitpid(-1, &stat, WNOHANG)) > 0)
+	printf("child %d terminated\n", pid);
+    return;
+} 
 
 int main(int argc,char* argv[]) {
   int i;
@@ -242,7 +251,7 @@
   if (fixedhost && fixedport) printf("[+] Using fixed forwarding to %s:%s.\n",argv[3],argv[4]);
     else printf("[+] Using dynamic (transparent proxy) forwarding.\n");
   signal(SIGPIPE,SIG_IGN);
-  signal(SIGCHLD,SIG_IGN);
+  signal(SIGCHLD,sig_chld);
 
   // Am I bad coder?;>
 
