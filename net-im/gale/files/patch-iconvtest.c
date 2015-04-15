--- iconvtest.c.orig	2000-11-18 06:38:47 UTC
+++ iconvtest.c
@@ -27,7 +27,7 @@ int main() {
     ||  utf[0] != 0x7f 
     ||  utf[1] != 0xdf || utf[2] != 0xbf
     ||  utf[3] != 0xef || utf[4] != 0xbf || utf[5] != 0xbf) exit(1);
-    inbuf = utf; inbytes = 6;
+    inbuf = (char *) utf; inbytes = 6;
     outbuf = (char *) wch; outbytes = sizeof(wch);
     if (0 != iconv(from,&inbuf,&inbytes,&outbuf,&outbytes)
     ||  0 != inbytes || (sizeof(wch) - 3*sizeof(wchar_t)) != outbytes
