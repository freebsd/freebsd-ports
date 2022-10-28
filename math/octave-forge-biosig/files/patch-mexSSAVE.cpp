--- mexSSAVE.cpp.orig	2022-10-28 21:23:00 UTC
+++ mexSSAVE.cpp
@@ -202,7 +202,7 @@ void mexFunction(
 	if ( (p = mxGetField(prhs[0], 0, "tzmin") ) != NULL )
 		hdr->tzmin 	= (int16_t)getDouble(p, 0);
 	else
-		hdr->tzmin	= -timezone/60;
+		hdr->tzmin	= -localtime(0)->tm_gmtoff/60;
 	if ( (p = mxGetField(prhs[0], 0, "FileName") ) != NULL ) 	FileName 	= mxArrayToString(p);
 	if ( (p = mxGetField(prhs[0], 0, "SampleRate") ) != NULL ) 	hdr->SampleRate = getDouble(p, 0);
 	if ( (p = mxGetField(prhs[0], 0, "NS") ) != NULL )	 	hdr->NS         = getDouble(p, 0);
