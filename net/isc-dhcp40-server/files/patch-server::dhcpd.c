--- server/dhcpd.c.orig	Thu Jun 10 19:59:52 2004
+++ server/dhcpd.c	Fri Jun 25 15:49:09 2004
@@ -47,6 +47,22 @@
 #include "version.h"
 #include <omapip/omapip_p.h>
 
+#if defined (PARANOIA)
+#include <sys/types.h>
+#include <unistd.h>
+#include <pwd.h>
+/* get around the ISC declaration of group */
+#define group real_group 
+#include <grp.h>
+#undef group
+#endif /* PARANOIA */
+#if defined (JAIL)
+#include <sys/param.h>
+#include <sys/jail.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
+#endif /* JAIL */
+
 static void usage PROTO ((void));
 
 TIME cur_time;
@@ -195,6 +211,35 @@
 	omapi_object_dereference (&listener, MDL);
 }
 
+#if defined (PARANOIA)
+/* to be used in one of two possible scenarios */
+static void setup_chroot (char *chroot_dir)
+{
+	if (geteuid ())
+		log_fatal ("you must be root to use chroot");
+	if (chroot (chroot_dir))
+		log_fatal ("chroot(\"%s\"): %m", chroot_dir);
+	if (chdir ("/"))
+		/* probably permission denied */
+		log_fatal ("chdir(\"/\"): %m");
+}
+#endif /* PARANOIA */
+
+#if defined (JAIL)
+static void setup_jail (char *chroot_dir, char *hostname, u_int32_t ip_number)
+{
+      struct jail j;
+
+      j.version = 0;
+      j.path = chroot_dir;
+      j.hostname = hostname;
+      j.ip_number = ip_number;
+
+      if (jail (&j) < 0)
+              log_fatal ("jail(%s, %s): %m", chroot_dir, hostname);
+}
+#endif /* JAIL */
+
 int main (argc, argv, envp)
 	int argc;
 	char **argv, **envp;
@@ -227,6 +272,25 @@
 	char *traceinfile = (char *)0;
 	char *traceoutfile = (char *)0;
 #endif
+#if defined (PARANOIA)
+	char *set_user   = 0;
+	char *set_group  = 0;
+	uid_t set_uid = 0;
+	gid_t set_gid = 0;
+	int early_chroot = 0;
+	int no_dhcpd_user = 0;
+	int no_dhcpd_group = 0;
+#endif /* PARANOIA */
+#if defined (PARANOIA) || defined (JAIL)
+	char *set_chroot = 0;
+	int no_dhcpd_chroot = 0;
+#endif /* PARANOIA || JAIL */
+#if defined (JAIL)
+	char *set_jail = 0;
+	u_int32_t jail_ip_address = 0; /* Good as long as it's IPv4 ... */
+	int no_dhcpd_jail = 0;
+	char *s2;
+#endif /* JAIL */
 
 	/* Make sure we have stdin, stdout and stderr. */
 	status = open ("/dev/null", O_RDWR);
@@ -289,6 +353,39 @@
 			if (++i == argc)
 				usage ();
 			server = argv [i];
+#if defined (PARANOIA)
+		} else if (!strcmp (argv [i], "-user")) {
+			if (++i == argc)
+				usage ();
+			set_user = argv [i];
+			no_dhcpd_user = 1;
+		} else if (!strcmp (argv [i], "-group")) {
+			if (++i == argc)
+				usage ();
+			set_group = argv [i];
+			no_dhcpd_group = 1;
+		} else if (!strcmp (argv [i], "-early_chroot")) {
+			early_chroot = 1;
+#endif /* PARANOIA */
+#if defined (PARANOIA) || defined (JAIL)
+		} else if (!strcmp (argv [i], "-chroot")) {
+			if (++i == argc)
+				usage ();
+			set_chroot = argv [i];
+			no_dhcpd_chroot = 1;
+#endif /* PARANOIA || JAIL */
+#if defined (JAIL)
+		} else if (!strcmp (argv [i], "-jail")) {
+			if (++i == argc)
+				usage ();
+			set_jail = argv [i];
+			if (++i == argc)
+				usage ();
+			if (ascii2addr (AF_INET, argv[i], &jail_ip_address) < 0)
+				log_fatal ("invalid ip address: %s", argv[i]);
+			jail_ip_address = ntohl (jail_ip_address);
+			no_dhcpd_jail = 1;
+#endif /* JAIL */
 		} else if (!strcmp (argv [i], "-cf")) {
 			if (++i == argc)
 				usage ();
@@ -366,6 +463,28 @@
 	if (!no_dhcpd_pid && (s = getenv ("PATH_DHCPD_PID"))) {
 		path_dhcpd_pid = s;
 	}
+#if defined (PARANOIA)
+	if (!no_dhcpd_user && (s = getenv ("DHCPD_USER"))) {
+		set_user = s;
+	}
+	if (!no_dhcpd_group && (s = getenv ("DHCPD_GROUP"))) {
+		set_group = s;
+	}
+#endif /* PARANOIA */
+#if defined (PARANOIA) || defined (JAIL)
+	if (!no_dhcpd_chroot && (s = getenv ("PATH_DHCPD_CHROOT"))) {
+		set_chroot = s;
+	}
+#endif /* PARANOIA || JAIL */
+#if defined (JAIL)
+	if (!no_dhcpd_jail && (s = getenv ("DHCPD_JAIL_HOSTNAME")) &&
+	    (s2 = getenv ("DHCPD_JAIL_IPADDRESS"))) {
+		set_jail = s;
+		if (ascii2addr (AF_INET, s2, &jail_ip_address) < 0)
+			log_fatal ("invalid ip address: %s", s2);
+		jail_ip_address = ntohl (jail_ip_address);
+	}
+#endif /* JAIL */
 
 	if (!quiet) {
 		log_info ("%s %s", message, DHCP_VERSION);
@@ -388,6 +507,57 @@
 					     trace_seed_stop, MDL);
 #endif
 
+#if defined (PARANOIA)
+	/* get user and group info if those options were given */
+	if (set_user) {
+		struct passwd *tmp_pwd;
+
+		if (geteuid ())
+			log_fatal ("you must be root to set user");
+
+		if (!(tmp_pwd = getpwnam (set_user)))
+			log_fatal ("no such user: %s", set_user);
+
+		set_uid = tmp_pwd->pw_uid;
+
+		/* use the user's group as the default gid */
+		if (!set_group)
+			set_gid = tmp_pwd->pw_gid;
+	}
+
+	if (set_group) {
+/* get around the ISC declaration of group */
+#define group real_group
+		struct group *tmp_grp;
+
+		if (geteuid ())
+			log_fatal ("you must be root to set group");
+
+		if (!(tmp_grp = getgrnam (set_group)))
+			log_fatal ("no such group: %s", set_group);
+
+		set_gid = tmp_grp->gr_gid;
+#undef group
+	}
+#endif /* PARANOIA */
+#if defined (JAIL)
+	if (set_jail) {
+		/* Initialize icmp support... */
+		if (!cftest && !lftest)
+			icmp_startup (1, lease_pinged);
+		if(!set_chroot)
+			set_chroot = "/";
+		setup_jail (set_chroot, set_jail, jail_ip_address);
+	}
+#endif /* JAIL */
+#if defined (PARANOIA) && defined (JAIL)
+	else
+#endif /* PARANOIA && JAIL */
+#if defined (PARANOIA)
+	if (early_chroot && set_chroot)
+		setup_chroot (set_chroot);
+#endif /* PARANOIA */
+
 	/* Default to the DHCP/BOOTP port. */
 	if (!local_port)
 	{
@@ -462,6 +632,9 @@
 #endif
 
 	/* Initialize icmp support... */
+#if defined (JAIL)
+	if (!set_jail)
+#endif /* JAIL */
 	if (!cftest && !lftest)
 		icmp_startup (1, lease_pinged);
 
@@ -491,6 +664,14 @@
 
 	postconf_initialization (quiet);
 
+#if defined (PARANOIA)
+#if defined (JAIL)
+	if (!set_jail)
+#endif /* JAIL */
+	if (!early_chroot && set_chroot)
+		setup_chroot (set_chroot);
+#endif /* PARANOIA */
+
         /* test option should cause an early exit */
  	if (cftest && !lftest) 
  		exit(0);
@@ -533,7 +714,22 @@
 		else if (pid)
 			exit (0);
 	}
+  
+#if defined (PARANOIA)
+	/* change uid to the specified one */
+	if (set_gid) {
+		if (setgroups (0, (void *)0))
+			log_fatal ("setgroups: %m");
+		if (setgid (set_gid))
+			log_fatal ("setgid(%d): %m", (int) set_gid);
+	}
 
+	if (set_uid) {
+		if (setuid (set_uid))
+			log_fatal ("setuid(%d): %m", (int) set_uid);
+	}
+#endif /* PARANOIA */
+  
 	/* Read previous pid file. */
 	if ((i = open (path_dhcpd_pid, O_RDONLY)) >= 0) {
 		status = read (i, pbuf, (sizeof pbuf) - 1);
@@ -877,8 +1073,24 @@
 	log_info (copyright);
 	log_info (arr);
 
-	log_fatal ("Usage: dhcpd [-p <UDP port #>] [-d] [-f]%s%s%s%s",
+	log_fatal ("Usage: dhcpd [-p <UDP port #>] [-d] [-f]%s%s%s%s%s%s%s",
 		   "\n             [-cf config-file] [-lf lease-file]",
+
+#if defined (PARANOIA)
+		   /* meld into the following string */
+		   "\n             [-user user] [-group group]",
+		   "\n             [-chroot dir] [-early_chroot]",
+#else /* PARANOIA */
+		   "", "",
+#endif /* PARANOIA */
+
+#if defined (JAIL)
+		   /* then also these ones */
+		   "\n             [-jail name ip]",
+#else /* JAIL */
+		   "",
+#endif /* JAIL */
+
 #if defined (TRACING)
 		   "\n		   [-tf trace-output-file]",
 		   "\n		   [-play trace-input-file]",
