--- src/polkit/polkit-context.c.orig	2008-04-15 20:31:16.000000000 -0400
+++ src/polkit/polkit-context.c	2008-04-18 01:12:13.000000000 -0400
@@ -43,7 +43,13 @@
 #include <port.h>
 #include <sys/stat.h>
 #else
+#ifdef HAVE_INOTIFY
 #include <sys/inotify.h>
+#elif HAVE_KQUEUE
+#include <sys/event.h>
+#include <sys/time.h>
+#include <fcntl.h>
+#endif
 #endif
 #include <syslog.h>
 
@@ -111,11 +117,19 @@ struct _PolKitContext
 
         polkit_bool_t load_descriptions;
 
+#ifdef HAVE_INOTIFY
         int inotify_fd;
         int inotify_fd_watch_id;
         int inotify_config_wd;
         int inotify_policy_wd;
         int inotify_grant_perm_wd;
+#elif HAVE_KQUEUE
+	int kqueue_fd;
+	int kqueue_fd_watch_id;
+	int kqueue_config_fd;
+	int kqueue_policy_fd;
+	int kqueue_grant_perm_fd;
+#endif
 };
 
 /**
@@ -149,6 +163,10 @@ polkit_context_new (void)
 polkit_bool_t
 polkit_context_init (PolKitContext *pk_context, PolKitError **error)
 {
+#ifdef HAVE_KQUEUE
+	struct kevent ev;
+#endif
+
         kit_return_val_if_fail (pk_context != NULL, FALSE);
 
         pk_context->policy_dir = kit_strdup (PACKAGE_DATA_DIR "/PolicyKit/policy");
@@ -209,7 +227,87 @@ polkit_context_init (PolKitContext *pk_c
                         goto error;
                 }
         }
+#elif HAVE_KQUEUE
+	if (pk_context->io_add_watch_func != NULL) {
+		pk_context->kqueue_fd = kqueue ();
+		if (pk_context->kqueue_fd < 0) {
+			polkit_debug ("failed to initialize kqueue: %s", strerror (errno));
+			/* TODO: set error */
+			goto error;
+		}
+
+		/* Watch the /etc/PolicyKit/PolicyKit.conf file */
+		pk_context->kqueue_config_fd = open (PACKAGE_SYSCONF_DIR "/PolicyKit/PolicyKit.conf", O_RDONLY);
+		if (pk_context->kqueue_config_fd < 0) {
+			polkit_debug ("failed '" PACKAGE_SYSCONF_DIR "/PolicyKit/PolicyKit.conf' for reading: %s",
+				strerror (errno));
+			/* TODO: set error */
+			goto error;
+		}
+
+		EV_SET (&ev, pk_context->kqueue_config_fd, EVFILT_VNODE,
+			EV_ADD | EV_ENABLE | EV_CLEAR,
+			NOTE_DELETE | NOTE_EXTEND | NOTE_WRITE | NOTE_RENAME,
+			0, 0);
+		if (kevent (pk_context->kqueue_fd, &ev, 1, NULL, 0, NULL) == -1) {
+			polkit_debug ("failed to add watch on file '" PACKAGE_SYSCONF_DIR "/PolicyKit/PolicyKit.conf': %s",
+				strerror (errno));
+			close (pk_context->kqueue_config_fd);
+			/* TODO: set error */
+			goto error;
+		}
+
+		/* Watch the /usr/share/PolicyKit/policy directory */
+		pk_context->kqueue_policy_fd = open (PACKAGE_DATA_DIR "/PolicyKit/policy", O_RDONLY);
+		if (pk_context->kqueue_policy_fd < 0) {
+			polkit_debug ("failed to open '" PACKAGE_DATA_DIR "/PolicyKit/policy for reading: %s",
+				strerror (errno));
+			/* TODO: set error */
+			goto error;
+		}
+
+		EV_SET (&ev, pk_context->kqueue_policy_fd, EVFILT_VNODE,
+			EV_ADD | EV_ENABLE | EV_CLEAR,
+			NOTE_DELETE | NOTE_EXTEND | NOTE_WRITE | NOTE_RENAME,
+			0, 0);
+		if (kevent (pk_context->kqueue_fd, &ev, 1, NULL, 0, NULL) == -1) {
+			polkit_debug ("failed to add watch on directory '" PACKAGE_DATA_DIR "/PolicyKit/policy': %s",
+				strerror (errno));
+			close (pk_context->kqueue_policy_fd);
+			/* TODO: set error */
+			goto error;
+		}
+
+#ifdef POLKIT_AUTHDB_DEFAULT
+		/* Watch the /var/lib/misc/PolicyKit.reload file */
+		pk_context->kqueue_grant_perm_fd = open (PACKAGE_LOCALSTATE_DIR "/lib/misc/PolicyKit.reload", O_RDONLY);
+		if (pk_context->kqueue_grant_perm_fd < 0) {
+			polkit_debug ("failed to open '" PACKAGE_LOCALSTATE_DIR "/lib/misc/PolicyKit.reload' for reading: %s",
+				strerror (errno));
+			/* TODO: set error */
+			goto error;
+		}
+
+		EV_SET (&ev, pk_context->kqueue_grant_perm_fd, EVFILT_VNODE,
+			EV_ADD | EV_ENABLE | EV_CLEAR,
+			NOTE_DELETE | NOTE_EXTEND | NOTE_WRITE | NOTE_RENAME | NOTE_ATTRIB,
+			0, 0);
+		if (kevent (pk_context->kqueue_fd, &ev, 1, NULL, 0, NULL) == -1) {
+			polkit_debug ("failed to add watch on file '" PACKAGE_LOCALSTATE_DIR "/lib/misc/PolicyKit.reload': %s",
+				strerror (errno));
+			close (pk_context->kqueue_grant_perm_fd);
+			/* TODO: set error */
+			goto error;
+		}
+#endif
 
+		pk_context->kqueue_fd_watch_id = pk_context->io_add_watch_func (pk_context, pk_context->kqueue_fd);
+		if (pk_context->kqueue_fd_watch_id == 0) {
+			polkit_debug ("failed to add io watch");
+			/* TODO: set error */
+			goto error;
+		}
+	}
 #else
         if (pk_context->io_add_watch_func != NULL) {
                 pk_context->inotify_fd = inotify_init ();
@@ -444,6 +542,35 @@ polkit_context_io_func (PolKitContext *p
                 }
         }
 
+#elif HAVE_KQUEUE
+	if (fd == pk_context->kqueue_fd) {
+		struct kevent ev[1024];
+		struct timespec nullts = { 0, 0 };
+		int res;
+		int i = 0;
+
+		res = kevent (fd, NULL, 0, ev, 1024, &nullts);
+
+		if (res > 0) {
+			/* Sleep for a half-second to avoid potential races
+			 * during install/uninstall. */
+			usleep (500000);
+
+			while (i < res) {
+				struct kevent *evptr;
+
+				evptr = &ev[i];
+				polkit_debug ("ident=%d filter=%d flags=%u fflags=%u",
+					   evptr->ident, evptr->filter, evptr->flags, evptr->fflags);
+				polkit_debug ("config changed!");
+				config_changed = TRUE;
+
+				i++;
+			}
+		} else {
+			polkit_debug ("failed to read kqueue event: %s", strerror (errno));
+		}
+	}
 #else
         if (fd == pk_context->inotify_fd) {
 /* size of the event structure, not counting name */
