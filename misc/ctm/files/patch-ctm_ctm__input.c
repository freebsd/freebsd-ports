--- ctm/ctm_input.c.orig	2018-10-27 15:56:22 UTC
+++ ctm/ctm_input.c
@@ -63,11 +63,11 @@ Ffield(FILE *fd, MD5_CTX *ctx,u_char term)
     return buf;
 }
 
-int
+intmax_t
 Fbytecnt(FILE *fd, MD5_CTX *ctx, u_char term)
 {
     u_char *p,*q;
-    int u_chars=0;
+    intmax_t u_chars=0;
 
     p = Ffield(fd,ctx,term);
     if(!p) return -1;
@@ -101,6 +101,42 @@ Fdata(FILE *fd, int u_chars, MD5_CTX *ctx)
     p[u_chars] = '\0';
     return p;
 }
+
+int Fforward(FILE *fd, intmax_t u_chars, MD5_CTX *ctx, FILE *fd_to)
+{
+    u_char buf[BUFSIZ];
+    intmax_t amount_read = 0;
+    int amount_to_read;
+
+    while (amount_read < u_chars) {
+	if (u_chars - amount_read >= BUFSIZ)
+	    amount_to_read = BUFSIZ;
+	else
+	    amount_to_read = u_chars - amount_read;
+	if(amount_to_read != fread(buf, 1, amount_to_read, fd)) {
+	    Fatal("Truncated patch.");
+	    return 0;
+	}
+	MD5Update(ctx,buf,amount_to_read);
+	if (fd_to != NULL) {
+	    if (amount_to_read != fwrite(buf, 1, amount_to_read, fd_to)) {
+		Fatal("Write error.");
+		return 0;
+	    }
+	}
+	amount_read += amount_to_read;
+    }
+
+    if(getc(fd) != '\n') {
+	if(Verbose > 3)
+	    printf("FileData wasn't followed by a newline.\n");
+        Fatal("Corrupt patch.");
+	return 0;
+    }
+    MD5Update(ctx,"\n",1);
+    return 1;
+}
+
 
 /*---------------------------------------------------------------------------*/
 /* get the filename in the next field, prepend BaseDir and give back the result
