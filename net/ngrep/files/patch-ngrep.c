--- ngrep.c.orig	Mon Jun 26 12:52:50 2000
+++ ngrep.c	Wed Aug  9 02:16:59 2000
@@ -50,0 +51 @@
+extern FILE *yyin;
@@ -199 +200 @@
-      PCAP_RESTART();
+      PCAP_RESTART(yyin);
