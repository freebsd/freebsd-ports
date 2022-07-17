--- src/client.c.orig	2022-07-17 20:37:11 UTC
+++ src/client.c
@@ -77,6 +77,8 @@ NOEXPORT int redirect(CLI *);
 NOEXPORT void print_bound_address(CLI *);
 NOEXPORT void reset(SOCKET, const char *);
 
+extern char **environ;
+
 /* allocate local data structure for the new thread */
 CLI *alloc_client_session(SERVICE_OPTIONS *opt, SOCKET rfd, SOCKET wfd) {
     static unsigned long long seq=0;
