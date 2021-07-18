--- io.c.orig
+++ io.c
@@ -787,18 +787,19 @@
 			if (msgs2stderr == 1 && DEBUG_GTE(IO, 2))
 				rprintf(FINFO, "[%s] recv=%ld\n", who_am_i(), (long)n);
 
-			if (io_timeout || stop_at_utime) {
+			if (io_timeout) {
 				last_io_in = time(NULL);
-				if (stop_at_utime && last_io_in >= stop_at_utime) {
-					rprintf(FERROR, "stopping at requested limit\n");
-					exit_cleanup(RERR_TIMEOUT);
-				}
 				if (io_timeout && flags & PIO_NEED_INPUT)
 					maybe_send_keepalive(last_io_in, 0);
 			}
 			stats.total_read += n;
 
 			iobuf.in.len += n;
+		}
+
+		if (stop_at_utime && time(NULL) >= stop_at_utime) {
+			rprintf(FERROR, "stopping at requested limit\n");
+			exit_cleanup(RERR_TIMEOUT);
 		}
 
 		if (out && FD_ISSET(iobuf.out_fd, &w_fds)) {
