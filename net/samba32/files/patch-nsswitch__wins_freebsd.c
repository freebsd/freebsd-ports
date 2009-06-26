--- ./nsswitch/wins_freebsd.c.orig	2009-06-25 20:49:35.000000000 +0000
+++ ./nsswitch/wins_freebsd.c	2009-06-25 20:49:35.000000000 +0000
@@ -0,0 +1,112 @@
+/* 
+   Unix SMB/CIFS implementation.
+
+   Copyright (C) Timur I. Bakeyev 2007
+   
+   This library is free software; you can redistribute it and/or
+   modify it under the terms of the GNU Library General Public
+   License as published by the Free Software Foundation; either
+   version 2 of the License, or (at your option) any later version.
+   
+   This library is distributed in the hope that it will be useful,
+   but WITHOUT ANY WARRANTY; without even the implied warranty of
+   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
+   Library General Public License for more details.
+   
+   You should have received a copy of the GNU Library General Public
+   License along with this library; if not, write to the
+   Free Software Foundation, Inc., 59 Temple Place - Suite 330,
+   Boston, MA  02111-1307, USA.   
+*/
+
+#include "winbind_client.h"
+
+NSS_STATUS _nss_wins_gethostbyname_r(const char *hostname, struct hostent *he,
+			  char *buffer, size_t buflen, int *h_errnop);
+NSS_STATUS _nss_wins_gethostbyname2_r(const char *name, int af, struct hostent *he,
+			   char *buffer, size_t buflen, int *h_errnop);
+
+NSS_METHOD_PROTOTYPE(__nss_wins_freebsd_gethostbyname_r);
+NSS_METHOD_PROTOTYPE(__nss_wins_freebsd_gethostbyname2_r);
+
+static ns_mtab methods[] =
+{
+/*
+	{ NSDB_HOSTS, "getaddrinfo",	  NULL, NULL },
+	{ NSDB_HOSTS, "ghbyname",	  NULL, NULL },
+	{ NSDB_HOSTS, "ghbyaddr",	  NULL, NULL },
+*/
+	{ NSDB_HOSTS, "gethostbyaddr_r",  __nss_wins_freebsd_gethostbyname_r,  _nss_wins_gethostbyname_r },
+	{ NSDB_HOSTS, "gethostbyname2_r", __nss_wins_freebsd_gethostbyname2_r, _nss_wins_gethostbyname2_r },
+/*
+	{ NSDB_HOSTS, "getnetbyname_r",	  NULL, NULL },
+	{ NSDB_HOSTS, "getnetbyaddr_r",	  NULL, NULL },
+	{ NSDB_HOSTS, "gethostbyname",	  NULL, NULL },
+	{ NSDB_HOSTS, "gethostbyaddr",	  NULL, NULL },
+	{ NSDB_HOSTS, "getnetbyname",	  NULL, NULL },
+	{ NSDB_HOSTS, "getnetbyaddr",	  NULL, NULL }
+*/
+};
+
+int
+__nss_wins_freebsd_gethostbyname_r(void *retval, void *mdata, va_list ap)
+{
+	int (*fn)(const char *, struct hostent *, char *, size_t, int *);
+	const char	*hostname;
+	struct hostent	*he;
+	char		*buffer;
+	size_t		buflen;
+	int		*h_errnop;
+	enum nss_status	 status;
+	
+	fn = mdata;
+	hostname = va_arg(ap, const char *);
+	he = va_arg(ap, struct hostent *);
+	buffer = va_arg(ap, char *);
+	buflen = va_arg(ap, size_t);
+	h_errnop = va_arg(ap, int *);
+
+	status = fn(hostname, he, buffer, buflen, h_errnop);
+	status = __nss_compat_result(status, *h_errnop);
+	if (status == NS_SUCCESS)
+		*(struct hostent **)retval = he;
+	
+	return (status);
+}
+
+int
+__nss_wins_freebsd_gethostbyname2_r(void *retval, void *mdata, va_list ap)
+{
+	int (*fn)(const char *, int, struct hostent *, char *, size_t, int *);
+	const char	*hostname;
+	int		af;
+	struct hostent	*he;
+	char		*buffer;
+	size_t		buflen;
+	int		*h_errnop;
+	enum nss_status	 status;
+	
+	fn = mdata;
+	hostname = va_arg(ap, const char *);
+	af = va_arg(ap, int);
+	he = va_arg(ap, struct hostent *);
+	buffer = va_arg(ap, char *);
+	buflen = va_arg(ap, size_t);
+	h_errnop = va_arg(ap, int *);
+
+	status = fn(hostname, af, he, buffer, buflen, h_errnop);
+	status = __nss_compat_result(status, *h_errnop);
+	if (status == NS_SUCCESS)
+		*(struct hostent **)retval = he;
+	
+	return (status);
+}
+
+ns_mtab *
+nss_module_register(const char *source __unused, unsigned int *mtabsize,
+    nss_module_unregister_fn *unreg)
+{
+	*mtabsize = sizeof(methods) / sizeof(methods[0]);
+	*unreg = NULL;
+	return (methods);
+}
