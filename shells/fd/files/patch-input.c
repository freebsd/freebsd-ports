[FDclone-users:00278]
  Disable path name completion RENAME_FILE.
--- input.c.orig	Sat Apr 24 01:46:44 2004
+++ input.c	Sun May 23 05:52:56 2004
@@ -2506,7 +2506,7 @@
 #ifndef	_NOCOMPLETE
			case '\t':
				keyflush();
-				if (selectlist) {
+				if (h < 0 || selectlist) {
					ringbell();
					break;
				}
