From bd48ad11fd11412c62c3ac8ed5d52c4f10a985aa Mon Sep 17 00:00:00 2001
From: Joerg Sonnenberger <joerg@britannica.bec.de>
Date: Sun, 21 Aug 2011 16:51:53 +0000
Subject: Do proper input validation to fix for CVE-2011-2895.

It ensures that all valid input can be decompressed, checks that the
overflow conditions doesn't happen and generally tightens the
validation of the LZW stream and doesn't pessimize the inner loop for
no good reason. It's derived from a change in libarchive from 2004.

Signed-off-by: Matthieu Herrb <matthieu.herrb@laas.fr>
Reviewed-by: Tomas Hoger <thoger@redhat.com>

--- src/fontfile/decompress.c.orig	2011-08-10 22:22:01.000000000 +0200
+++ src/fontfile/decompress.c	2012-03-13 12:55:35.000000000 +0100
@@ -97,7 +97,7 @@ static char_type magic_header[] = { "\03
 #define FIRST	257	/* first free entry */
 #define	CLEAR	256	/* table clear output code */
 
-#define STACK_SIZE  8192
+#define STACK_SIZE  65300
 
 typedef struct _compressedFILE {
     BufFilePtr	    file;
@@ -178,14 +178,12 @@ BufFilePushCompressed (BufFilePtr f)
 	file->tab_suffix[code] = (char_type) code;
     }
     file->free_ent = ((file->block_compress) ? FIRST : 256 );
+    file->oldcode = -1;
     file->clear_flg = 0;
     file->offset = 0;
     file->size = 0;
     file->stackp = file->de_stack;
     bzero(file->buf, BITS);
-    file->finchar = file->oldcode = getcode (file);
-    if (file->oldcode != -1)
-	*file->stackp++ = file->finchar;
     return BufFileCreate ((char *) file,
 			  BufCompressedFill,
 			  0,
@@ -230,9 +228,6 @@ BufCompressedFill (BufFilePtr f)
 	if (buf == bufend)
 	    break;
 
-	if (oldcode == -1)
-	    break;
-
 	code = getcode (file);
 	if (code == -1)
 	    break;
@@ -241,26 +236,35 @@ BufCompressedFill (BufFilePtr f)
 	    for ( code = 255; code >= 0; code-- )
 	    	file->tab_prefix[code] = 0;
 	    file->clear_flg = 1;
-	    file->free_ent = FIRST - 1;
-	    if ( (code = getcode (file)) == -1 )	/* O, untimely death! */
-	    	break;
+	    file->free_ent = FIRST;
+	    oldcode = -1;
+	    continue;
     	}
     	incode = code;
     	/*
      	 * Special case for KwKwK string.
      	 */
     	if ( code >= file->free_ent ) {
+	    if ( code > file->free_ent || oldcode == -1 ) {
+		/* Bad stream. */
+		return BUFFILEEOF;
+	    }
 	    *stackp++ = finchar;
 	    code = oldcode;
     	}
-    
+
+	/*
+	 * The above condition ensures that code < free_ent.
+	 * The construction of tab_prefixof in turn guarantees that
+	 * each iteration decreases code and therefore stack usage is
+	 * bound by 1 << BITS - 256.
+	 */
+
     	/*
      	 * Generate output characters in reverse order
      	 */
     	while ( code >= 256 )
     	{
-	    if (stackp - de_stack >= STACK_SIZE - 1)
-		return BUFFILEEOF;
 	    *stackp++ = file->tab_suffix[code];
 	    code = file->tab_prefix[code];
     	}
@@ -270,7 +274,7 @@ BufCompressedFill (BufFilePtr f)
     	/*
      	 * Generate the new entry.
      	 */
-    	if ( (code=file->free_ent) < file->maxmaxcode ) {
+    	if ( (code=file->free_ent) < file->maxmaxcode && oldcode != -1) {
 	    file->tab_prefix[code] = (unsigned short)oldcode;
 	    file->tab_suffix[code] = finchar;
 	    file->free_ent = code+1;
