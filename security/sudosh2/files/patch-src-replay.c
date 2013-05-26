--- src/replay.c.orig	2010-07-09 13:37:01.000000000 -0700
+++ src/replay.c	2013-05-26 10:07:55.720227505 -0700
@@ -238,7 +238,7 @@
 	    strncpy(s->randstr, randstr, BUFSIZ - 1);
 	    strftime(s->date, 20, "%m/%d/%Y %H:%M:%S", localtime(&s->e));
 	    snprintf(s->id, BUFSIZ - 1, "%s%c%s%c%ld%c%s", s->from,
-		     config_option.fdl, s->to, config_option.fdl, s->e,
+		     config_option.fdl, s->to, config_option.fdl, (long)s->e,
 		     config_option.fdl, s->randstr);
 
 	    link_session(s);
