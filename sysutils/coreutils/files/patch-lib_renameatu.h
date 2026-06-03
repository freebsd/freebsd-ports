--- lib/renameatu.h.orig	2026-03-09 21:11:48 UTC
+++ lib/renameatu.h
@@ -27,7 +27,13 @@ extern "C" {
 
 #ifndef RENAME_NOREPLACE
 # define RENAME_NOREPLACE  (1 << 0)
+#endif
+
+#ifndef RENAME_EXCHANGE
 # define RENAME_EXCHANGE   (1 << 1)
+#endif
+
+#ifndef RENAME_WHITEOUT
 # define RENAME_WHITEOUT   (1 << 2)
 #endif
 
