--- src/outbound.cpp.orig  Sun May 21 18:09:12 2000
+++ src/outbound.cpp   Tue May 23 12:43:00 2000
@@ -373,7 +373,7 @@
    fclose (fh);
    unlink(TmtName);
 
-   bfh = open(BsyName,O_CREAT | O_EXCL,0666);
+   bfh = open(BsyName,O_CREAT | O_EXCL,0640);
    if (bfh == -1) {
       return FALSE;
    }
@@ -858,7 +858,7 @@
    }
    fclose (fh);
    unlink(TmtName);
-   bfh = open(Buff,O_CREAT | O_EXCL,0666);
+   bfh = open(Buff,O_CREAT | O_EXCL,0640);
    if (bfh == -1) {
       Log.Level(LOGW) << "Packet " << Name << " is locked." << EOL;
       return TRUE;
