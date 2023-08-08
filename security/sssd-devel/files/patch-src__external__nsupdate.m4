--- src/external/nsupdate.m4.orig	2023-05-05 08:11:07 UTC
+++ src/external/nsupdate.m4
@@ -1,4 +1,4 @@
-AC_PATH_PROG(NSUPDATE, nsupdate)
+AC_PATH_PROG(NSUPDATE, samba-nsupdate)
 AC_MSG_CHECKING(for executable nsupdate)
 if test -x "$NSUPDATE"; then
   AC_DEFINE_UNQUOTED([NSUPDATE_PATH], ["$NSUPDATE"], [The path to nsupdate])
