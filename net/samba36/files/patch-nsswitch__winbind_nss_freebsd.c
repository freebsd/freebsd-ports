--- ./nsswitch/winbind_nss_freebsd.c.orig	2012-10-02 08:24:41.000000000 +0000
+++ ./nsswitch/winbind_nss_freebsd.c	2013-03-13 09:40:37.285778609 +0000
@@ -5,6 +5,7 @@
    routines against Samba winbind/Windows NT Domain
 
    Copyright (C) Aaron Collins 2003
+   Copyright (C) Timur I. Bakeyev 2013
 
    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
@@ -53,6 +54,9 @@
 NSS_METHOD_PROTOTYPE(__nss_compat_getpwent_r);
 NSS_METHOD_PROTOTYPE(__nss_compat_setpwent);
 NSS_METHOD_PROTOTYPE(__nss_compat_endpwent);
+NSS_METHOD_PROTOTYPE(__nss_compat_endpwent);
+
+NSS_METHOD_PROTOTYPE(__freebsd_getgroupmembership);
 
 static ns_mtab methods[] = {
 { NSDB_GROUP, "getgrnam_r", __nss_compat_getgrnam_r, _nss_winbind_getgrnam_r },
@@ -60,6 +64,7 @@
 { NSDB_GROUP, "getgrent_r", __nss_compat_getgrent_r, _nss_winbind_getgrent_r },
 { NSDB_GROUP, "setgrent",   __nss_compat_setgrent,   _nss_winbind_setgrent },
 { NSDB_GROUP, "endgrent",   __nss_compat_endgrent,   _nss_winbind_endgrent },
+{ NSDB_GROUP, "getgroupmembership", __freebsd_getgroupmembership, NULL },
 
 { NSDB_PASSWD, "getpwnam_r", __nss_compat_getpwnam_r, _nss_winbind_getpwnam_r },
 { NSDB_PASSWD, "getpwuid_r", __nss_compat_getpwuid_r, _nss_winbind_getpwuid_r },
@@ -69,6 +74,71 @@
 
 };
 
+/* Taken from libc */
+static int
+gr_addgid(gid_t gid, gid_t *groups, int maxgrp, int *grpcnt)
+{
+	int	ret, dupc;
+
+	/* skip duplicates */
+	for (dupc = 0; dupc < MIN(maxgrp, *grpcnt); dupc++) {
+		if (groups[dupc] == gid)
+			return 1;
+	}
+
+	ret = 1;
+	if (*grpcnt < maxgrp)			/* add this gid */
+		groups[*grpcnt] = gid;
+	else
+		ret = 0;
+
+	(*grpcnt)++;
+
+	return ret;
+}
+
+/*
+    rv = _nsdispatch(NULL, dtab, NSDB_GROUP, "getgroupmembership",
+	            defaultsrc, uname, agroup, groups, maxgrp, grpcnt);
+*/
+
+int
+__freebsd_getgroupmembership(void *retval, void *mdata, va_list ap)
+{
+	const char 	*uname  = va_arg(ap, const char *);
+	gid_t		 group  = va_arg(ap, gid_t);
+	gid_t		*groups = va_arg(ap, gid_t *);
+	int		 maxgrp = va_arg(ap, int);
+	int		*groupc = va_arg(ap, int *);
+
+	NSS_STATUS ret;
+	long int lcount, lsize;
+	int i, errnop;
+	gid_t *tmpgroups;
+
+	/* Can be realloc() inside _nss_winbind_initgroups_dyn() */
+	if ((tmpgroups=calloc(maxgrp, sizeof(gid_t))) == NULL) {
+		errno = ENOMEM;
+		return NS_TRYAGAIN;
+	}
+
+	lcount = 0;
+	lsize = maxgrp;
+	/* insert primary membership(possibly already there) */
+	gr_addgid(group, groups, maxgrp, groupc);
+	/* Don't limit number of groups, we want to know total size */
+	ret = _nss_winbind_initgroups_dyn(uname, group, &lcount, &lsize,
+		&tmpgroups, 0, &errnop);
+	if (ret == NSS_STATUS_SUCCESS) {
+		/* lcount potentially can be bigger than maxgrp, so would groupc */
+		for (i = 0; i < lcount; i++)
+			 gr_addgid(tmpgroups[i], groups, maxgrp, groupc);
+	}
+	free(tmpgroups);
+	/* Let following nsswitch backend(s) add more groups(?) */
+	return NSS_STATUS_NOTFOUND;
+}
+
 ns_mtab *
 nss_module_register(const char *source, unsigned int *mtabsize,
     nss_module_unregister_fn *unreg)
