--- src/core/unix/file_unix.cpp	Sat Oct 28 04:15:21 2000
+++ src/core/unix/file_unix.cpp	Wed Jun 13 09:29:07 2001
@@ -155,10 +155,15 @@
 	if( flags & OPEN_CREATE )
 		perm |= O_CREAT;
 
+	mode_t openmode = 0664;
+	if ( flags & OPEN_EXCLUSIVE ) {
+		perm |= O_CREAT | O_EXCL;
+		openmode = (mode_t) 0600; // Make sure only root can read the file
+	}
 	//
 	// actually open the file
 	//
-	int fh = _topen( sFileName.c_str(), perm, 0664 );
+	int fh = _topen( sFileName.c_str(), perm, openmode );
 	if( fh == -1 )
 	{
 		throw( eFileOpen( sFileName, iFSServices::GetInstance()->GetErrString() ) );
--- src/core/file.h	Sat Oct 28 04:15:20 2000
+++ src/core/file.h	Wed Jun 13 09:07:20 2001
@@ -96,7 +96,8 @@
 		OPEN_LOCKED_TEMP	= 0x00000004,	// the file should not be readable by other processes and should be removed when closed
 		OPEN_TRUNCATE		= 0x00000008,	// opens an empty file. creates it if it doesn't exist. Doesn't make much sense without OF_WRITE
 		OPEN_CREATE			= 0x00000010,	// create the file if it doesn't exist; this is implicit if OF_TRUNCATE is set
-		OPEN_TEXT			= 0x00000020
+		OPEN_TEXT			= 0x00000020,
+		OPEN_EXCLUSIVE = 0x0000040 // Use O_CREAT | O_EXCL
 	};
 
 	//Ctor, Dtor, CpyCtor, Operator=:
--- src/core/archive.cpp	Sat Feb 24 21:02:12 2001
+++ src/core/archive.cpp	Wed Jun 13 09:15:25 2001
@@ -896,8 +896,9 @@
     // create file
 
     // set up flags
-    uint32 flags = cFile::OPEN_WRITE | cFile::OPEN_LOCKED_TEMP | cFile::OPEN_CREATE;
-    if ( openFlags & FA_OPEN_TRUNCATE ) 
+    uint32 flags = cFile::OPEN_WRITE | cFile::OPEN_LOCKED_TEMP | cFile::OPEN_CREATE | cFile::OPEN_EXCLUSIVE;
+
+    if ( openFlags & FA_OPEN_TRUNCATE )
       flags |= cFile::OPEN_TRUNCATE;
     if ( openFlags & FA_OPEN_TEXT ) 
       flags |= cFile::OPEN_TEXT;
