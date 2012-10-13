Index: bgpd/log.h
===================================================================
RCS file: /home/cvs/private/hrs/openbgpd/bgpd/log.h,v
retrieving revision 1.1.1.2
retrieving revision 1.1.1.3
diff -u -p -r1.1.1.2 -r1.1.1.3
--- bgpd/log.h	9 Jul 2009 16:49:54 -0000	1.1.1.2
+++ bgpd/log.h	13 Oct 2012 18:22:43 -0000	1.1.1.3
@@ -1,4 +1,4 @@
-/*	$OpenBSD: log.h,v 1.11 2008/09/11 14:49:58 henning Exp $ */
+/*	$OpenBSD: log.h,v 1.13 2012/06/10 11:16:08 claudio Exp $ */
 
 /*
  * Copyright (c) 2003, 2004 Henning Brauer <henning@openbsd.org>
@@ -71,6 +71,13 @@ static const char * const suberr_open_na
 	"unsupported capability"
 };
 
+static const char * const suberr_fsm_names[] = {
+	"unspecified error",
+	"received unexpected message in OpenSent",
+	"received unexpected message in OpenConfirm",
+	"received unexpected message in Established"
+};
+
 static const char * const suberr_update_names[] = {
 	"none",
 	"attribute list error",
@@ -109,7 +116,9 @@ static const char * const ctl_res_strerr
 	"no such neighbor",
 	"permission denied",
 	"neighbor does not have this capability",
-	"config file has errors, reload failed"
+	"config file has errors, reload failed",
+	"previous reload still running",
+	"out of memory"
 };
 
 static const char * const timernames[] = {
