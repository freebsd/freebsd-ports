--- conf/dokuwiki.php.orig	Fri Feb 18 21:04:39 2005
+++ conf/dokuwiki.php	Mon Apr 18 07:14:35 2005
@@ -17,7 +17,7 @@
 $conf['mediadir']    = './media';         //where to store media files
 $conf['mediaweb']    = 'media';           //access to media from the web
 $conf['changelog']   = './changes.log';   //change log
-$conf['uploadtypes'] = 'gif|jpe?g|png|zip|pdf|tar(\.gz)?|tgz'; //regexp of allowed filetypes to upload
+$conf['uploadtypes'] = '(gif|jpe?g|png|zip|pdf|tar(\.gz)?|tgz)'; //regexp of allowed filetypes to upload
 
 /* Display Options */
 
