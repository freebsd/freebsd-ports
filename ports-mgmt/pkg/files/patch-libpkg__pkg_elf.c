--- ./libpkg/pkg_elf.c.orig	2013-05-16 23:38:38.020628709 -0500
+++ ./libpkg/pkg_elf.c	2013-05-16 23:57:33.346627390 -0500
@@ -258,7 +258,10 @@
 	}
 
 	if (note != NULL) {
-		data = elf_getdata(note, NULL);
+		if ((data = elf_getdata(note, NULL)) == NULL) {
+			ret = EPKG_END; /* Some error occurred, ignore this file */
+			goto cleanup;
+		}
 		osname = (const char *) data->d_buf + sizeof(Elf_Note);
 		if (strncasecmp(osname, "freebsd", sizeof("freebsd")) != 0 &&
 		    strncasecmp(osname, "dragonfly", sizeof("dragonfly")) != 0) {
@@ -272,7 +275,10 @@
 		}
 	}
 
-	data = elf_getdata(dynamic, NULL);
+	if ((data = elf_getdata(dynamic, NULL)) == NULL) {
+		ret = EPKG_END; /* Some error occurred, ignore this file */
+		goto cleanup;
+	}
 
 	/* First, scan through the data from the .dynamic section to
 	   find any RPATH or RUNPATH settings.  These are colon
