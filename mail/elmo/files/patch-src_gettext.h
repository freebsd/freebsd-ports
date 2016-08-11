--- src/gettext.h.orig	2003-04-26 19:01:59 UTC
+++ src/gettext.h
@@ -42,7 +42,7 @@
    for invalid uses of the value returned from these functions.
    On pre-ANSI systems without 'const', the config.h file is supposed to
    contain "#define const".  */
-# define gettext(Msgid) ((const char *) (Msgid))
+# define gettext(Msgid) ((char *) (Msgid))
 # define dgettext(Domainname, Msgid) ((const char *) (Msgid))
 # define dcgettext(Domainname, Msgid, Category) ((const char *) (Msgid))
 # define ngettext(Msgid1, Msgid2, N) \
