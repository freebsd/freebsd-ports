--- quicktime/libdv/parse.c.orig	Mon Feb 12 22:35:41 2001
+++ quicktime/libdv/parse.c	Mon Nov  1 19:40:00 2004
@@ -376,8 +376,10 @@
 	    vlc_trace("%s", (bitstream_get(bs,1)) ? "1" : "0");
 	} else { vlc_trace("\n\tno unused bits"); }
 #endif // PARSE_VLC_TRACE
+	;
       } // for b 
-  mb_done: 
+  mb_done:
+      ; 
     } // for m 
     vlc_trace("\n");
   } // for pass 
