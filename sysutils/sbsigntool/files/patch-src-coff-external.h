--- src/coff/external.h.orig	2014-11-30 17:11:35.000000000 +0100
+++ src/coff/external.h	2014-11-30 17:12:19.000000000 +0100
@@ -51,7 +51,7 @@ typedef struct external_aouthdr
     char entry[4];	/* entry pt.				*/
     char text_start[4];	/* base of text used for this file 	*/
     char data_start[4];	/* base of data used for this file 	*/
-  } ATTRIBUTE_PACKED
+  } __attribute__((packed))
 AOUTHDR;
 
 #define AOUTHDRSZ 28
@@ -165,7 +165,7 @@ struct external_syment 
   char e_type[2];
   char e_sclass[1];
   char e_numaux[1];
-} ATTRIBUTE_PACKED ;
+} __attribute__((packed));
 
 #define	SYMENT	struct external_syment
 #define	SYMESZ	18	
@@ -257,7 +257,7 @@ union external_auxent
     char x_tvlen[2];	/* length of .tv */
     char x_tvran[2][2];	/* tv range */
   } x_tv;		/* info about .tv section (in auxent of symbol .tv)) */
-} ATTRIBUTE_PACKED ;
+} __attribute__((packed));
 
 #define	AUXENT	union external_auxent
 #define	AUXESZ	18
