--- ./misc.c	2009-08-08 20:54:21.000000000 -0400
+++ ../../pam_ssh_agent_auth-0.9.3.fixed/misc.c	2011-10-10 13:10:35.866387792 -0400
@@ -84,13 +84,13 @@
 		return (-1);
 	}
 	if (val & O_NONBLOCK) {
-		verbose("fd %d is O_NONBLOCK", fd);
+		pam_ssh_auth_verbose("fd %d is O_NONBLOCK", fd);
 		return (0);
 	}
-	verbose("fd %d setting O_NONBLOCK", fd);
+	pam_ssh_auth_verbose("fd %d setting O_NONBLOCK", fd);
 	val |= O_NONBLOCK;
 	if (fcntl(fd, F_SETFL, val) == -1) {
-		verbose("fcntl(%d, F_SETFL, O_NONBLOCK): %s", fd,
+		pam_ssh_auth_verbose("fcntl(%d, F_SETFL, O_NONBLOCK): %s", fd,
 		    strerror(errno));
 		return (-1);
 	}
@@ -108,13 +108,13 @@
 		return (-1);
 	}
 	if (!(val & O_NONBLOCK)) {
-		verbose("fd %d is not O_NONBLOCK", fd);
+		pam_ssh_auth_verbose("fd %d is not O_NONBLOCK", fd);
 		return (0);
 	}
-	verbose("fd %d clearing O_NONBLOCK", fd);
+	pam_ssh_auth_verbose("fd %d clearing O_NONBLOCK", fd);
 	val &= ~O_NONBLOCK;
 	if (fcntl(fd, F_SETFL, val) == -1) {
-		verbose("fcntl(%d, F_SETFL, ~O_NONBLOCK): %s",
+		pam_ssh_auth_verbose("fcntl(%d, F_SETFL, ~O_NONBLOCK): %s",
 		    fd, strerror(errno));
 		return (-1);
 	}
@@ -138,15 +138,15 @@
 
 	optlen = sizeof opt;
 	if (getsockopt(fd, IPPROTO_TCP, TCP_NODELAY, &opt, &optlen) == -1) {
-		verbose("getsockopt TCP_NODELAY: %.100s", strerror(errno));
+		pam_ssh_auth_verbose("getsockopt TCP_NODELAY: %.100s", strerror(errno));
 		return;
 	}
 	if (opt == 1) {
-		verbose("fd %d is TCP_NODELAY", fd);
+		pam_ssh_auth_verbose("fd %d is TCP_NODELAY", fd);
 		return;
 	}
 	opt = 1;
-	verbose("fd %d setting TCP_NODELAY", fd);
+	pam_ssh_auth_verbose("fd %d setting TCP_NODELAY", fd);
 	if (setsockopt(fd, IPPROTO_TCP, TCP_NODELAY, &opt, sizeof opt) == -1)
 		logerror("setsockopt TCP_NODELAY: %.100s", strerror(errno));
 }
@@ -367,7 +367,7 @@
 		return(xstrdup(host));
 	if (asprintf(&hoststr, "[%s]:%d", host, (int)port) < 0)
 		fatal("put_host_port: asprintf: %s", strerror(errno));
-	verbose("put_host_port: %s", hoststr);
+	pam_ssh_auth_verbose("put_host_port: %s", hoststr);
 	return hoststr;
 }
 
@@ -631,7 +631,7 @@
 		if (buf[strlen(buf) - 1] == '\n' || feof(f)) {
 			return 0;
 		} else {
-			verbose("%s: %s line %lu exceeds size limit", __func__,
+			pam_ssh_auth_verbose("%s: %s line %lu exceeds size limit", __func__,
 			    filename, *lineno);
 			/* discard remainder of line */
 			while (fgetc(f) != '\n' && !feof(f))
@@ -662,16 +662,16 @@
 				break;
 		}
 	} else {
-		verbose("%s: invalid tunnel %u", __func__, tun);
+		pam_ssh_auth_verbose("%s: invalid tunnel %u", __func__, tun);
 		return (-1);
 	}
 
 	if (fd < 0) {
-		verbose("%s: %s open failed: %s", __func__, name, strerror(errno));
+		pam_ssh_auth_verbose("%s: %s open failed: %s", __func__, name, strerror(errno));
 		return (-1);
 	}
 
-	verbose("%s: %s mode %d fd %d", __func__, name, mode, fd);
+	pam_ssh_auth_verbose("%s: %s mode %d fd %d", __func__, name, mode, fd);
 
 	/* Set the tunnel device operation mode */
 	snprintf(ifr.ifr_name, sizeof(ifr.ifr_name), "tun%d", tun);
@@ -703,7 +703,7 @@
 		close(fd);
 	if (sock >= 0)
 		close(sock);
-	verbose("%s: failed to set %s mode %d: %s", __func__, name,
+	pam_ssh_auth_verbose("%s: failed to set %s mode %d: %s", __func__, name,
 	    mode, strerror(errno));
 	return (-1);
 #else
