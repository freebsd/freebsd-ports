--- packages/tmail/ext/tmail/mails/mails.c.orig	Sun Nov 10 23:18:39 2002
+++ packages/tmail/ext/tmail/mails/mails.c	Sat Nov 16 04:55:28 2002
@@ -58,7 +58,7 @@
 
 static VALUE
 mails_s_new(klass, str, ident, cmt)
-    VALUE klass;
+    VALUE klass, str, ident, cmt;
 {
     struct scanner *sc;
     const char *tmp;
