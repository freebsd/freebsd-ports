--- src/labels.h.orig	2018-11-23 02:16:45 UTC
+++ src/labels.h
@@ -30,11 +30,17 @@
 #ifndef LABELS_H_INCLUDED
 #define LABELS_H_INCLUDED
 
+#ifdef ENABLE_NLS
 #include <libintl.h>
 
 #define _(String) dgettext (PACKAGE , String)
 #define gettext_noop(String) String
 #define N_(String) gettext_noop (String)
+#else
+#define _(String) String
+#define gettext_noop(String) String
+#define N_(String) String
+#endif
 
 /* global lang attribute */
 #define DOC_LANG                 _( "en")
