--- userspace.py.orig	2010-12-23 09:35:39.917675583 +0100
+++ userspace.py	2010-12-23 09:52:20.873003971 +0100
@@ -30,7 +30,6 @@
 import pwd
 import grp
 import errno
-import solaris.misc
 import zfs.util
 import zfs.ioctl
 import zfs.dataset
@@ -68,9 +67,9 @@
 		idstr = "%u" % rid
 
 	(typename, mapfunc) = {
-	    (1, 1): ("SMB Group",   lambda id: solaris.misc.sid_to_name(id, 0)),
+	    (1, 1): ("SMB Group",   id),
 	    (1, 0): ("POSIX Group", lambda id: grp.getgrgid(int(id)).gr_name),
-	    (0, 1): ("SMB User",    lambda id: solaris.misc.sid_to_name(id, 1)),
+	    (0, 1): ("SMB User",    id),
 	    (0, 0): ("POSIX User",  lambda id: pwd.getpwuid(int(id)).pw_name)
 	}[isgroup, bool(domain)]
 
@@ -107,13 +106,13 @@
 	(domain, rid, value) = elem
 	(field, isgroup) = props[prop]
 
-	if options.translate and domain:
-		try:
-			rid = solaris.misc.sid_to_id("%s-%u" % (domain, rid),
-			    not isgroup)
-			domain = None
-		except KeyError:
-			pass;
+#	if options.translate and domain:
+#		try:
+#			rid = solaris.misc.sid_to_id("%s-%u" % (domain, rid),
+#			    not isgroup)
+#			domain = None
+#		except KeyError:
+#			pass;
 	key = (isgroup, domain, rid)
 		
 	try:
