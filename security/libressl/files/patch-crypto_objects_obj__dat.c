untrusted comment: signature from openbsd 5.8 base secret key
RWQNNZXtC/MqPxdRqITWYJITKuMf4PaGPnczCFn+ietYQ+RhccezaFn1ZWlJrue9du2wf4+ENQVydzKTtyZLLtU1UAgEts+A4AM=

OpenBSD 5.8 errata 7, Oct 15, 2015:

The OBJ_obj2txt function in libcrypto contains a one byte buffer overrun
and memory leak, as reported by Qualys Security.

Apply by doing:
    signify -Vep /etc/signify/openbsd-58-base.pub -x 007_obj2txt.patch.sig \
            -m - | (cd /usr/src && patch -p0)

And then rebuild and install libcrypto:
	cd src/lib/libcrypto
	make obj
	make depend
	make
	make install


Index: crypto/objects/obj_dat.c
===================================================================
RCS file: /cvs/src/lib/libssl/src/crypto/objects/obj_dat.c,v
retrieving revision 1.31
diff -u -p -r1.31 obj_dat.c
--- crypto/objects/obj_dat.c	8 Aug 2014 04:53:43 -0000	1.31
+++ crypto/objects/obj_dat.c	14 Oct 2015 21:58:32 -0000
@@ -491,7 +491,6 @@ OBJ_obj2txt(char *buf, int buf_len, cons
 {
 	int i, ret = 0, len, nid, first = 1, use_bn;
 	BIGNUM *bl = NULL;
-	char *bndec = NULL;
 	unsigned long l;
 	const unsigned char *p;
 
@@ -567,14 +566,16 @@ OBJ_obj2txt(char *buf, int buf_len, cons
 		}
 
 		if (use_bn) {
+			char *bndec;
+
 			bndec = BN_bn2dec(bl);
 			if (!bndec)
 				goto err;
 			i = snprintf(buf, buf_len, ".%s", bndec);
+			free(bndec);
 			if (i == -1)
 				goto err;
 			if (i >= buf_len) {
-				buf += buf_len;
 				buf_len = 0;
 			} else {
 				buf += i;
@@ -586,7 +587,6 @@ OBJ_obj2txt(char *buf, int buf_len, cons
 			if (i == -1)
 				goto err;
 			if (i >= buf_len) {
-				buf += buf_len;
 				buf_len = 0;
 			} else {
 				buf += i;
@@ -598,13 +598,11 @@ OBJ_obj2txt(char *buf, int buf_len, cons
 	}
 
 out:
-	free(bndec);
 	BN_free(bl);
 	return ret;
 
 err:
 	ret = 0;
-	buf[0] = '\0';
 	goto out;
 }
 
