--- docsis_decode.c.orig	Fri Jul  5 14:54:11 2002
+++ docsis_decode.c	Fri Jul  5 14:55:31 2002
@@ -47,7 +47,7 @@
   memset( &helper, 0,sizeof(unsigned int));
   memcpy( &helper, tlvbuf+2, sizeof(unsigned int));
 
-  printf ( "%s %u;\n", sym->sym_ident, ntohl(helper));
+  printf ( "%s %u;\n", sym->sym_ident, (unsigned int)ntohl(helper));
 }
 
 void decode_ushort (unsigned char *tlvbuf, symbol_type *sym)
