--- plugins/kerberos4.c.orig	Wed Feb 26 22:20:04 2003
+++ plugins/kerberos4.c	Wed Feb 26 22:30:25 2003
@@ -711,14 +730,18 @@
 #ifdef __FreeBSD__
     des_pcbc_encrypt((const unsigned char *)in,
 		     (unsigned char *)in,
+		     clientinlen,   
+		     text->init_keysched,
+		     &text->session,
+		     DES_DECRYPT);
 #else
     des_pcbc_encrypt((des_cblock *)in,
 		     (des_cblock *)in,
-#endif
 		     clientinlen,
 		     text->init_keysched,
 		     &text->session,
 		     DES_DECRYPT);
+#endif
 
     testnum=(in[0]*256*256*256)+(in[1]*256*256)+(in[2]*256)+in[3];
 
@@ -1255,18 +1278,22 @@
 	    len++;
 	}
 	sout[len]=0;
+
 #ifdef __FreeBSD__
 	des_pcbc_encrypt((const unsigned char *)sout,
- 		     (unsigned char *)sout,
+ 			 (unsigned char *)sout,
+	 		 len,       
+			 text->init_keysched,
+			 (des_cblock *)text->session,
+			 DES_ENCRYPT);
 #else
-    
 	des_pcbc_encrypt((des_cblock *)sout,
 			 (des_cblock *)sout,
-#endif
 			 len,
 			 text->init_keysched,
 			 (des_cblock *)text->session,
 			 DES_ENCRYPT);
+#endif
 
 	*clientout = params->utils->malloc(len);
 	memcpy((char *) *clientout, sout, len);
