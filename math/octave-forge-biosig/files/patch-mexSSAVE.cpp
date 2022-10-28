--- mexSSAVE.cpp.orig	2021-07-14 20:07:43 UTC
+++ mexSSAVE.cpp
@@ -87,6 +87,7 @@ void mexFunction(
 	HDRTYPE		*hdr;
 	size_t 		count;
 	time_t 		T0;
+	time_t		zero = 0;
 	char 		*FileName;  
 	char 		tmpstr[128];  
 	int 		status; 
@@ -202,7 +203,7 @@ void mexFunction(
 	if ( (p = mxGetField(prhs[0], 0, "tzmin") ) != NULL )
 		hdr->tzmin 	= (int16_t)getDouble(p, 0);
 	else
-		hdr->tzmin	= -timezone/60;
+		hdr->tzmin	= -localtime(&zero)->tm_gmtoff/60;
 	if ( (p = mxGetField(prhs[0], 0, "FileName") ) != NULL ) 	FileName 	= mxArrayToString(p);
 	if ( (p = mxGetField(prhs[0], 0, "SampleRate") ) != NULL ) 	hdr->SampleRate = getDouble(p, 0);
 	if ( (p = mxGetField(prhs[0], 0, "NS") ) != NULL )	 	hdr->NS         = getDouble(p, 0);
