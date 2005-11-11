--- lsdvd.c.orig	Wed Apr 13 23:34:34 2005
+++ lsdvd.c	Fri Nov 11 11:41:05 2005
@@ -124,19 +124,26 @@
 		return -1;
 	}
 
-	if ( fseek(filehandle, 32808, SEEK_SET )) {
+	if ( fseek(filehandle, 32768, SEEK_SET )) {
 		fclose(filehandle);
 		fprintf(stderr, "Couldn't seek in %s for title\n", dvd_device);
 		strcpy(title, "unknown");
 		return -1;
 	}
 
-	if ( 32 != (i = fread(title, 1, 32, filehandle)) ) {
+	{
+	#define DVD_SEC_SIZ 2048
+	char tempBuf[ DVD_SEC_SIZ ];
+
+	if ( DVD_SEC_SIZ != fread(tempBuf, 1, DVD_SEC_SIZ, filehandle) ) {
 		fclose(filehandle);
 		fprintf(stderr, "Couldn't read enough bytes for title.\n");
 		strcpy(title, "unknown");
 		return -1;
 	}
+	snprintf( title, 32, "%s", tempBuf + 40 );
+	i=32;
+	}
 
 	fclose (filehandle);
 
@@ -193,6 +200,7 @@
 	int has_title = 0, ret = 0;
 	int max_length = 0, max_track = 0;
 	struct stat dvd_stat;
+	struct dvd_info dvd_info;
 
 	program_name = argv[0];
 
@@ -263,8 +271,6 @@
 
 	vmgi_mat = ifo_zero->vmgi_mat;
 
-	struct dvd_info dvd_info;
-		
 	dvd_info.discinfo.device = dvd_device;
 	dvd_info.discinfo.disc_title = has_title ? "unknown" : title;
 	dvd_info.discinfo.vmg_id =  vmgi_mat->vmg_identifier;
@@ -363,14 +369,16 @@
 
 		cell = 0;
 		if (opt_c) {
+			int ms;
+
 			dvd_info.titles[j].chapter_count = pgc->nr_of_programs;
 			dvd_info.titles[j].chapters = calloc(dvd_info.titles[j].chapter_count, sizeof(*dvd_info.titles[j].chapters));
 
-						int ms;
 			for (i=0; i<pgc->nr_of_programs; i++)
 			{	   
+				int next;
 				ms=0;
-				int next = pgc->program_map[i+1];   
+				next = pgc->program_map[i+1];   
 				if (i == pgc->nr_of_programs - 1) next = pgc->nr_of_cells + 1;
 
 				while (cell < next - 1)
