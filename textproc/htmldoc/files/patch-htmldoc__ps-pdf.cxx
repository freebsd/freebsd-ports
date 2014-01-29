--- ./htmldoc/ps-pdf.cxx.orig	2014-01-06 04:42:43.000000000 +0100
+++ ./htmldoc/ps-pdf.cxx	2014-01-28 04:47:41.000000000 +0100
@@ -120,13 +120,9 @@
 
 /*#define DEBUG*/
 #include "htmldoc.h"
-#include "md5-private.h"
-#define md5_append _cupsMD5Append
-#define md5_finish _cupsMD5Finish
-#define md5_init _cupsMD5Init
 typedef unsigned char md5_byte_t;
-#define md5_state_t _cups_md5_state_t
-#include "rc4.h"
+#include <openssl/md5.h>
+#include <openssl/rc4.h>
 #include <stdarg.h>
 #include <ctype.h>
 #include <time.h>
@@ -331,8 +327,8 @@
 static uchar		comp_buffer[8192];
 static uchar		encrypt_key[16];
 static int		encrypt_len;
-static rc4_context_t	encrypt_state;
-static md5_byte_t	file_id[16];
+static RC4_KEY	encrypt_state;
+static unsigned char	file_id[16];
 
 
 /*
@@ -10545,7 +10541,7 @@
 	    {
 	      // Encrypt the colormap...
 	      encrypt_init();
-	      rc4_encrypt(&encrypt_state, cmap[0], cmap[0], ncolors * 3);
+	      RC4(&encrypt_state, ncolors * 3, cmap[0], cmap[0]);
 	    }
 
 	    fprintf(out, "/ColorSpace[/Indexed/DeviceRGB %d<", ncolors - 1);
@@ -11166,9 +11162,9 @@
   int		font_desc[TYPE_MAX][STYLE_MAX];
 					/* Font descriptor objects */
   char		temp[1024];		/* Temporary string */
-  md5_state_t	md5;			/* MD5 state */
-  md5_byte_t	digest[16];		/* MD5 digest value */
-  rc4_context_t	rc4;			/* RC4 context */
+  MD5_CTX	md5;			/* MD5 state */
+  unsigned char	digest[16];		/* MD5 digest value */
+  RC4_KEY	rc4;			/* RC4 context */
   uchar		owner_pad[32],		/* Padded owner password */
 		owner_key[32],		/* Owner key */
 		user_pad[32],		/* Padded user password */
@@ -11568,10 +11564,10 @@
     * Compute the file ID...
     */
 
-    md5_init(&md5);
-    md5_append(&md5, (md5_byte_t *)OutputPath, sizeof(OutputPath));
-    md5_append(&md5, (md5_byte_t *)&doc_time, sizeof(doc_time));
-    md5_finish(&md5, file_id);
+    MD5_Init(&md5);
+    MD5_Update(&md5, (unsigned char *)OutputPath, sizeof(OutputPath));
+    MD5_Update(&md5, (unsigned char *)&doc_time, sizeof(doc_time));
+    MD5_Final(file_id, &md5);
 
    /*
     * Setup encryption stuff as necessary...
@@ -11627,18 +11623,18 @@
       * Compute the owner key...
       */
 
-      md5_init(&md5);
-      md5_append(&md5, owner_pad, 32);
-      md5_finish(&md5, digest);
+      MD5_Init(&md5);
+      MD5_Update(&md5, owner_pad, 32);
+      MD5_Final(digest, &md5);
 
       if (encrypt_len > 5)
       {
         // MD5 the result 50 more times...
 	for (i = 0; i < 50; i ++)
 	{
-          md5_init(&md5);
-          md5_append(&md5, digest, 16);
-          md5_finish(&md5, digest);
+          MD5_Init(&md5);
+          MD5_Update(&md5, digest, 16);
+          MD5_Final(digest, &md5);
 	}
 
         // Copy the padded user password...
@@ -11651,14 +11647,14 @@
 	  for (j = 0; j < encrypt_len; j ++)
 	    encrypt_key[j] = digest[j] ^ i;
 
-          rc4_init(&rc4, encrypt_key, encrypt_len);
-          rc4_encrypt(&rc4, owner_key, owner_key, 32);
+          RC4_set_key(&rc4, encrypt_len, encrypt_key);
+          RC4(&rc4, 32, owner_key, owner_key);
 	}
       }
       else
       {
-        rc4_init(&rc4, digest, encrypt_len);
-        rc4_encrypt(&rc4, user_pad, owner_key, 32);
+        RC4_set_key(&rc4, encrypt_len, digest);
+        RC4(&rc4, 32, user_pad, owner_key);
       }
 
      /*
@@ -11680,27 +11676,27 @@
       * Compute the encryption key...
       */
 
-      md5_init(&md5);
-      md5_append(&md5, user_pad, 32);
-      md5_append(&md5, owner_key, 32);
+      MD5_Init(&md5);
+      MD5_Update(&md5, user_pad, 32);
+      MD5_Update(&md5, owner_key, 32);
 
       perm_bytes[0] = perm_value;
       perm_bytes[1] = perm_value >> 8;
       perm_bytes[2] = perm_value >> 16;
       perm_bytes[3] = perm_value >> 24;
 
-      md5_append(&md5, perm_bytes, 4);
-      md5_append(&md5, file_id, 16);
-      md5_finish(&md5, digest);
+      MD5_Update(&md5, perm_bytes, 4);
+      MD5_Update(&md5, file_id, 16);
+      MD5_Final(digest, &md5);
 
       if (encrypt_len > 5)
       {
         // MD5 the result 50 times..
         for (i = 0; i < 50; i ++)
 	{
-	  md5_init(&md5);
-	  md5_append(&md5, digest, 16);
-	  md5_finish(&md5, digest);
+	  MD5_Init(&md5);
+	  MD5_Update(&md5, digest, 16);
+	  MD5_Final(digest, &md5);
 	}
       }
 
@@ -11712,10 +11708,10 @@
 
       if (encrypt_len > 5)
       {
-        md5_init(&md5);
-        md5_append(&md5, pad, 32);
-        md5_append(&md5, file_id, 16);
-        md5_finish(&md5, user_key);
+        MD5_Init(&md5);
+        MD5_Update(&md5, pad, 32);
+        MD5_Update(&md5, file_id, 16);
+        MD5_Final(user_key, &md5);
 
         memset(user_key + 16, 0, 16);
 
@@ -11726,14 +11722,14 @@
 	  for (j = 0; j < encrypt_len; j ++)
 	    digest[j] = encrypt_key[j] ^ i;
 
-          rc4_init(&rc4, digest, encrypt_len);
-          rc4_encrypt(&rc4, user_key, user_key, 16);
+          RC4_set_key(&rc4, encrypt_len, digest);
+          RC4(&rc4, 16, user_key, user_key);
 	}
       }
       else
       {
-        rc4_init(&rc4, encrypt_key, encrypt_len);
-        rc4_encrypt(&rc4, pad, user_key, 32);
+        RC4_set_key(&rc4, encrypt_len, encrypt_key);
+        RC4(&rc4, 32, pad, user_key);
       }
 
      /*
@@ -11920,7 +11916,7 @@
       else
         bytes = len;
 
-      rc4_encrypt(&encrypt_state, s, news, bytes);
+      RC4(&encrypt_state, bytes, s, news);
 
       for (i = 0; i < bytes; i ++)
         fprintf(out, "%02x", news[i]);
@@ -12585,7 +12581,7 @@
     unicode[0] = 0xfe;			// Start with BOM
     unicode[1] = 0xff;
 
-    rc4_encrypt(&encrypt_state, unicode, enicode, 2);
+    RC4(&encrypt_state, 2, unicode, enicode);
 
     fprintf(out, "%02x%02x", enicode[0], enicode[1]);
 
@@ -12595,7 +12591,7 @@
       unicode[0] = ch >> 8;
       unicode[1] = ch;
 
-      rc4_encrypt(&encrypt_state, unicode, enicode, 2);
+      RC4(&encrypt_state, 2, unicode, enicode);
 
       fprintf(out, "%02x%02x", enicode[0], enicode[1]);
     }
@@ -12627,8 +12623,8 @@
   int		i;			/* Looping var */
   uchar		data[21],		/* Key data */
 		*dataptr;		/* Pointer to key data */
-  md5_state_t	md5;			/* MD5 state */
-  md5_byte_t	digest[16];		/* MD5 digest value */
+  MD5_CTX	md5;			/* MD5 state */
+  unsigned char	digest[16];		/* MD5 digest value */
 
 
  /*
@@ -12648,18 +12644,18 @@
   * Hash it...
   */
 
-  md5_init(&md5);
-  md5_append(&md5, data, encrypt_len + 5);
-  md5_finish(&md5, digest);
+  MD5_Init(&md5);
+  MD5_Update(&md5, data, encrypt_len + 5);
+  MD5_Final(digest, &md5);
 
  /*
   * Initialize the RC4 context using the first N+5 bytes of the digest...
   */
 
   if (encrypt_len > 11)
-    rc4_init(&encrypt_state, digest, 16);
+    RC4_set_key(&encrypt_state, 16, digest);
   else
-    rc4_init(&encrypt_state, digest, encrypt_len + 5);
+    RC4_set_key(&encrypt_state, encrypt_len + 5, digest);
 }
 
 
@@ -12727,8 +12723,8 @@
     else
     {
       if (Encryption)
-        rc4_encrypt(&encrypt_state, comp_buffer, comp_buffer,
-	            (uchar *)compressor.next_out - (uchar *)comp_buffer);
+        RC4(&encrypt_state, (uchar *)compressor.next_out - (uchar *)comp_buffer,
+	    comp_buffer, comp_buffer);
 
       fwrite(comp_buffer, (uchar *)compressor.next_out - (uchar *)comp_buffer,
              1, out);
@@ -12751,8 +12747,8 @@
     else
     {
       if (Encryption)
-        rc4_encrypt(&encrypt_state, comp_buffer, comp_buffer,
-	            (uchar *)compressor.next_out - (uchar *)comp_buffer);
+        RC4(&encrypt_state, (uchar *)compressor.next_out - (uchar *)comp_buffer,
+	    comp_buffer, comp_buffer);
 
       fwrite(comp_buffer, (uchar *)compressor.next_out - (uchar *)comp_buffer,
              1, out);
@@ -12844,8 +12840,8 @@
 	else
 	{
 	  if (Encryption)
-            rc4_encrypt(&encrypt_state, comp_buffer, comp_buffer,
-	        	(uchar *)compressor.next_out - (uchar *)comp_buffer);
+		RC4(&encrypt_state, (uchar *)compressor.next_out - (uchar *)comp_buffer,
+		    comp_buffer, comp_buffer);
 
 	  fwrite(comp_buffer,
 	         (uchar *)compressor.next_out - (uchar *)comp_buffer, 1, out);
@@ -12878,7 +12874,7 @@
       if ((bytes = length - i) > (int)sizeof(newbuf))
         bytes = sizeof(newbuf);
 
-      rc4_encrypt(&encrypt_state, buf + i, newbuf, bytes);
+      RC4(&encrypt_state, bytes, buf + i, newbuf);
       fwrite(newbuf, bytes, 1, out);
     }
   }
