--- src/bbcp_Protocol.C.orig	2015-01-16 11:37:43.000000000 -0800
+++ src/bbcp_Protocol.C	2015-01-16 11:41:33.000000000 -0800
@@ -86,7 +86,7 @@
 
 // Start-up the first node
 //
-   if (retc = Fnode->Run(Ffs->username, Ffs->hostname, Fcmd, Ftype))
+   if ((retc = Fnode->Run(Ffs->username, Ffs->hostname, Fcmd, Ftype)))
       return retc;
 
 // Determine additional options
@@ -101,15 +101,15 @@
 
 // Send the arguments
 //
-   if (retc = SendArgs(Fnode, Ffs, (char *)"none", 0, addOpt[0])) return retc;
+   if ((retc = SendArgs(Fnode, Ffs, (char *)"none", 0, addOpt[0]))) return retc;
 
 // Get the callback port from the first host
 //
-   if (retc = getCBPort(Fnode)) return retc;
+   if ((retc = getCBPort(Fnode))) return retc;
 
 // Start the second node
 //
-   if (retc = Lnode->Run(Lfs->username, Lfs->hostname, Lcmd, Ltype))
+   if ((retc = Lnode->Run(Lfs->username, Lfs->hostname, Lcmd, Ltype)))
       return retc;
 
 // Compute callback hostname and reset callback port
@@ -152,7 +152,7 @@
 
 // The remote program should hve started, get the call back port
 //
-   if (wp = Node->GetLine())
+   if ((wp = Node->GetLine()))
       {if ((wp = Node->GetToken()) && !strcmp(wp, "200")
        &&  (wp = Node->GetToken()) && !strcmp(wp, "Port:")
        &&  (wp = Node->GetToken())
@@ -408,7 +408,7 @@
 
 // Get the optional offset
 //
-   if (wp = Remote->GetToken())
+   if ((wp = Remote->GetToken()))
       {if (bbcp_Config.a2ll("file offset", wp, foffset, 0, -1)) return 22;
        if (foffset > fp->Info.size)
           {char buff[128];
@@ -447,7 +447,7 @@
 // Get the first line of the login stream
 //
    if (!(np->GetLine()))
-      {if (retc = np->LastError())
+      {if ((retc = np->LastError()))
           return bbcp_Emsg("Process_Login", retc, "processing login from",
                                  Net->LinkName());
        return bbcp_Fmsg("Process_Login", "Bad login from", Net->LinkName());
@@ -549,8 +549,8 @@
    if (texists && bbcp_Config.snkSpec->Info.Otype == 'd')
        tdir = bbcp_Config.snkSpec->pathname;
       else {int plen;
-            if (plen = bbcp_Config.snkSpec->filename -
-                       bbcp_Config.snkSpec->pathname)
+            if ((plen = bbcp_Config.snkSpec->filename -
+                       bbcp_Config.snkSpec->pathname))
                strncpy(buff, bbcp_Config.snkSpec->pathname, plen-1);
                else {buff[0] = '.'; plen = 2;}
             tdir = buff; buff[plen-1] = '\0';
@@ -562,7 +562,7 @@
       tdir_id = bbcp_Config.snkSpec->Info.fileid;
       else {bbcp_FileInfo Tinfo;
             if (!fs_obj || (!(retc = fs_obj->Stat(tdir, &Tinfo))
-            && Tinfo.Otype != 'd') && outDir) retc = ENOTDIR;
+            && (Tinfo.Otype != 'd') && outDir)) retc = ENOTDIR;
             if (retc) {bbcp_Fmsg("Request","Target directory",
                                  bbcp_Config.snkSpec->pathname,"not found");
                        return Request_exit(2, dRM);
