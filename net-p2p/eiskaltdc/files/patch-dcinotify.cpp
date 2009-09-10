--- eiskaltdc/dcinotify.cpp.orig	2009-09-01 09:45:17.000000000 +0700
+++ eiskaltdc/dcinotify.cpp	2009-09-01 09:46:21.000000000 +0700
@@ -2,7 +2,201 @@
 
 #include "dcinotify.h"
 
-#include <sys/inotify.h>
+/* inotify_local.h injected directly into dcinotify.cpp
+
+/*
+ * inotify_local.h - wrapping of libc features and kernel defines
+ *
+ * Copyright (C) 2005-2006 Kay Sievers <kay.sievers at vrfy.org>
+ *
+ *	This program is free software; you can redistribute it and/or modify it
+ *	under the terms of the GNU General Public License as published by the
+ *	Free Software Foundation version 2 of the License.
+ * 
+ *	This program is distributed in the hope that it will be useful, but
+ *	WITHOUT ANY WARRANTY; without even the implied warranty of
+ *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
+ *	General Public License for more details.
+ * 
+ *	You should have received a copy of the GNU General Public License along
+ *	with this program; if not, write to the Free Software Foundation, Inc.,
+ *	675 Mass Ave, Cambridge, MA 02139, USA.
+ *
+ */
+
+#ifndef _INOTIFY_LOCAL_H_
+#define _INOTIFY_LOCAL_H_
+
+#include <string.h>
+#include <unistd.h>
+#include <stdint.h>
+
+/* needed until Inotify! syscalls reach glibc */
+#include <sys/syscall.h>
+#ifndef __NR_inotify_init
+#if defined(__i386__)
+# define __NR_inotify_init	291
+# define __NR_inotify_add_watch	292
+# define __NR_inotify_rm_watch	293
+#elif defined(__x86_64__)
+# define __NR_inotify_init	253
+# define __NR_inotify_add_watch	254
+# define __NR_inotify_rm_watch	255
+#elif defined(__powerpc__) || defined(__powerpc64__)
+# define __NR_inotify_init	275
+# define __NR_inotify_add_watch	276
+# define __NR_inotify_rm_watch	277
+#elif defined (__ia64__)
+# define __NR_inotify_init	1277
+# define __NR_inotify_add_watch	1278
+# define __NR_inotify_rm_watch	1279
+#elif defined (__s390__)
+# define __NR_inotify_init	284
+# define __NR_inotify_add_watch	285
+# define __NR_inotify_rm_watch	286
+#elif defined (__mc68000__)
+# define __NR_inotify_init	284
+# define __NR_inotify_add_watch	285
+# define __NR_inotify_rm_watch	286
+#elif defined (__alpha__)
+# define __NR_inotify_init	444
+# define __NR_inotify_add_watch	445
+# define __NR_inotify_rm_watch	446
+#elif defined (__sparc__) || defined (__sparc64__)
+# define __NR_inotify_init	151
+# define __NR_inotify_add_watch	152
+# define __NR_inotify_rm_watch	156
+#elif defined (__arm__)
+# define __NR_inotify_init	__NR_SYSCALL_BASE+316
+# define __NR_inotify_add_watch	__NR_SYSCALL_BASE+317
+# define __NR_inotify_rm_watch	__NR_SYSCALL_BASE+318
+#elif defined (__sh__)
+# define __NR_inotify_init	290
+# define __NR_inotify_add_watch	291
+# define __NR_inotify_rm_watch	292
+#elif defined (__m32r__)
+# define __NR_inotify_init      290
+# define __NR_inotify_add_watch 291
+# define __NR_inotify_rm_watch  292
+#elif defined (__hppa__)
+# define __NR_inotify_init      269
+# define __NR_inotify_add_watch 270
+# define __NR_inotify_rm_watch  271
+#elif defined (__mips__)
+# include <sgidefs.h>
+# if _MIPS_SIM == _MIPS_SIM_ABI32
+#  define __NR_Linux             4000
+#  define __NR_inotify_init      (__NR_Linux + 284)
+#  define __NR_inotify_add_watch (__NR_Linux + 285)
+#  define __NR_inotify_rm_watch  (__NR_Linux + 286)
+# elif _MIPS_SIM == _MIPS_SIM_ABI64
+#  define __NR_Linux             5000
+#  define __NR_inotify_init      (__NR_Linux + 243)
+#  define __NR_inotify_add_watch (__NR_Linux + 244)
+#  define __NR_inotify_rm_watch  (__NR_Linux + 245)
+# elif _MIPS_SIM == _MIPS_SIM_NABI32
+#  define __NR_Linux             6000
+#  define __NR_inotify_init      (__NR_Linux + 247)
+#  define __NR_inotify_add_watch (__NR_Linux + 248)
+#  define __NR_inotify_rm_watch  (__NR_Linux + 249)
+# endif
+#else
+# warning "inotify unsupported on this architecture!"
+#endif
+#endif /* __NR_inotify_init */
+
+/* dummy if we don't have the syscalls defined */
+#ifndef __NR_inotify_init
+static inline int inotify_init(void)
+{
+	return -1;
+}
+
+static inline int inotify_add_watch(int fd, const char *name, uint32_t mask)
+{
+	return -1;
+}
+
+static inline int inotify_rm_watch(int fd, uint32_t wd)
+{
+	return -1;
+}
+#else
+static inline int inotify_init(void)
+{
+	return syscall(__NR_inotify_init);
+}
+
+static inline int inotify_add_watch(int fd, const char *name, uint32_t mask)
+{
+	return syscall(__NR_inotify_add_watch, fd, name, mask);
+}
+
+static inline int inotify_rm_watch(int fd, uint32_t wd)
+{
+	return syscall(__NR_inotify_rm_watch, fd, wd);
+}
+#endif /* __NR_inotify_init */
+
+#ifndef IN_CREATE
+#define IN_CREATE		0x00000100	/* Subfile was created */
+#define IN_MOVED_FROM		0x00000040	/* File was moved from X */
+#define IN_MOVED_TO		0x00000080	/* File was moved to Y */
+#define IN_DELETE		0x00000200	/* Subfile was deleted */
+#define IN_CLOSE_WRITE		0x00000008	/* Writtable file was closed */
+#define IN_MOVE			(IN_MOVED_FROM | IN_MOVED_TO) /* moves */
+#endif /* IN_CREATE */
+
+struct inotify_event {
+	int      wd;
+	uint32_t mask;
+	uint32_t cookie;
+	uint32_t len;
+	char     *name;
+};
+
+/* the following are legal, implemented events that user-space can watch for */
+#define IN_ACCESS		0x00000001	/* File was accessed */
+#define IN_MODIFY		0x00000002	/* File was modified */
+#define IN_ATTRIB		0x00000004	/* Metadata changed */
+#define IN_CLOSE_WRITE		0x00000008	/* Writtable file was closed */
+#define IN_CLOSE_NOWRITE	0x00000010	/* Unwrittable file closed */
+#define IN_OPEN			0x00000020	/* File was opened */
+#define IN_MOVED_FROM		0x00000040	/* File was moved from X */
+#define IN_MOVED_TO		0x00000080	/* File was moved to Y */
+#define IN_CREATE		0x00000100	/* Subfile was created */
+#define IN_DELETE		0x00000200	/* Subfile was deleted */
+#define IN_DELETE_SELF		0x00000400	/* Self was deleted */
+#define IN_MOVE_SELF		0x00000800	/* Self was moved */
+
+/* the following are legal events.  they are sent as needed to any watch */
+#define IN_UNMOUNT		0x00002000	/* Backing fs was unmounted */
+#define IN_Q_OVERFLOW		0x00004000	/* Event queued overflowed */
+#define IN_IGNORED		0x00008000	/* File was ignored */
+
+/* helper events */
+#define IN_CLOSE		(IN_CLOSE_WRITE | IN_CLOSE_NOWRITE) /* close */
+#define IN_MOVE			(IN_MOVED_FROM | IN_MOVED_TO) /* moves */
+
+/* special flags */
+#define IN_ONLYDIR		0x01000000	/* only watch the path if it is a directory */
+#define IN_DONT_FOLLOW		0x02000000	/* don't follow a sym link */
+#define IN_MASK_ADD		0x20000000	/* add to the mask of an already existing watch */
+#define IN_ISDIR		0x40000000	/* event occurred against dir */
+#define IN_ONESHOT		0x80000000	/* only send event once */
+
+/*
+ * All of the events - we build the list by hand so that we can add flags in
+ * the future and not break backward compatibility.  Apps will get only the
+ * events that they originally wanted.  Be sure to add new events here!
+ */
+#define IN_ALL_EVENTS	(IN_ACCESS | IN_MODIFY | IN_ATTRIB | IN_CLOSE_WRITE | \
+			 IN_CLOSE_NOWRITE | IN_OPEN | IN_MOVED_FROM | \
+			 IN_MOVED_TO | IN_DELETE | IN_CREATE | IN_DELETE_SELF | \
+			 IN_MOVE_SELF)
+
+#endif /* _INOTIFY_LOCAL_H_ */
+
 #include <sys/ioctl.h>
 #include <sys/types.h>
 #include <sys/select.h>
