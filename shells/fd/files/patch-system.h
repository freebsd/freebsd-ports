Taken from: [FDclone-users:00145]

diff -u ../old/FD-2.03a/system.h ./system.h
--- ../old/FD-2.03a/system.h	Tue Apr 15 00:00:00 2003
+++ ./system.h	Tue Apr 22 00:00:00 2003
@@ -185,6 +185,7 @@
 #define	MD_WITHERR	0020
 #define	MD_HEREDOC	0040
 #define	MD_FORCED	0100
+#define	MD_REST		0200
 
 typedef struct _command_t {
 	hashlist *hash;
