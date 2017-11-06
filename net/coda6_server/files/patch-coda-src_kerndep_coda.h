--- coda-src/kerndep/coda.h.orig	2007-08-01 18:32:36 UTC
+++ coda-src/kerndep/coda.h
@@ -184,13 +184,29 @@ struct venus_dirent {
 
 #ifndef _VENUS_DIRENT_T_
 #define _VENUS_DIRENT_T_ 1
+#if defined(__FreeBSD__)
+#include <sys/param.h>
+#endif
+#if defined(__FreeBSD__) && (__FreeBSD_version >= 1200031)
 struct venus_dirent {
+	ino_t		d_fileno;		/* file number of entry */
+	off_t		d_off;			/* directory offset of entry */
+	uint16_t	d_reclen;		/* length of this record */
+	uint8_t		d_type;			/* file type, see below */
+	uint8_t		d_pad0;
+	uint16_t	d_namlen;		/* length of string in d_name */
+	uint16_t	d_pad1;
+	char		d_name[255 + 1];	/* name must be no longer than this */
+};
+#else
+struct venus_dirent {
         unsigned int	d_fileno;		/* file number of entry */
         unsigned short	d_reclen;		/* length of this record */
         unsigned char 	d_type;			/* file type, see below */
         unsigned char	d_namlen;		/* length of string in d_name */
         char		d_name[CODA_MAXNAMLEN + 1];/* name must be no longer than this */
 };
+#endif
 #undef DIRSIZ
 #define DIRSIZ(dp)      ((sizeof (struct venus_dirent) - (CODA_MAXNAMLEN+1)) + \
                          (((dp)->d_namlen+1 + 3) &~ 3))
