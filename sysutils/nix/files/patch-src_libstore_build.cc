--- src/libstore/build.cc.orig	2019-11-28 21:39:47 UTC
+++ src/libstore/build.cc
@@ -44,12 +44,16 @@
 #include <grp.h>
 
 /* Includes required for chroot support. */
-#if __linux__
+#if __linux__ || __FreeBSD__
 #include <sys/socket.h>
 #include <sys/ioctl.h>
 #include <net/if.h>
+#endif
+#if __linux__
 #include <netinet/ip.h>
 #include <sys/personality.h>
+#endif
+#if __linux__ || __FreeBSD__
 #include <sys/mman.h>
 #include <sched.h>
 #include <sys/param.h>
@@ -1943,7 +1947,7 @@ void DerivationGoal::startBuilder()
     /* If `build-users-group' is not empty, then we have to build as
        one of the members of that group. */
     if (settings.buildUsersGroup != "" && getuid() == 0) {
-#if defined(__linux__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
         buildUser = std::make_unique<UserLock>();
 
         /* Make sure that no other processes are executing under this
