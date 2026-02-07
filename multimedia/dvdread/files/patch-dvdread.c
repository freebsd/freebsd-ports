--- dvdread.c.orig	2016-07-01 16:06:13 UTC
+++ dvdread.c
@@ -203,7 +203,7 @@ int main(int argc, char *argv[]) {
                     || file[curfile].type == vts_vob)
                 && curfile != lastfile) {
             st = "seek key";
-            r = dvdcss_seek(dvdcss, s, DVDCSS_SEEK_KEY);
+            r = dvdcss_seek(dvdcss, s, DVDCSS_SEEK_MPEG);
         } else {
             st = "seek";
             r = dvdcss_seek(dvdcss, s, DVDCSS_NOFLAGS);
