--- osslsigncode.c.orig	Fri Jan 21 04:23:44 2005
+++ osslsigncode.c	Thu Nov  9 15:31:37 2006
@@ -610,9 +610,10 @@
         
         BIO_write(hash, indata + i, st.st_size - i);
 
-	/* pad (with 0's) pe file to 8 byte boundary */
+	/* pad (with 0's) pe file to 8 byte boundary, but do not pad at all if 
+	   already aligned on 8 byte boundary. See http://sourceforge.net/tracker/index.php?func=detail&aid=1422627&group_id=129143&atid=713906 */
 	len = 8 - st.st_size % 8;
-	if (len > 0) {
+	if (len > 0 && len != 8) {
 	  memset(buf, 0, len);
 	  BIO_write(hash, buf, len);
 	  st.st_size += len;
