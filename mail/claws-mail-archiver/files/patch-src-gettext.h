$FreeBSD$

Index: src/gettext.h
===================================================================
RCS file: /home/claws-mail/plugins/archive/src/Attic/gettext.h,v
retrieving revision 1.1.2.2
retrieving revision 1.1.2.3
diff -u -r1.1.2.2 -r1.1.2.3
--- src/gettext.h	6 Jan 2012 14:10:15 -0000	1.1.2.2
+++ src/gettext.h	9 Jul 2012 05:06:19 -0000	1.1.2.3
@@ -69,7 +69,7 @@
 # define bind_textdomain_codeset(Domainname, Codeset) ((const char *) (Codeset))
 
 #define _(str)		str
-
+#define D_(domain, str)	(domain, str)
 #endif
 
 /* A pseudo function call that serves as a marker for the automated
