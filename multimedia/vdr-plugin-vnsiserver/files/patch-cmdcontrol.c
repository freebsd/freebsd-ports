--- a/cmdcontrol.c
+++ b/cmdcontrol.c
@@ -1232,7 +1232,7 @@ bool cCmdControl::processRECORDINGS_Move
           return true;
         }
       }
-      else if ((statret == 0) && (! (dstat.st_mode && S_IFDIR))) // Something exists but it's not a dir
+      else if ((statret == 0) && (! (dstat.st_mode & S_IFDIR))) // Something exists but it's not a dir
       {
         delete[] dateDirName;
         delete[] titleDirName;
