--- tools/zunitc/src/zunitc_impl.c.orig	2016-05-19 21:36:04 UTC
+++ tools/zunitc/src/zunitc_impl.c
@@ -36,6 +36,10 @@
 #include <sys/wait.h>
 #include <time.h>
 #include <unistd.h>
+#if defined(__FreeBSD__)
+#include <libgen.h>
+#include <signal.h>
+#endif
 
 #include "zunitc/zunitc_impl.h"
 #include "zunitc/zunitc.h"
@@ -1069,7 +1073,11 @@ spawn_test(struct zuc_test *test, void *
 	}
 	default: { /* parent */
 		ssize_t rc = 0;
+#if defined(__FreeBSD__)
+		int status;
+#else
 		siginfo_t info = {};
+#endif
 
 		close(g_ctx.fds[1]);
 		g_ctx.fds[1] = -1;
@@ -1081,11 +1089,39 @@ spawn_test(struct zuc_test *test, void *
 		close(g_ctx.fds[0]);
 		g_ctx.fds[0] = -1;
 
+#if defined(__FreeBSD__)
+		if (wait(&status) == -1) {
+			printf("%s:%d: error: wait failed. (%d)\n",
+#else
 		if (waitid(P_ALL, 0, &info, WEXITED)) {
 			printf("%s:%d: error: waitid failed. (%d)\n",
+#endif
 			       __FILE__, __LINE__, errno);
 			mark_failed(test, ZUC_CHECK_ERROR);
 		} else {
+#if defined(__FreeBSD__)
+			if (WIFEXITED(status)) {
+				int exit_code = WEXITSTATUS(status);
+				switch(exit_code) {
+				case EXIT_SUCCESS:
+					break;
+				case ZUC_EXIT_SKIP:
+					if (!test_has_skip(g_ctx.curr_test) &&
+					    !test_has_failure(g_ctx.curr_test))
+						ZUC_SKIP("Child exited SKIP");
+					break;
+				default:
+					/* unexpected failure */
+					if (!test_has_failure(g_ctx.curr_test))
+						ZUC_ASSERT_EQ(0, exit_code);
+				}
+			} else if (WIFSIGNALED(status)) {
+				printf("%s:%d: error: signaled: %d\n",
+				       __FILE__, __LINE__, WTERMSIG(status));
+				mark_failed(test, ZUC_CHECK_ERROR);
+				break;
+			}
+#else
 			switch (info.si_code) {
 			case CLD_EXITED: {
 				int exit_code = info.si_status;
@@ -1111,6 +1147,7 @@ spawn_test(struct zuc_test *test, void *
 				mark_failed(test, ZUC_CHECK_ERROR);
 				break;
 			}
+#endif
 		}
 	}
 	}
