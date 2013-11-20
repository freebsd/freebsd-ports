--- library/gnome-keyring.c.orig	Fri Aug 17 12:15:17 2012
+++ library/gnome-keyring.c	Sat Oct 27 14:36:16 2012
@@ -51,6 +51,8 @@
 #include <sys/uio.h>
 #include <stdarg.h>
 
+EGG_SECURE_DECLARE (libgnome_keyring);
+
 typedef gboolean (*DecodeCallback) (DBusMessageIter *, gpointer);
 
 typedef gboolean (*DecodeDictCallback) (const gchar *, DBusMessageIter *, gpointer);
