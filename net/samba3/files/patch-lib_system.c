--- lib/system.c.orig	Fri Feb 25 18:59:32 2005
+++ lib/system.c	Fri Mar  4 02:04:45 2005
@@ -1373,10 +1373,17 @@
 {
 #if defined(HAVE_GETXATTR)
 	return getxattr(path, name, value, size);
+#elif defined(HAVE_EXTATTR_GET_FILE)
+	char *s;
+	int attrnamespace = (strncmp(name, "system", 6) == 0) ? 
+		EXTATTR_NAMESPACE_SYSTEM : EXTATTR_NAMESPACE_USER;
+	const char *attrname = ((s=strchr_m(name, '.')) == NULL) ? name : s + 1;
+
+	return extattr_get_file(path, attrnamespace, attrname, value, size);
 #elif defined(HAVE_ATTR_GET)
 	int retval, flags = 0;
 	int valuelength = (int)size;
-	char *attrname = strchr(name,'.') +1;
+	char *attrname = strchr(name,'.') + 1;
 	
 	if (strncmp(name, "system", 6) == 0) flags |= ATTR_ROOT;
 
@@ -1393,10 +1400,17 @@
 {
 #if defined(HAVE_LGETXATTR)
 	return lgetxattr(path, name, value, size);
+#elif defined(HAVE_EXTATTR_GET_LINK)
+	char *s;
+	int attrnamespace = (strncmp(name, "system", 6) == 0) ? 
+		EXTATTR_NAMESPACE_SYSTEM : EXTATTR_NAMESPACE_USER;
+	const char *attrname = ((s=strchr_m(name, '.')) == NULL) ? name : s + 1;
+
+	return extattr_get_link(path, attrnamespace, attrname, value, size);
 #elif defined(HAVE_ATTR_GET)
 	int retval, flags = ATTR_DONTFOLLOW;
 	int valuelength = (int)size;
-	char *attrname = strchr(name,'.') +1;
+	char *attrname = strchr(name,'.') + 1;
 	
 	if (strncmp(name, "system", 6) == 0) flags |= ATTR_ROOT;
 
@@ -1413,10 +1427,17 @@
 {
 #if defined(HAVE_FGETXATTR)
 	return fgetxattr(filedes, name, value, size);
+#elif defined(HAVE_EXTATTR_GET_FD)
+	char *s;
+	int attrnamespace = (strncmp(name, "system", 6) == 0) ? 
+		EXTATTR_NAMESPACE_SYSTEM : EXTATTR_NAMESPACE_USER;
+	const char *attrname = ((s=strchr_m(name, '.')) == NULL) ? name : s + 1;
+
+	return extattr_get_fd(filedes, attrnamespace, attrname, value, size);
 #elif defined(HAVE_ATTR_GETF)
 	int retval, flags = 0;
 	int valuelength = (int)size;
-	char *attrname = strchr(name,'.') +1;
+	char *attrname = strchr(name,'.') + 1;
 	
 	if (strncmp(name, "system", 6) == 0) flags |= ATTR_ROOT;
 
@@ -1429,6 +1450,99 @@
 #endif
 }
 
+#if defined(HAVE_EXTATTR_LIST_FILE)
+
+#define EXTATTR_PREFIX(s)	(s), (sizeof((s))-1)
+
+static struct {
+        int space;
+	const char *name;
+	size_t len;
+} 
+extattr[] = {
+	{ EXTATTR_NAMESPACE_SYSTEM, EXTATTR_PREFIX("system.") },
+        { EXTATTR_NAMESPACE_USER, EXTATTR_PREFIX("user.") },
+};
+
+typedef union {
+	const char *path;
+	int filedes;
+} extattr_arg;
+
+static ssize_t bsd_attr_list (int type, extattr_arg arg, char *list, size_t size)
+{
+	ssize_t list_size, total_size = 0;
+	int i, t, len;
+	char *buf;
+	/* Iterate through extattr(2) namespaces */
+	for(t = 0; t < (sizeof(extattr)/sizeof(extattr[0])); t++) {
+		switch(type) {
+#if defined(HAVE_EXTATTR_LIST_FILE)
+			case 0:
+				list_size = extattr_list_file(arg.path, extattr[t].space, list, size);
+				break;
+#endif
+#if defined(HAVE_EXTATTR_LIST_LINK)
+			case 1:
+				list_size = extattr_list_link(arg.path, extattr[t].space, list, size);
+				break;
+#endif
+#if defined(HAVE_EXTATTR_LIST_FD)
+			case 2:
+				list_size = extattr_list_fd(arg.filedes, extattr[t].space, list, size);
+				break;
+#endif
+			default:
+				errno = ENOSYS;
+				return -1;
+		}
+		/* Some error happend. Errno should be set by the previous call */
+		if(list_size < 0)
+			return -1;
+		/* No attributes */
+		if(list_size == 0)
+			continue;
+		/* XXX: Call with an empty buffer may be used to calculate
+		   necessary buffer size. Unfortunately, we can't say, how
+		   many attributes were returned, so here is the potential
+		   problem with the emulation.
+		*/
+		if(list == NULL) {
+			/* Take the worse case of one char attribute names - 
+			   two bytes per name plus one more for sanity.
+			*/
+			total_size += list_size + (list_size/2 + 1)*extattr[t].len;
+			continue;
+		}
+		/* Count necessary offset to fit namespace prefixes */
+		len = 0;
+		for(i = 0; i < list_size; i += list[i] + 1)
+			len += extattr[t].len;
+
+		total_size += list_size + len;
+		/* Buffer is too small to fit the results */
+		if(total_size > size) {
+			errno = ERANGE;
+			return -1;
+		}
+		/* Shift the results back, so we can prepend prefixes */
+		buf = memmove(list + len, list, list_size);
+
+		for(i = 0; i < list_size; i += len + 1) {
+			len = buf[i];
+			strncpy(list, extattr[t].name, extattr[t].len + 1);
+			list += extattr[t].len;
+			strncpy(list, buf + i + 1, len);
+			list[len] = '\0';
+			list += len + 1;
+		}
+		size -= total_size;
+	}
+	return total_size;
+}
+
+#endif
+
 #if defined(HAVE_ATTR_LIST) && defined(HAVE_SYS_ATTRIBUTES_H)
 static char attr_buffer[ATTR_MAX_VALUELEN];
 
@@ -1501,6 +1615,10 @@
 {
 #if defined(HAVE_LISTXATTR)
 	return listxattr(path, list, size);
+#elif defined(HAVE_EXTATTR_LIST_FILE)
+	extattr_arg arg;
+	arg.path = path;
+	return bsd_attr_list(0, arg, list, size);
 #elif defined(HAVE_ATTR_LIST) && defined(HAVE_SYS_ATTRIBUTES_H)
 	return irix_attr_list(path, 0, list, size, 0);
 #else
@@ -1513,6 +1631,10 @@
 {
 #if defined(HAVE_LLISTXATTR)
 	return llistxattr(path, list, size);
+#elif defined(HAVE_EXTATTR_LIST_LINK)
+	extattr_arg arg;
+	arg.path = path;
+	return bsd_attr_list(1, arg, list, size);
 #elif defined(HAVE_ATTR_LIST) && defined(HAVE_SYS_ATTRIBUTES_H)
 	return irix_attr_list(path, 0, list, size, ATTR_DONTFOLLOW);
 #else
@@ -1525,6 +1647,10 @@
 {
 #if defined(HAVE_FLISTXATTR)
 	return flistxattr(filedes, list, size);
+#elif defined(HAVE_EXTATTR_LIST_FD)
+	extattr_arg arg;
+	arg.filedes = filedes;
+	return bsd_attr_list(2, arg, list, size);
 #elif defined(HAVE_ATTR_LISTF)
 	return irix_attr_list(NULL, filedes, list, size, 0);
 #else
@@ -1537,9 +1663,16 @@
 {
 #if defined(HAVE_REMOVEXATTR)
 	return removexattr(path, name);
+#elif defined(HAVE_EXTATTR_DELETE_FILE)
+	char *s;
+	int attrnamespace = (strncmp(name, "system", 6) == 0) ? 
+		EXTATTR_NAMESPACE_SYSTEM : EXTATTR_NAMESPACE_USER;
+	const char *attrname = ((s=strchr_m(name, '.')) == NULL) ? name : s + 1;
+
+	return extattr_delete_file(path, attrnamespace, attrname);
 #elif defined(HAVE_ATTR_REMOVE)
 	int flags = 0;
-	char *attrname = strchr(name,'.') +1;
+	char *attrname = strchr(name,'.') + 1;
 	
 	if (strncmp(name, "system", 6) == 0) flags |= ATTR_ROOT;
 
@@ -1554,9 +1687,16 @@
 {
 #if defined(HAVE_LREMOVEXATTR)
 	return lremovexattr(path, name);
+#elif defined(HAVE_EXTATTR_DELETE_LINK)
+	char *s;
+	int attrnamespace = (strncmp(name, "system", 6) == 0) ? 
+		EXTATTR_NAMESPACE_SYSTEM : EXTATTR_NAMESPACE_USER;
+	const char *attrname = ((s=strchr_m(name, '.')) == NULL) ? name : s + 1;
+
+	return extattr_delete_link(path, attrnamespace, attrname);
 #elif defined(HAVE_ATTR_REMOVE)
 	int flags = ATTR_DONTFOLLOW;
-	char *attrname = strchr(name,'.') +1;
+	char *attrname = strchr(name,'.') + 1;
 	
 	if (strncmp(name, "system", 6) == 0) flags |= ATTR_ROOT;
 
@@ -1571,9 +1711,16 @@
 {
 #if defined(HAVE_FREMOVEXATTR)
 	return fremovexattr(filedes, name);
+#elif defined(HAVE_EXTATTR_DELETE_FD)
+	char *s;
+	int attrnamespace = (strncmp(name, "system", 6) == 0) ? 
+		EXTATTR_NAMESPACE_SYSTEM : EXTATTR_NAMESPACE_USER;
+	const char *attrname = ((s=strchr_m(name, '.')) == NULL) ? name : s + 1;
+
+	return extattr_delete_fd(filedes, attrnamespace, attrname);
 #elif defined(HAVE_ATTR_REMOVEF)
 	int flags = 0;
-	char *attrname = strchr(name,'.') +1;
+	char *attrname = strchr(name,'.') + 1;
 	
 	if (strncmp(name, "system", 6) == 0) flags |= ATTR_ROOT;
 
@@ -1593,9 +1740,18 @@
 {
 #if defined(HAVE_SETXATTR)
 	return setxattr(path, name, value, size, flags);
+#elif defined(HAVE_EXTATTR_SET_FILE)
+	char *s;
+	int retval = 0;
+	int attrnamespace = (strncmp(name, "system", 6) == 0) ? 
+		EXTATTR_NAMESPACE_SYSTEM : EXTATTR_NAMESPACE_USER;
+	const char *attrname = ((s=strchr_m(name, '.')) == NULL) ? name : s + 1;
+
+	retval = extattr_set_file(path, attrnamespace, attrname, value, size);
+	return (retval < 0) ? -1 : 0;
 #elif defined(HAVE_ATTR_SET)
 	int myflags = 0;
-	char *attrname = strchr(name,'.') +1;
+	char *attrname = strchr(name,'.') + 1;
 	
 	if (strncmp(name, "system", 6) == 0) myflags |= ATTR_ROOT;
 	if (flags & XATTR_CREATE) myflags |= ATTR_CREATE;
@@ -1612,9 +1768,18 @@
 {
 #if defined(HAVE_LSETXATTR)
 	return lsetxattr(path, name, value, size, flags);
+#elif defined(HAVE_EXTATTR_SET_LINK)
+	char *s;
+	int retval = 0;
+	int attrnamespace = (strncmp(name, "system", 6) == 0) ? 
+		EXTATTR_NAMESPACE_SYSTEM : EXTATTR_NAMESPACE_USER;
+	const char *attrname = ((s=strchr_m(name, '.')) == NULL) ? name : s + 1;
+
+	retval = extattr_set_link(path, attrnamespace, attrname, value, size);
+	return (retval < 0) ? -1 : 0;
 #elif defined(HAVE_ATTR_SET)
 	int myflags = ATTR_DONTFOLLOW;
-	char *attrname = strchr(name,'.') +1;
+	char *attrname = strchr(name,'.') + 1;
 	
 	if (strncmp(name, "system", 6) == 0) myflags |= ATTR_ROOT;
 	if (flags & XATTR_CREATE) myflags |= ATTR_CREATE;
@@ -1631,9 +1796,18 @@
 {
 #if defined(HAVE_FSETXATTR)
 	return fsetxattr(filedes, name, value, size, flags);
+#elif defined(HAVE_EXTATTR_SET_FD)
+	char *s;
+	int retval = 0;
+	int attrnamespace = (strncmp(name, "system", 6) == 0) ? 
+		EXTATTR_NAMESPACE_SYSTEM : EXTATTR_NAMESPACE_USER;
+	const char *attrname = ((s=strchr_m(name, '.')) == NULL) ? name : s + 1;
+
+	retval = extattr_set_fd(filedes, attrnamespace, attrname, value, size);
+	return (retval < 0) ? -1 : 0;
 #elif defined(HAVE_ATTR_SETF)
 	int myflags = 0;
-	char *attrname = strchr(name,'.') +1;
+	char *attrname = strchr(name,'.') + 1;
 	
 	if (strncmp(name, "system", 6) == 0) myflags |= ATTR_ROOT;
 	if (flags & XATTR_CREATE) myflags |= ATTR_CREATE;
