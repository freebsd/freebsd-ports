Hi,

some folks asked what the message

  gpg: this cipher algorithm is depreciated; please use a more standard one!

does mean.  Yes, gpg 1.0.4 should not emit this message.  I forgot
to put the AES cipher algorithm into the list of "good" algorithms.

Either ignore this message or apply the patch below.

  Werner


Index: g10/misc.c
===================================================================
RCS file: /home/koch/cvs/gnupg/g10/misc.c,v
retrieving revision 1.16.2.4
diff -u -r1.16.2.4 misc.c
--- g10/misc.c	2000/10/13 15:03:48	1.16.2.4
+++ g10/misc.c	2000/10/18 13:34:01
@@ -224,6 +224,9 @@
 	     || algo == CIPHER_ALGO_CAST5
 	     || algo == CIPHER_ALGO_BLOWFISH
 	     || algo == CIPHER_ALGO_TWOFISH
+	     || algo == CIPHER_ALGO_RIJNDAEL
+	     || algo == CIPHER_ALGO_RIJNDAEL192
+	     || algo == CIPHER_ALGO_RIJNDAEL256
 	   )
 	;
     else {
