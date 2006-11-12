--- fido.c.orig	Sun Nov 12 18:26:36 2006
+++ fido.c	Sun Nov 12 18:28:10 2006
@@ -110,6 +110,16 @@
 #define OPENC   O_WRONLY | O_BINARY | O_CREAT   /* open/create */
 #define OPENRW  O_RDWR | O_BINARY               /* open read/write */
 
+/*
+ *  get_word
+ *
+ *  Reads in a 2 byte word that is stored in little endian (Intel) notation
+ *  and converts it to the local representation in an architecture-
+ *  independent manner
+ */
+#define get_word(ptr)		\
+	((word)(ptr)[0] |	\
+	 (((word)(ptr)[1]) << 8 ))
 
 /* prototypes */
 
