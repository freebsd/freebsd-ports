Add compatibility with libunrar >= 7. Based upon upstream commits:

https://github.com/hasse69/rar2fs/commit/d1d31f416269f4abb1262850b1fe645713a14fc4
https://github.com/hasse69/rar2fs/commit/89d144d17bb23bd2ff143a3aac3593cbfc2dd3c1

--- src/dllext.cpp.orig	2021-05-02 06:17:04 UTC
+++ src/dllext.cpp
@@ -169,13 +169,21 @@ int PASCAL RARListArchiveEx(HANDLE hArcData, RARArchiv
         }
         else
         {
+#if RARVER_MAJOR >= 7
+          wcscpy(N->LinkTargetW,Arc.FileHead.RedirName.c_str());
+#else
           wcscpy(N->LinkTargetW,Arc.FileHead.RedirName);
+#endif
           N->LinkTargetFlags |= LINK_T_UNICODE; // Make sure UNICODE is set
         }
       }
       else if (Arc.FileHead.RedirType == FSREDIR_FILECOPY)
       {
+#if RARVER_MAJOR >= 7
+          wcscpy(N->LinkTargetW,Arc.FileHead.RedirName.c_str());
+#else
           wcscpy(N->LinkTargetW,Arc.FileHead.RedirName);
+#endif
           N->LinkTargetFlags |= LINK_T_FILECOPY;
       }
     }
@@ -208,6 +216,13 @@ void PASCAL RARNextVolumeName(char *arch, bool oldstyl
 {
 #if RARVER_MAJOR < 5
   NextVolumeName(arch, NULL, 0, oldstylevolume);
+#elif RARVER_MAJOR >= 7
+  wstring ArchiveW;
+  size_t len=strlen(arch);
+  ArchiveW.assign(arch,arch+len);
+  NextVolumeName(ArchiveW,oldstylevolume);
+  string NextArchive(ArchiveW.begin(),ArchiveW.end());
+  strcpy(arch,NextArchive.c_str());
 #else
   wchar NextName[NM];
   CharToWide(arch, NextName, ASIZE(NextName));
@@ -221,6 +236,14 @@ void PASCAL RARVolNameToFirstName(char *arch, bool old
 {
 #if RARVER_MAJOR < 5
   VolNameToFirstName(arch, arch, !oldstylevolume);
+#elif RARVER_MAJOR >=7
+  wstring ArcName;
+  size_t len=strlen(arch);
+  ArcName.assign(arch,arch+len);
+  VolNameToFirstName(ArcName, ArcName, !oldstylevolume);
+  string FirstName(ArcName.begin(),ArcName.end());
+  strcpy(arch,FirstName.c_str());
+  return;
 #else
   wchar ArcName[NM];
   CharToWide(arch, ArcName, ASIZE(ArcName));
@@ -239,7 +262,6 @@ void PASCAL RARGetFileInfo(HANDLE hArcData, const char
 void PASCAL RARGetFileInfo(HANDLE hArcData, const char *FileName, struct RARWcb *wcb)
 {
 #if RARVER_MAJOR > 4
-  char FileNameUtf[NM];
   DataSet *Data = (DataSet *)hArcData;
   Archive& Arc = Data->Arc;
   struct RARHeaderDataEx h;
@@ -248,8 +270,17 @@ void PASCAL RARGetFileInfo(HANDLE hArcData, const char
   wcb->bytes = 0;
   while (!RARReadHeaderEx(hArcData, &h))
   {
+#if RARVER_MAJOR >= 7
+    size_t FileNameLen=Arc.FileHead.FileName.size()*sizeof(char32_t);
+    string FileNameUtf(FileNameLen,'\0');
+    WideToUtf(Arc.FileHead.FileName.c_str(),&FileNameUtf[0],FileNameLen);
+    FileNameUtf.resize(strlen(FileNameUtf.c_str()));
+    if (!strcmp(FileNameUtf.c_str(), FileName))
+#else
+    char FileNameUtf[NM];
     WideToUtf(Arc.FileHead.FileName,FileNameUtf,ASIZE(FileNameUtf));
     if (!strcmp(FileNameUtf, FileName))
+#endif
     {
       wcb->bytes = ListFileHeader(wcb->data, Arc);
       return;
@@ -368,7 +399,11 @@ static size_t ListFileHeader(wchar *wcs,Archive &Arc)
 static size_t ListFileHeader(wchar *wcs,Archive &Arc)
 {
   FileHeader &hd=Arc.FileHead;
+#if RARVER_MAJOR >= 7
+  wstring *Name=&hd.FileName;
+#else
   wchar *Name=hd.FileName;
+#endif
   RARFORMAT Format=Arc.Format;
 
   void *wcs_start = (void *)wcs;
@@ -433,25 +468,45 @@ static size_t ListFileHeader(wchar *wcs,Archive &Arc)
   {
     if (Format==RARFMT15)
     {
+#if RARVER_MAJOR >= 7
+      string LinkTargetA;
+#else
       char LinkTargetA[NM];
+#endif
       if (Arc.FileHead.Encrypted)
       {
         // Link data are encrypted. We would need to ask for password
         // and initialize decryption routine to display the link target.
+#if RARVER_MAJOR >= 7
+        LinkTargetA="*<-?->";
+#else
         strncpyz(LinkTargetA,"*<-?->",ASIZE(LinkTargetA));
+#endif
       }
       else
       {
         int DataSize=(int)Min((size_t)hd.PackSize,ASIZE(LinkTargetA)-1);
+#if RARVER_MAJOR >= 7
+        Arc.Read(&LinkTargetA,DataSize);
+#else
         Arc.Read(LinkTargetA,DataSize);
+#endif
         LinkTargetA[DataSize > 0 ? DataSize : 0] = 0;
       }
+#if RARVER_MAJOR >= 7
+      wstring LinkTarget(LinkTargetA.begin(),LinkTargetA.end());
+      wcs += msprintf(wcs, L"\n%12ls: %ls",St(MListTarget),LinkTarget.c_str());
+    }
+    else
+      wcs += msprintf(wcs, L"\n%12ls: %ls",St(MListTarget),hd.RedirName.c_str());
+#else
       wchar LinkTarget[NM];
       CharToWide(LinkTargetA,LinkTarget,ASIZE(LinkTarget));
       wcs += msprintf(wcs, L"\n%12ls: %ls",St(MListTarget),LinkTarget);
     }
     else
       wcs += msprintf(wcs, L"\n%12ls: %ls",St(MListTarget),hd.RedirName);
+#endif
   }
 
   if (!hd.Dir)
@@ -487,11 +542,20 @@ static size_t ListFileHeader(wchar *wcs,Archive &Arc)
       hd.FileHash.CRC32);
   if (hd.FileHash.Type==HASH_BLAKE2)
   {
+#if RARVER_MAJOR >= 7
+    wstring BlakeStr;
+    BinToHex(hd.FileHash.Digest,BLAKE2_DIGEST_SIZE,BlakeStr);
+#else
     wchar BlakeStr[BLAKE2_DIGEST_SIZE*2+1];
     BinToHex(hd.FileHash.Digest,BLAKE2_DIGEST_SIZE,NULL,BlakeStr,ASIZE(BlakeStr));
+#endif
     wcs += msprintf(wcs, L"\n%12ls: %ls",
       hd.UseHashKey ? L"BLAKE2 MAC":hd.SplitAfter ? L"Pack-BLAKE2":L"BLAKE2",
+#if RARVER_MAJOR >= 7
+      BlakeStr.c_str());
+#else
       BlakeStr);
+#endif
   }
 
   const wchar *HostOS=L"";
@@ -529,7 +593,11 @@ static size_t ListFileHeader(wchar *wcs,Archive &Arc)
 
   if (hd.Version)
   {
+#if RARVER_MAJOR >= 7
+    uint Version=ParseVersionFileName(*Name,false);
+#else
     uint Version=ParseVersionFileName(Name,false);
+#endif
     if (Version!=0)
       wcs += msprintf(wcs, L"\n%12ls: %u",St(MListFileVer),Version);
   }
@@ -538,9 +606,17 @@ static size_t ListFileHeader(wchar *wcs,Archive &Arc)
   {
     wcs += msprintf(wcs, L"\n%12ls: ",L"Unix owner");
     if (*hd.UnixOwnerName!=0)
+#if RARVER_MAJOR >= 7
+      wcs += msprintf(wcs, L"%ls:",GetWide(hd.UnixOwnerName).c_str());
+#else
       wcs += msprintf(wcs, L"%ls:",GetWide(hd.UnixOwnerName));
+#endif
     if (*hd.UnixGroupName!=0)
+#if RARVER_MAJOR >= 7
+      wcs += msprintf(wcs, L"%ls",GetWide(hd.UnixGroupName).c_str());
+#else
       wcs += msprintf(wcs, L"%ls",GetWide(hd.UnixGroupName));
+#endif
     if ((*hd.UnixOwnerName!=0 || *hd.UnixGroupName!=0) && (hd.UnixOwnerNumeric || hd.UnixGroupNumeric))
       wcs += msprintf(wcs, L"  ");
     if (hd.UnixOwnerNumeric)
@@ -555,5 +631,3 @@ static size_t ListFileHeader(wchar *wcs,Archive &Arc)
 }
 
 #endif
-
-
