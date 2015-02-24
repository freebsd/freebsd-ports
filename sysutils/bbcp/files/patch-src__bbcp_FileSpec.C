--- src/bbcp_FileSpec.C.orig	2015-01-16 14:34:11.000000000 -0800
+++ src/bbcp_FileSpec.C	2015-01-16 14:36:54.000000000 -0800
@@ -174,7 +174,7 @@
 
 // Get the current state of the file or directory
 //
-        if (retc = FSp->Stat(targpath, &Targ)) targetsz = 0;
+        if ((retc = FSp->Stat(targpath, &Targ))) targetsz = 0;
    else if (Targ.Otype == 'p' && (bbcp_Config.Options & bbcp_XPIPE))
                                {targetsz =  0; return 0;}
    else if (Targ.Otype != 'f') {targetsz = -1; return 0;}
@@ -211,7 +211,7 @@
 // in the directory. This will later be set to the true mode if it differs.
 //
    DEBUG("Make link " <<targpath <<" -> " <<Info.SLink);
-   if (retc = FSp->MKLnk(Info.SLink, targpath))
+   if ((retc = FSp->MKLnk(Info.SLink, targpath)))
       return bbcp_Emsg("Create_Link", retc, "creating link", targpath);
 
 // All done
@@ -232,7 +232,7 @@
 // in the directory. This will later be set to the true mode if it differs.
 //
    DEBUG("Make path " <<Info.mode <<' ' <<targpath);
-   if (retc = FSp->MKDir(targpath, bbcp_Config.ModeDC))
+   if ((retc = FSp->MKDir(targpath, bbcp_Config.ModeDC)))
       if (retc == -EEXIST) return 0;
          else return bbcp_Emsg("Create_Path", retc, "creating path", targpath);
 
@@ -764,7 +764,7 @@
                         else bbcp_Config.srcPath = PS_New;
              PS_Prv = PS_New; PS_Cur = PS_New->next;
             }
-         if (*cp = delim) cp++;
+         if ((*cp = delim)) cp++;
         }
 }
 
