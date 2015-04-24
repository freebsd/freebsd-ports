--- Fast/Stream.xs.orig	2003-06-23 08:57:12 UTC
+++ Fast/Stream.xs
@@ -218,8 +218,7 @@ g_mime_stream_read(mime_stream, buf, len
     	if (SvREADONLY(buf) && PL_curcop != &PL_compiling)
 	    croak("MIME::Fast::Stream->read: buffer parameter is read-only");
 	else
-	if (!SvUPGRADE(buf, SVt_PV))
-	    croak("MIME::Fast::Stream->read: cannot use buf argument as lvalue");
+	SvUPGRADE(buf, SVt_PV);
 	SvPOK_only(buf);
 	SvCUR_set(buf, 0);
 	
