--- ./src/cleanup/cleanup_message.c.orig	Tue Nov 27 16:55:39 2001
+++ ./src/cleanup/cleanup_message.c	Tue Nov 27 16:58:43 2001
@@ -269,6 +269,10 @@
 		state->errs |= CLEANUP_STAT_CONT;
 	    } else if (strcasecmp(value, "IGNORE") == 0) {
 		return;
+	    } else if (strcasecmp(value, "WARN") == 0) {
+		msg_info("%s: warning: header %.200s; from=<%s> to=<%s>",
+			state->queue_id, header, state->sender,
+			state->recip ? state->recip : "unknown");
 	    }
 	}
     }
@@ -498,6 +502,10 @@
 		    state->errs |= CLEANUP_STAT_CONT;
 		} else if (strcasecmp(value, "IGNORE") == 0) {
 		    return;
+		} else if (strcasecmp(value, "WARN") == 0) {
+		    msg_info("%s: warning: body %.200s; from=<%s> to=<%s>",
+			state->queue_id, buf, state->sender,
+			state->recip ? state->recip : "unknown");
 		}
 	    }
 	}
