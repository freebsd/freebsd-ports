--- spread.c	Sun Nov 10 00:17:59 2002
+++ spread.c	Sun Nov 10 00:18:42 2002
@@ -65,6 +65,7 @@
 
 static	void	Invalid_privilege_decrease(char *user, char *group);
 static	void	Usage(int argc, char *argv[]);
+static	void	writepidfile();
 
 /* auth-null.c: */
 void null_init(void);
@@ -144,6 +145,8 @@
 
 #endif	/* ARCH_PC_WIN95 */
 
+	writepidfile();
+
         /* initialize each valid authentication protocol */
         null_init();
         ip_init();
@@ -193,6 +196,20 @@
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
