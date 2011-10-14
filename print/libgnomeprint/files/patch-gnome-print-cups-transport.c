=========================
commit 9b82b7e75b83395e7c5692085e1934202cf7f65f
Author: Jeremy Huddleston <jeremyhu@freedesktop.org>
Date:   Wed Oct 12 17:08:59 2011 +0200

    Add missing include

    https://bugzilla.gnome.org/show_bug.cgi?id=653388

=========================

--- libgnomeprint/modules/cups/gnome-print-cups-transport.c.orig	2010-02-09 05:32:51.000000000 -0700
+++ libgnomeprint/modules/cups/gnome-print-cups-transport.c	2011-10-13 08:27:55.000000000 -0600
@@ -34,6 +34,7 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
+#include <stdio.h>
 #include <unistd.h>
 #include <locale.h>
 
