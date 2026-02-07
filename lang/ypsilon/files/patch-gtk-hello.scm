--- example/gtk-hello.scm.orig	2008-12-27 17:14:34.000000000 +0200
+++ example/gtk-hello.scm	2008-12-27 17:15:07.000000000 +0200
@@ -7,6 +7,7 @@
 ;; Requirements:
 ;;   Darwin:  Gtk.framework
 ;;   Linux:   libgtk-x11-2.0.so.0
+;;   FreeBSD: libgtk-x11-2.0.so
 
 (import (rnrs)
         (srfi :28)
@@ -16,6 +17,7 @@
 
 (define libgtk-name (cond (on-linux "libgtk-x11-2.0.so.0")
                           (on-darwin "Gtk.framework/Gtk")
+                          (on-freebsd "libgtk-x11-2.0.so")
                           (else
                            (assertion-violation #f "can not locate GTK library, unknown operating system"))))
 
