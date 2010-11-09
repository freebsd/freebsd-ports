--- src/http.h.orig	2007-12-09 15:03:36.000000000 +0200
+++ src/http.h	2010-11-09 14:29:36.150630970 +0200
@@ -25,6 +25,21 @@
 #include <upnp/upnp.h>
 #include <upnp/upnptools.h>
 
+#ifdef __FreeBSD__
+struct UpnpVirtualDirCallbacks {
+int               (*get_info) __P((const char *filename, struct File_Info *info)) ;
+UpnpWebFileHandle (*open)     __P((const char *filename, enum UpnpOpenFileMode mode)) ;
+int               (*read)     __P((UpnpWebFileHandle fh, char *buf, size_t buflen)) ;
+int               (*write)    __P((UpnpWebFileHandle fh __attribute__((unused)),
+                                   char *buf __attribute__((unused)),
+                                   size_t buflen __attribute__((unused)))) ;
+int               (*seek)     __P((UpnpWebFileHandle fh, off_t offset, int origin)) ;
+int               (*close)    __P((UpnpWebFileHandle fh)) ;
+} ;
+
+extern struct UpnpVirtualDirCallbacks virtual_dir_callbacks;
+#else
 struct UpnpVirtualDirCallbacks virtual_dir_callbacks;
+#endif /* __FreeBSD__ */
 
 #endif /* _HTTP_H_ */
