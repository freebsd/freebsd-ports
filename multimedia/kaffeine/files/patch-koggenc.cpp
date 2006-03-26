--- kaffeine/src/input/disc/plugins/oggvorbis/koggenc.cpp.orig	Sun Mar 26 15:12:09 2006
+++ kaffeine/src/input/disc/plugins/oggvorbis/koggenc.cpp	Sun Mar 26 15:12:37 2006
@@ -159,7 +159,7 @@
 	while( ogg_stream_flush( &os, &og ) ){
 		delete [] bufEncode;
 		bufEncode = new char[ og.header_len+og.body_len+buflen ];
-		memcpy( mempcpy( mempcpy( bufEncode, tmpBuf, buflen ), og.header, og.header_len ), og.body, og.body_len );
+		memcpy( (char *)memcpy( (char *)memcpy( bufEncode, tmpBuf, buflen ) + buflen, og.header, og.header_len ) + og.header_len, og.body, og.body_len );
 		buflen+= og.header_len;
 		buflen+= og.body_len;
 		delete [] tmpBuf;
@@ -192,7 +192,7 @@
 			while( ogg_stream_pageout( &os, &og ) ) {
 				delete [] bufEncode;
 				bufEncode = new char[ og.header_len+og.body_len+buflen ];
-				memcpy( mempcpy( mempcpy( bufEncode, tmpBuf, buflen ), og.header, og.header_len ), og.body, og.body_len );
+				memcpy( (char *)memcpy( (char *)memcpy( bufEncode, tmpBuf, buflen ) + buflen, og.header, og.header_len ) + og.header_len, og.body, og.body_len );
 				buflen+= og.header_len;
 				buflen+= og.body_len;
 				delete [] tmpBuf;
@@ -220,7 +220,7 @@
 			while( ogg_stream_pageout( &os, &og ) ) {
 				delete [] bufEncode;
 				bufEncode = new char[ og.header_len+og.body_len+buflen ];
-				memcpy( mempcpy( mempcpy( bufEncode, tmpBuf, buflen ), og.header, og.header_len ), og.body, og.body_len );
+				memcpy( (char *)memcpy( (char *)memcpy( bufEncode, tmpBuf, buflen ) + buflen, og.header, og.header_len ) + og.header_len, og.body, og.body_len );
 				buflen+= og.header_len;
 				buflen+= og.body_len;
 				delete [] tmpBuf;
