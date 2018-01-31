--- build/snoopy.m4.orig	2016-09-14 15:02:26 UTC
+++ build/snoopy.m4
@@ -183,7 +183,8 @@ AU_DEFUN([SNOOPY_CONFIGURE_ENTITY_MSG],
         [
             dotLine="..................................................";
             whatString="Snoopy $1 enabled: $3 ";
-            whatStringPadded="$whatString${dotLine:${#whatString}}";
+            dotLine2=$(echo ${dotLine} | cut -d. -f${#whatString}-)
+            whatStringPadded="$whatString${dotLine2}";
             if test "x$4" == "xyes"; then
                 AC_MSG_NOTICE([$whatStringPadded YES])
             elif test "x$4" == "xno"; then
