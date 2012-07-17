$FreeBSD$

Index: src/gettext.h
===================================================================
RCS file: /home/claws-mail/plugins/gtkhtml2_viewer/src/Attic/gettext.h,v
retrieving revision 1.1.2.3
retrieving revision 1.1.2.4
diff -u -r1.1.2.3 -r1.1.2.4
--- src/gettext.h	6 Jan 2012 14:23:24 -0000	1.1.2.3
+++ src/gettext.h	9 Jul 2012 05:09:48 -0000	1.1.2.4
@@ -69,7 +69,7 @@
 # define bind_textdomain_codeset(Domainname, Codeset) ((const char *) (Codeset))
 
 #define _(str)		str
-
+#define D_(domain, str)	(domain, str)
 #endif
 
 /* A pseudo function call that serves as a marker for the automated
