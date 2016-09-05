--- pxe.cc.orig	2003-02-02 12:39:26 UTC
+++ pxe.cc
@@ -208,6 +208,31 @@ int StartPxeService(const char *configfi
 	return(retval);
 }
 
+/******************************************************************************
+ * DoSetUID - set uid and gid                                                 *
+ ******************************************************************************/
+void DoSetUID()
+{
+	// set the UID/GID to a low user
+#ifndef NO_SUID
+	struct passwd *pw;
+	pw = getpwnam(SETUID);
+
+	if(NULL == pw)
+		std::cout << "Unable to find passwd entry for " << SETUID
+		     << ", continuing with user id " << getuid() << "\n";
+	else
+	{
+		if((-1 == setgid(pw->pw_gid)) || (-1 == setegid(pw->pw_gid)))
+			std::cout << "Unable to change group id, continuing with group id "
+			     << getgid() << "\n";
+		if((-1 == setuid(pw->pw_uid)) || (-1 == seteuid(pw->pw_uid)))
+			std::cout << "Unable to change user id, continuing with user id "
+			     << getuid() << "\n";
+	}
+#endif
+}
+
 
 /******************************************************************************
  * main - kick things off and do cool things                                  *
@@ -247,6 +272,15 @@ int main(int argc, char **argv)
 	}
 	debug.close();
 
+	// check to see if the daemon is already running
+	chk = open(LOCKFILE, O_WRONLY|O_CREAT|O_EXCL, 0644);
+	if(-1 == chk)
+	{
+		std::cerr << "PXE daemon already running, or left-over pid file " << LOCKFILE << " exists?\n";
+		std::cerr << "Aborting startup.\n";
+		return(-1);
+	}
+
 	// redirect the file descriptors
 	if (0 == _debug) {
 		debug.open("/dev/null", std::ios::out);
@@ -258,34 +292,6 @@ int main(int argc, char **argv)
 		debug.close();
 	}
 
-
-	// set the UID/GID to a low user
-#ifndef NO_SUID
-	struct passwd *pw;
-	pw = getpwnam(SETUID);
-
-	if(NULL == pw)
-		std::cout << "Unable to find passwd entry for " << SETUID
-		     << ", continuing with user id " << getuid() << "\n";
-	else
-	{
-		if((-1 == setgid(pw->pw_gid)) || (-1 == setegid(pw->pw_gid)))
-			std::cout << "Unable to change group id, continuing with group id "
-			     << getgid() << "\n";
-		if((-1 == setuid(pw->pw_uid)) || (-1 == seteuid(pw->pw_uid)))
-			std::cout << "Unable to change user id, continuing with user id "
-			     << getuid() << "\n";
-	}
-#endif
-
-	// check to see if the daemon is already running
-	chk = open(LOCKFILE, O_WRONLY|O_CREAT|O_EXCL, 0644);
-	if(-1 == chk)
-	{
-		std::cerr << "PXE daemon already running\n";
-		return(-1);
-	}
-
 	// if not in debug mode, fork and go
 	if (0 == _debug) {
 		signal(SIGCHLD, SIG_IGN);
@@ -320,6 +326,7 @@ int main(int argc, char **argv)
 				}
 				close(chk);
 
+				DoSetUID;
 				StartPxeService(configfile);
 
 				exit(0);
@@ -328,6 +335,7 @@ int main(int argc, char **argv)
 		}
 
 	} else { // debug
+		DoSetUID;
 		StartPxeService(configfile);
 	}
 	
