--- Makefile.PL.orig	2007-07-29 15:52:47.000000000 +0400
+++ Makefile.PL	2007-07-29 15:52:55.000000000 +0400
@@ -4,7 +4,7 @@
   # Hack to avoid rpm conflicts with old man page.
   MAN3EXT => 3,
   # Hack to force this version to override.
-  INSTALLSITELIB => "\$(INSTALLARCHLIB)",
+#  INSTALLSITELIB => "\$(INSTALLARCHLIB)",
 };
 WriteMakefile
   NAME => "Net::Ping",
