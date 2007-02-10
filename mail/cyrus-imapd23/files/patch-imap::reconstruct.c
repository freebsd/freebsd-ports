Index: imap/reconstruct.c
diff -u -p imap/reconstruct.c.orig imap/reconstruct.c
--- imap/reconstruct.c.orig	Tue Feb  6 03:41:48 2007
+++ imap/reconstruct.c	Sat Feb 10 18:52:48 2007
@@ -577,8 +577,7 @@ reconstruct_expunge (char * path, struct
 	    free(expuid);
 	    return IMAP_IOERROR;
    	}
-	unsigned msgno;
-	const char *p = index_base + start_offset;
+	p = index_base + start_offset;
 
 	/* 
 	* verify the message files exist - 
