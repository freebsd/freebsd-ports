--- src/PlatformSpecific.h.orig	2011-11-20 19:08:59.000000000 +0100
+++ src/PlatformSpecific.h	2012-10-13 12:34:46.000000000 +0200
@@ -100,6 +100,8 @@
 {
 	switch (GetFilesystemType(path)) {
 		case fsFAT:
+		// Backported from r10794
+		case fsNTFS:
 		case fsHFS:
 			return false;
 		default:
