--- ./mark_read/mark_read.php.orig	2008-02-17 19:51:57.000000000 +0200
+++ ./mark_read/mark_read.php	2008-02-17 19:52:05.000000000 +0200
@@ -106,7 +106,7 @@
     mark_read_mark_mailbox($imap_stream, $mailbox, ($mark=="unread"));
 }
 
-header ('Location: ' . $base_uri . '../../src/left_main.php');
+header ('Location: ' . $base_uri . 'src/left_main.php');
 
 sqimap_logout($imap_stream);
 
