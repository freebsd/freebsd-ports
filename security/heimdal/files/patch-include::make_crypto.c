Index: include/make_crypto.c
===================================================================
RCS file: /home/kth-krb/heimdal/include/make_crypto.c,v
retrieving revision 1.3
retrieving revision 1.4
diff -c -c -r1.3 -r1.4
*** include/make_crypto.c	19 Sep 2002 15:25:14 -0000	1.3
--- include/make_crypto.c	12 Jan 2003 18:54:46 -0000	1.4
***************
*** 60,65 ****
--- 60,66 ----
      fprintf(f, "#ifndef __%s__\n", argv[1]);
      fprintf(f, "#define __%s__\n", argv[1]);
  #ifdef HAVE_OPENSSL
+     fputs("#define OPENSSL_DES_LIBDES_COMPATIBILITY\n", f);
      fputs("#include <openssl/des.h>\n", f);
      fputs("#include <openssl/rc4.h>\n", f);
      fputs("#include <openssl/md4.h>\n", f);
