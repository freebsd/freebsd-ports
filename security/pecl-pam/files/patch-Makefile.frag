--- Makefile.frag.orig	2026-10-26 06:40:28 UTC
+++ Makefile.frag
@@ -5,4 +5,4 @@ pam_version.h:
 pam.lo: pam_version.h
 
 pam_version.h:
-	@bash $(top_srcdir)/scripts/sync-version.sh
+	@sh $(top_srcdir)/scripts/sync-version.sh
