--- src/common.h.orig	2011-03-09 18:02:34 UTC
+++ src/common.h
@@ -54,6 +54,7 @@
 #  define dcgettext(Domain,Message,Type) (Message)
 #  define bindtextdomain(Domain,Directory) (Domain)
 #  define _(String) (String)
+#  define __(String) (String)
 #  define N_(String) (String)
 #endif
 
