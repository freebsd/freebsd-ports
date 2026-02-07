--- src/common/lpd.c.orig
+++ src/common/lpd.c
@@ -64,7 +64,9 @@
  *
  ****************************************************************************/
 
+#ifdef DMALLOC
 	static char *malloc_area;
+#endif
 
 int main(int argc, char *argv[], char *envp[])
 {
@@ -359,9 +361,9 @@
 		first_scan = 0;
 	}
 
+#ifdef DMALLOC
 	malloc_area = sbrk(0);
 
-#ifdef DMALLOC
 	DEBUG1( "lpd: LOOP START - sbrk 0x%lx", (long)malloc_area );
 	{
 		extern int dmalloc_outfile_fd;
@@ -979,7 +981,6 @@
 * libwrap/tcp_wrappers:
 * draht@suse.de, Mon Jan 28 2002
 */
-		if( !unix_socket ){
 			struct request_info wrap_req;
 
 			request_init(&wrap_req, RQ_DAEMON, "lpd" , RQ_FILE, newsock, NULL);
@@ -993,7 +994,6 @@
 				close( newsock );
 				return;
 			}
-		}
 #endif
 
 		pid = Start_worker( "server", Service_connection, &args, newsock );
