--- vlog.c.orig	Wed Oct 15 22:18:26 2003
+++ vlog.c	Wed Oct 15 22:18:46 2003
@@ -23,32 +23,32 @@
 
 void usage()
 {
-  fprintf(stderr, "
-%s v%s (%s)  %s
-Curses based logfile viewer for IP-Filter
-
-Options:
-  -r                (rotated): read also old, rotated log files (logfile.0, ...)
-  -i                show ipmon log lines only (default is to show all log lines)
-  -g regexp         (grep) show only loglines that match 'regexp'
-  -v regexp         (grep -v) show only loglines that do not match 'regexp'
-  -l logfile        name of log file to be read
-  -l{imsxladcq}     predefined logfile names: i = /var/log/ipflog (default),
-                    m = /var/log/messages,    s = /var/log/syslog,
-		    x = /var/log/xferlog,     l = /var/log/maillog,
-		    a = /var/log/authlog,     d = /var/log/daemon,
-		    c = /var/cron/log,        q = /var/log/squid.
-  -<nn>f or -f      follow logfile: a simple `tail -<nn>f' (no curses)
-  -<nn>  or -n <nn> print <nn> loglines on stdout and exit (no curses)
-  -s [[Mmm] dd]     show lines from date Mmm dd hh:mm:ss. If Mmm and dd are
-     [hh[:mm[:ss]]    not given, use current day. (ex: -s Jul 21) (ex: -s 12:30)
-  -e ...            same thing as -s, specify end date (no curses)
-  -o{dtuhfrilan}    choose which optional fields to display (date time usec
-                      host intf rule isba-rule hdrlen, or all/none)
-  -t                (text only) don't print ANSI codes (if no curses mode)
-  -d                disguise IP addresses and hostnames for publishing purpose
-  -w <nn> or -ww    force vlog output line width to nn chars max (if no curses)
-  -h                this help                       (-ww = no width limitation)
+  fprintf(stderr, "\n\
+%s v%s (%s)  %s\n\
+Curses based logfile viewer for IP-Filter\n\
+\n\
+Options:\n\
+  -r                (rotated): read also old, rotated log files (logfile.0, ...)\n\
+  -i                show ipmon log lines only (default is to show all log lines)\n\
+  -g regexp         (grep) show only loglines that match 'regexp'\n\
+  -v regexp         (grep -v) show only loglines that do not match 'regexp'\n\
+  -l logfile        name of log file to be read\n\
+  -l{imsxladcq}     predefined logfile names: i = /var/log/ipflog (default),\n\
+                    m = /var/log/messages,    s = /var/log/syslog,\n\
+		    x = /var/log/xferlog,     l = /var/log/maillog,\n\
+		    a = /var/log/authlog,     d = /var/log/daemon,\n\
+		    c = /var/cron/log,        q = /var/log/squid.\n\
+  -<nn>f or -f      follow logfile: a simple `tail -<nn>f' (no curses)\n\
+  -<nn>  or -n <nn> print <nn> loglines on stdout and exit (no curses)\n\
+  -s [[Mmm] dd]     show lines from date Mmm dd hh:mm:ss. If Mmm and dd are\n\
+     [hh[:mm[:ss]]    not given, use current day. (ex: -s Jul 21) (ex: -s 12:30)\n\
+  -e ...            same thing as -s, specify end date (no curses)\n\
+  -o{dtuhfrilan}    choose which optional fields to display (date time usec\n\
+                      host intf rule isba-rule hdrlen, or all/none)\n\
+  -t                (text only) don't print ANSI codes (if no curses mode)\n\
+  -d                disguise IP addresses and hostnames for publishing purpose\n\
+  -w <nn> or -ww    force vlog output line width to nn chars max (if no curses)\n\
+  -h                this help                       (-ww = no width limitation)\n\
 ", MYNAME, VERSION, DATE, CREDIT);
 
   exit(1);
