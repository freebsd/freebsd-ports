--- spread.c	Thu Jun 19 00:31:23 2003
+++ spread.c	Mon Dec  8 20:55:41 2003
@@ -48,6 +48,8 @@
 #include <pwd.h>
 #include <unistd.h>
 #include <sys/types.h>
+#include <errno.h>
+#include <stdlib.h>
 #endif
 
 #ifdef	ARCH_PC_WIN95
@@ -65,6 +67,7 @@
 
 static	void	Invalid_privilege_decrease(char *user, char *group);
 static	void	Usage(int argc, char *argv[]);
+static	void	writepidfile();
 
 /* auth-null.c: */
 void null_init(void);
@@ -144,6 +147,11 @@
 
 #endif	/* ARCH_PC_WIN95 */
 
+	if (daemon(0,0) == -1)
+		Alarm( EXIT, "Spread: couldn't daemonise: %d", strerror(errno) );
+
+	writepidfile();
+
         /* initialize each valid authentication protocol */
         null_init();
         ip_init();
@@ -193,6 +201,20 @@
 	E_handle_events();
 
 	return 0;
+}
+
+static void
+writepidfile()
+{
+	char pidbuf[11];
+	int pidfd;
+
+	if ((pidfd = open(_PATH_SPREAD_PIDDIR "/spread.pid", O_RDWR | O_CREAT, 0644)) == -1)
+		Alarm( EXIT, "Spread: couldn't open pidfile for writing" );
+
+	snprintf(pidbuf, sizeof(pidbuf), "%ld\n", (long)getpid());
+	write(pidfd, pidbuf, strlen(pidbuf));
+	close(pidfd);
 }
 
 static  void    Print_help(void)
