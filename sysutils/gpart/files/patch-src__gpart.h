--- ./src/gpart.h.orig	2001-01-31 00:07:29.000000000 +0100
+++ ./src/gpart.h	2011-03-17 01:15:54.000000000 +0100
@@ -22,8 +22,9 @@
 
 #define PROGRAM		"gpart"
 
+#include <stdint.h>
 
-typedef unsigned char byte_t;
+typedef uint8_t byte_t;
 
 
 
@@ -31,7 +32,7 @@
  * endianness (incomplete, later)
  */
 
-#if defined(__i386__) || defined(__alpha__)
+#if defined(__i386__) || defined(__amd64__) || defined(__alpha__)
 #	define le16(x)	(x)		/* x as little endian */
 #	define be16(x)	((((x)&0xff00)>>8)			| \
 			(((x)&0x00ff)<<8))
@@ -112,8 +113,8 @@
 	byte_t		p_ehd;		/* end head */
 	byte_t		p_esect;	/* end sector */
 	byte_t		p_ecyl;		/* end cylinder */
-	unsigned long	p_start;	/* start sector (absolute) */
-	unsigned long	p_size;		/* # of sectors */
+	uint32_t	p_start;	/* start sector (absolute) */
+	uint32_t	p_size;		/* # of sectors */
 } dos_part_entry;
 
 
@@ -123,7 +124,7 @@
 	byte_t		_align[2];
 	byte_t		t_boot[DOSPARTOFF];
 	dos_part_entry	t_parts[NDOSPARTS];
-	unsigned short	t_magic;	/* DOSPTMAGIC */
+	uint16_t	t_magic;	/* DOSPTMAGIC */
 } dos_part_table;
 
 
