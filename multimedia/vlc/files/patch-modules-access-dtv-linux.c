--- modules/access/dtv/linux.c.orig
+++ modules/access/dtv/linux.c
@@ -173,7 +173,14 @@ static int dvb_open_adapter (uint8_t ada
     char dir[20];
 
     snprintf (dir, sizeof (dir), "/dev/dvb/adapter%"PRIu8, adapter);
+#ifdef O_CLOEXEC
     return open (dir, O_SEARCH|O_DIRECTORY|O_CLOEXEC);
+#else
+    int fd = open (dir, O_SEARCH|O_DIRECTORY);
+    if (fd != -1)
+        fcntl(fd, F_SETFD, FD_CLOEXEC);
+    return fd;
+#endif
 }
 
 /** Opens the DVB device node of the specified type */
@@ -183,7 +190,13 @@ static int dvb_open_node (dvb_device_t *
     char path[strlen (type) + 4];
 
     snprintf (path, sizeof (path), "%s%u", type, d->device);
+#ifdef O_CLOEXEC
     fd = openat (d->dir, path, flags|O_CLOEXEC);
+#else
+    fd = openat (d->dir, path, flags);
+    if (fd != -1)
+        fcntl(fd, F_SETFD, FD_CLOEXEC);
+#endif
     if (fd != -1)
         fcntl (fd, F_SETFL, fcntl (fd, F_GETFL) | O_NONBLOCK);
     return fd;
