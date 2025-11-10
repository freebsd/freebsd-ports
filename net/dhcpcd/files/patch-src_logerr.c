--- src/logerr.c.orig	2025-06-01 18:40:28 UTC
+++ src/logerr.c
@@ -26,7 +26,9 @@
  * SUCH DAMAGE.
  */
 
+#include <sys/socket.h>
 #include <sys/time.h>
+
 #include <errno.h>
 #include <stdbool.h>
 #include <stdarg.h>
@@ -215,18 +217,25 @@ vlogmessage(int pri, const char *fmt, va_list args)
 	int len = 0;
 
 	if (ctx->log_fd != -1) {
+		pid_t pid = getpid();
 		char buf[LOGERR_SYSLOGBUF];
-		pid_t pid;
+		struct iovec iov[] = {
+			{ .iov_base = &pri, .iov_len = sizeof(pri) },
+			{ .iov_base = &pid, .iov_len = sizeof(pid) },
+			{ .iov_base = buf },
+		};
 
-		memcpy(buf, &pri, sizeof(pri));
-		pid = getpid();
-		memcpy(buf + sizeof(pri), &pid, sizeof(pid));
-		len = vsnprintf(buf + sizeof(pri) + sizeof(pid),
-		    sizeof(buf) - sizeof(pri) - sizeof(pid),
-		    fmt, args);
-		if (len != -1)
-			len = (int)write(ctx->log_fd, buf,
-			    ((size_t)++len) + sizeof(pri) + sizeof(pid));
+		len = vsnprintf(buf, sizeof(buf), fmt, args);
+		if (len != -1) {
+			if ((size_t)len >= sizeof(buf))
+				len = (int)sizeof(buf) - 1;
+			iov[2].iov_len = (size_t)(len + 1);
+			struct msghdr msg = {
+				.msg_iov = iov,
+				.msg_iovlen = sizeof(iov) / sizeof(iov[0]),
+			};
+			len = (int)sendmsg(ctx->log_fd, &msg, MSG_EOR);
+		}
 		return len;
 	}
 
@@ -390,24 +399,33 @@ logreadfd(int fd)
 logreadfd(int fd)
 {
 	struct logctx *ctx = &_logctx;
-	char buf[LOGERR_SYSLOGBUF];
 	int len, pri;
+	pid_t pid;
+	char buf[LOGERR_SYSLOGBUF] = { '\0' };
+	struct iovec iov[] = {
+		{ .iov_base = &pri, .iov_len = sizeof(pri) },
+		{ .iov_base = &pid, .iov_len = sizeof(pid) },
+		{ .iov_base = buf,  .iov_len = sizeof(buf) },
+	};
+	struct msghdr msg = {
+		.msg_iov = iov,
+		.msg_iovlen = sizeof(iov) / sizeof(iov[0])
+	};
 
-	len = (int)read(fd, buf, sizeof(buf));
-	if (len == -1)
+	len = (int)recvmsg(fd, &msg, MSG_WAITALL);
+	if (len == -1 || len == 0)
 		return -1;
-
-	/* Ensure we have pri, pid and a terminator */
-	if (len < (int)(sizeof(pri) + sizeof(pid_t) + 1) ||
-	    buf[len - 1] != '\0')
-	{
-		errno = EINVAL;
+	/* Ensure we received the minimum and at least one character to log */
+	if ((size_t)len < sizeof(pri) + sizeof(pid) + 1 ||
+	    msg.msg_flags & MSG_TRUNC) {
+		errno = EMSGSIZE;
 		return -1;
 	}
+	/* Ensure what we receive is NUL terminated */
+	buf[(size_t)len - (sizeof(pri) + sizeof(pid)) - 1] = '\0';
 
-	memcpy(&pri, buf, sizeof(pri));
-	memcpy(&ctx->log_pid, buf + sizeof(pri), sizeof(ctx->log_pid));
-	logmessage(pri, "%s", buf + sizeof(pri) + sizeof(ctx->log_pid));
+	ctx->log_pid = pid;
+	logmessage(pri, "%s", buf);
 	ctx->log_pid = 0;
 	return len;
 }
