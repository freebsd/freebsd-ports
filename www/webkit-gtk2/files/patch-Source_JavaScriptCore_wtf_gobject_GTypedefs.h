--- Source/JavaScriptCore/wtf/gobject/GTypedefs.h.orig	2013-01-27 14:57:47.000000000 +0000
+++ Source/JavaScriptCore/wtf/gobject/GTypedefs.h	2013-01-27 14:57:56.000000000 +0000
@@ -52,7 +52,7 @@
 typedef struct _GHashTable GHashTable;
 typedef struct _GInputStream GInputStream;
 typedef struct _GList GList;
-typedef struct _GMutex GMutex;
+typedef union _GMutex GMutex;
 typedef struct _GPatternSpec GPatternSpec;
 typedef struct _GPollableOutputStream GPollableOutputStream;
 typedef struct _GSocketClient GSocketClient;
