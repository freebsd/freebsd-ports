--- cfs_fh.c.orig	Sat Apr 17 20:44:41 2004
+++ cfs_fh.c	Sat Apr 17 23:01:11 2004
@@ -225,7 +225,9 @@
 }
 
 /*
- * set high order bits
+ * Carefully frob the high order bits of s in a way that is both easily
+ * reversible (see unchksum) and backwards-compatible (at least for 7-bit
+ * characters).
  */
 chksum(s,l)
      char *s;
@@ -236,16 +238,44 @@
 	u_char bits[8];
 
 	acc=0;
-	for (i=0; s[i]!='\0'; i++)
-		acc += s[i]*((i%6)+1);
+	/* Everything we do here must be reproducible without knowledge of
+	   bit 7 because unchksum won't have that information.  Therefore,
+	   only accumulate the lower 7 bits of each char and stop at the
+	   first occurrence of either 0x00 or 0x80.  Note that, for inputs
+	   with bit 7 constantly zero, this is equivalent to looking at the
+	   whole string. */
+	for (i=0; (s[i]&0x7f) != '\0'; i++)
+		acc += (s[i]&0x7f)*((i%6)+1);
+	for (; s[i]!='\0'; i++) /* advance i if we stopped at a 0x80 */
+		;
 	for (i++; i<l; i++)	/* fill up the end */
 		s[i] = s[i%8];
 	for (i=0; i<8; i++)
 		bits[i] = (acc<<(i%8))&0x80;
 	for (i=0; i<l; i++)
-		s[i] |= bits[i%8];
+		s[i] ^= bits[i%8];
 }
 
+unchksum(s,l)
+    char *s;
+    long l;
+{
+	u_long acc;
+	int i;
+	u_char bits[8];
+
+	acc=0;
+	for (i=0; (s[i]&0x7f) != '\0'; i++)
+		acc += (s[i]&0x7f)*((i%6)+1);
+	for (i=0; i<8; i++)
+		bits[i] = (acc<<(i%8))&0x80;
+	for (i=0; i<l; i++) {
+		s[i] ^= bits[i%8];
+		/* not sure whether this actually buys any performance */
+		if(s[i]=='\0')
+			break;  /* found end of filename, can stop here */
+	}
+}
 
 /*
  * decrypt path component
@@ -286,8 +316,7 @@
 	if (l%CFSBLOCK)
 		return NULL;
 	dodecrypt(key,clearstring,l,10241,zerovect);
-	for (i=0; (clearstring[i]&0x7f) !='\0'; i++)
-		clearstring[i] &= 0x7f;
+	unchksum(clearstring,l);
 	clearstring[i]='\0';
 	return clearstring;
 }
