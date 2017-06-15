--- tests/regression/kernel/select_poll_epoll.c.orig	2016-11-29 22:48:37 UTC
+++ tests/regression/kernel/select_poll_epoll.c
@@ -10,7 +10,9 @@
 #include <string.h>
 #include <stddef.h>
 #include <sys/select.h>
+#if !defined(__FreeBSD__)
 #include <sys/epoll.h>
+#endif
 #include <popt.h>
 #include <sys/time.h>
 #include <sys/resource.h>
@@ -249,6 +251,7 @@ void test_ppoll_big(void)
 	return;
 }
 
+#if !defined(__FreeBSD__)
 void test_epoll(void)
 {
 	int ret, epollfd;
@@ -332,6 +335,7 @@ void test_pepoll(void)
 end:
 	return;
 }
+#endif
 
 void run_working_cases(void)
 {
@@ -356,8 +360,10 @@ void run_working_cases(void)
 	test_select_big();
 	test_poll();
 	test_ppoll();
+#if !defined(__FreeBSD__)
 	test_epoll();
 	test_pepoll();
+#endif
 
 	if (timeout > 0) {
 		ret = close(pipe_fds[0]);
@@ -458,7 +464,11 @@ void pselect_fd_too_big(void)
 	}
 
 	FD_SET(fd2, (fd_set *) &rfds);
+#if defined(__FreeBSD__)
+	ret = __syscall(SYS_pselect, fd2 + 1, &rfds, NULL, NULL, NULL, NULL);
+#else
 	ret = syscall(SYS_pselect6, fd2 + 1, &rfds, NULL, NULL, NULL, NULL);
+#endif
 
 	if (ret == -1) {
 		perror("# pselect()");
@@ -487,9 +497,13 @@ void pselect_invalid_pointer(void)
 
 	FD_ZERO(&rfds);
 	FD_SET(wait_fd, &rfds);
-
+#if defined(__FreeBSD__)
+	ret = __syscall(SYS_pselect, 1, &rfds, (fd_set *) invalid, NULL, NULL,
+			NULL);
+#else
 	ret = syscall(SYS_pselect6, 1, &rfds, (fd_set *) invalid, NULL, NULL,
 			NULL);
+#endif
 
 	if (ret == -1) {
 		perror("# pselect()");
@@ -505,6 +519,7 @@ void pselect_invalid_pointer(void)
 
 }
 
+#if !defined(__FreeBSD__)
 /*
  * Pass an invalid pointer to epoll_pwait, should fail with
  * "Bad address", the event returns 0 FDs.
@@ -591,6 +606,7 @@ void epoll_pwait_int_max(void)
 end:
 	return;
 }
+#endif
 
 void *ppoll_writer(void *arg)
 {
@@ -700,6 +716,7 @@ void ppoll_concurrent_write(void)
 	return;
 }
 
+#if !defined(__FreeBSD__)
 void *epoll_pwait_writer(void *addr)
 {
 	srand(time(NULL));
@@ -795,6 +812,7 @@ end_unmap:
 end:
 	return;
 }
+#endif
 
 void usage(poptContext optCon, int exitcode, char *error, char *addl)
 {
@@ -906,18 +924,20 @@ int main(int argc, const char **argv)
 	case 7:
 		ppoll_fds_ulong_max();
 		break;
+#if !defined(__FreeBSD__)
 	case 8:
 		epoll_pwait_invalid_pointer();
 		break;
 	case 9:
 		epoll_pwait_int_max();
 		break;
-	case 10:
-		ppoll_concurrent_write();
-		break;
 	case 11:
 		epoll_pwait_concurrent_munmap();
 		break;
+#endif
+	case 10:
+		ppoll_concurrent_write();
+		break;
 	default:
 		poptPrintUsage(optCon, stderr, 0);
 		ret = -1;
