--- rdiff_backup/robust.py.orig	Tue Dec 14 17:02:48 2004
+++ rdiff_backup/robust.py	Tue Dec 14 17:03:43 2004
@@ -53,7 +53,7 @@
 		 errno.errorcode[exc[0]] in ('EPERM', 'ENOENT', 'EACCES', 'EBUSY',
 									 'EEXIST', 'ENOTDIR', 'ENAMETOOLONG',
 									 'EINTR', 'ENOTEMPTY', 'EIO', 'ETXTBSY',
-									 'ESRCH', 'EINVAL', 'EDEADLOCK'))):
+									 'ESRCH', 'EINVAL', 'EDEADLOCK', 'EDEADLK'))):
 		return 1
 	return 0
 
