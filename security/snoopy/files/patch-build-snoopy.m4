--- build/snoopy.m4.orig	2020-12-07 03:14:46 UTC
+++ build/snoopy.m4
@@ -191,7 +191,8 @@ AU_DEFUN([SNOOPY_CONFIGURE_ENTITY_MSG],
         [
             dotLine="..................................................";
             whatString="Snoopy $1 enabled: $3 ";
-            whatStringPadded="$whatString${dotLine:${#whatString}}";
+            dotLine2=$(echo ${dotLine} | cut -d. -f${#whatString}-)
+            whatStringPadded="$whatString${dotLine2}";
             if test "x$4" == "xyes"; then
                 AC_MSG_NOTICE([$whatStringPadded YES])
             elif test "x$4" == "xno"; then
