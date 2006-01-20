--- lxdvdrip.c.orig	Wed Dec 28 14:17:02 2005
+++ lxdvdrip.c	Fri Jan 20 00:53:53 2006
@@ -775,6 +775,9 @@
   FILE *filehandle = 0;
   int i;
 
+#define	DVD_SEC_SIZ	2048
+  char	tempBuf[DVD_SEC_SIZ];
+
   if (!(filehandle = fopen (dvd_device, "r")))
     {
       switch (lSprache)
@@ -794,7 +797,7 @@
       return -1;
     }
 
-  if (fseek (filehandle, 32808, SEEK_SET))
+  if (fseek (filehandle, 32768, SEEK_SET))
     {
       fclose (filehandle);
       switch (lSprache)
@@ -814,7 +817,7 @@
       return -1;
     }
 
-  if (32 != (i = fread (title, 1, 32, filehandle)))
+  if (DVD_SEC_SIZ != fread (tempBuf, 1, DVD_SEC_SIZ, filehandle))
     {
       fclose (filehandle);
       switch (lSprache)
@@ -832,7 +835,8 @@
       strcpy (title, "unknown");
       return -1;
     }
-
+  snprintf( title, 32, "%s", tempBuf + 40 );
+  i=32;
   fclose (filehandle);
 
   title[32] = '\0';
@@ -6228,7 +6232,7 @@
 	      if (strstr (buffer_name, "mbuffer"))
 		sprintf (szBufferBefehl, "%s -s 64k -q -i", buffer_name);	// nehme mbuffer
 	      else
-		sprintf (szBufferBefehl, "%s -s 64k -m 16m -i", buffer_name);	// nehme buffer
+		sprintf (szBufferBefehl, "%s -s 64k -m 10m -i", buffer_name);	// nehme buffer
 	    }
 	  // Behandlung von Forced Subtitles
 	  printf ("Wert Untertitel: %ld\n", lUntertitel);
@@ -7924,7 +7928,7 @@
 	    strcat (szFilmVerzeichnis, "/");
 	  strcat (szFilmVerzeichnis, szDVDName);
 	  // Verzeichnis AUDIO_TS anlegen
-	  sprintf (szBefehl, "mkdir %s/AUDIO_TS -m 0777", szFilmVerzeichnis);
+	  sprintf (szBefehl, "mkdir -m 0777 %s/AUDIO_TS", szFilmVerzeichnis);
 	  printf ("%s\n", szBefehl);
 	  system (szBefehl);
 	}
@@ -9401,7 +9405,7 @@
 		strcpy (szDVDCompat, "");
 	      check_program (growisofs_name, lSprache, 1);
 	      // Growisofs
-	      sprintf (szBefehl, "%s %s %s %s -Z %s -V %s %s -dvd-video %s",
+	      sprintf (szBefehl, "%s %s %s %s -use-the-force-luke=dao -Z %s -V %s %s -dvd-video %s",
 		       growisofs_name, szBurnParam, szSpeed, szDVDCompat,
 		       szDVDBrenner, szDVDNameOverwrite, szMkisofsParam,
 		       szFilmVerzeichnis);
