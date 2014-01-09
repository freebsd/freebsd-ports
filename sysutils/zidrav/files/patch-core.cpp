--- core.cpp.orig	2005-05-21 22:16:50.000000000 +0200
+++ core.cpp	2014-01-07 06:41:30.000000000 +0100
@@ -38,7 +38,7 @@
 
 void be_write32le(iostream &output, char *buf)
 {
-	int data;
+	int data = 0;
 	data = *(int*)buf;
 
 	data = SwapBO32(data);
@@ -48,7 +48,7 @@
 
 void be_read32le(istream &input, char *buf)
 {
-	int data;
+	int data = 0;
 	input.read((char *)&data, 4);
 
 	data = SwapBO32(data);
@@ -59,7 +59,7 @@
 
 	char	*buffer;
 	int		i;
-	long	crc;
+	crc32_type	crc;
     short   oldprc = 0;
     
 	output.write( ZC, 8 );
@@ -105,11 +105,11 @@
 
 void MakePatchCore( istream &cdti, istream &vstr, iostream &output, int cdtlen, int vstrlen, int * efound) {
 
-	long filesize;
-	long blocksize;
+	long filesize = 0; // reset all 64bit
+	long blocksize = 0; // reset all 64bit
 
-	long crc;
-	long cdtcrc;
+	crc32_type crc;
+	crc32_type cdtcrc = 0; // reset all 64bit
 
 	long curbs;
 
@@ -207,12 +207,12 @@
 
 void ApplyPatchCore( istream &cdpi, iostream &pstr, int cdplen, int pstrlen) {
 
-	long filesize;
-	long blocksize;
+	long filesize = 0; // reset all 64bit
+	long blocksize = 0; // reset all 64bit
 
 	long curbs = 0;
 
-	long offset;
+	long offset = 0; // reset all 64bit
 
 	char *buffer = NULL;
 
@@ -266,7 +266,8 @@
 
 	char minibuff[9];
 
-	long crc;
+	crc32_type crc;
+	crc32_type filecrc = 0; // reset all 64bit
 
 	buffer = new char[10];
 
@@ -317,12 +318,12 @@
     }
 
 	input.seekg( 0 );						// go to the beginning
-	input.read( buffer, datalen );		// and pull it all
+	input.read( buffer, datalen - 4 );		// and pull it all
+        read32le(input, (char *)&filecrc);
 
 	CreateChecksum( buffer, datalen - 4, &crc );
 
-	if( crc != int32tole(*(int *)&buffer[ datalen - 4 ]) ) {
-		delete [] buffer;
+	if( crc != filecrc ) {
         switch(emsg)
         {
             case IDS_UPT_INVCDT:
@@ -342,7 +343,7 @@
 void MakeOverallChecksum( iostream &st, long size ) {
 
 	char *buffer;
-	long crc;
+	crc32_type crc;
 
     // FIXME: trying to load whole file... again... :(
 	buffer = new char[size];
@@ -367,7 +368,7 @@
 #define DO8( buffer )  DO4( buffer ); DO4( buffer );
 #define DO16( buffer )  DO8( buffer ); DO8( buffer );
 
-void CreateChecksum( char *buffer, long size, long *crc ) {
+void CreateChecksum( char *buffer, long size, crc32_type *crc ) {
 
 	*crc = 0;
 
