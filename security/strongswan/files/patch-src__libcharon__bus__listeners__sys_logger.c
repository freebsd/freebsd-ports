--- srcold/libcharon/bus/listeners/sys_logger.c	2011-03-10 20:50:01.000000000 +0200
+++ src/libcharon/bus/listeners/sys_logger.c	2011-03-10 20:53:59.000000000 +0200
@@ -79,13 +79,15 @@
 		/* do a syslog with every line */
 		while (current)
 		{
+			char tmp[8192];
 			next = strchr(current, '\n');
 			if (next)
 			{
 				*(next++) = '\0';
 			}
-			syslog(this->facility|LOG_INFO, "%.2d[%N]%s %s\n",
+			snprintf(tmp, 8192, "%.2d[%N]%s %s\n",
 				   thread, debug_names, group, namestr, current);
+			syslog(this->facility|LOG_INFO, tmp);
 			current = next;
 		}
 	}
