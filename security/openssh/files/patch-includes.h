--- includes.h.orig	Sat Jan 26 17:44:22 2002
+++ includes.h	Fri Jun 28 06:23:07 2002
@@ -24,12 +24,12 @@
 #include <sys/select.h>
 #include <sys/param.h>
 #include <sys/ioctl.h>
-#include <sys/endian.h>
 #include <sys/stat.h>
 #include <sys/wait.h>
 #include <sys/time.h>
 #include <sys/un.h>
 #include <sys/resource.h>
+#include <machine/endian.h>
 
 #include <netinet/in.h>
 #include <netinet/in_systm.h>
@@ -38,7 +38,6 @@
 #include <arpa/inet.h>
 #include <netdb.h>
 
-#include <netgroup.h>
 #include <stdio.h>
 #include <ctype.h>
 #include <errno.h>
@@ -61,6 +60,69 @@
  * Define this to use pipes instead of socketpairs for communicating with the
  * client program.  Socketpairs do not seem to work on all systems.
  */
-#define USE_PIPES 1
+#undef USE_PIPES
+
+#if defined(__FreeBSD__) && __FreeBSD__ <= 3
+/*
+ * Data types.
+ */
+typedef u_char          sa_family_t;
+typedef int             socklen_t;
+
+/*
+ * bsd-api-new-02a: protocol-independent placeholder for socket addresses
+ */
+#define	_SS_MAXSIZE	128
+#define	_SS_ALIGNSIZE	(sizeof(int64_t))
+#define	_SS_PAD1SIZE	(_SS_ALIGNSIZE - sizeof(u_char) * 2)
+#define	_SS_PAD2SIZE	(_SS_MAXSIZE - sizeof(u_char) * 2 - \
+				_SS_PAD1SIZE - _SS_ALIGNSIZE)
+
+struct sockaddr_storage {
+	u_char		ss_len;		/* address length */
+	sa_family_t	ss_family;	/* address family */
+	char		__ss_pad1[_SS_PAD1SIZE];
+	int64_t		__ss_align;	/* force desired structure storage alignment */
+	char		__ss_pad2[_SS_PAD2SIZE];
+};
+
+/* defines for comatibility with older FreeBSD releases */
+#ifndef	SHUT_RD
+#define	SHUT_RD		0
+#endif
+#ifndef	SHUT_WR
+#define	SHUT_WR		1
+#endif
+#ifndef	SHUT_RDWR
+#define	SHUT_RDWR	2
+#endif
+
+#ifndef INET_ADDRSTRLEN
+#define	INET_ADDRSTRLEN	46
+#endif
+
+#ifndef OSSH_ALIGNBYTES
+#define OSSH_ALIGNBYTES (sizeof(int) - 1)
+#endif
+
+#ifndef __CMSG_ALIGN
+#define __CMSG_ALIGN(p) (((u_int)(p) + OSSH_ALIGNBYTES) &~ OSSH_ALIGNBYTES)
+#endif
+
+/* Length of the contents of a control message of length len */
+#ifndef CMSG_LEN
+#define CMSG_LEN(len)   (__CMSG_ALIGN(sizeof(struct cmsghdr)) + (len))
+#endif
+
+/* Length of the space taken up by a padded control message of length len */
+#ifndef CMSG_SPACE
+#define CMSG_SPACE(len) (__CMSG_ALIGN(sizeof(struct cmsghdr)) + __CMSG_ALIGN(len))
+#endif
+
+#ifndef __func__
+#define	__func__	__FUNCTION__
+#endif
+
+#endif
 
 #endif				/* INCLUDES_H */
