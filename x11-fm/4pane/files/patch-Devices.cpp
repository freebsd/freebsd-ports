--- Devices.cpp.orig	2020-11-22 11:42:51 UTC
+++ Devices.cpp
@@ -1357,7 +1357,7 @@ if (!wxFileExists(BLKID))
     if (wxFileExists(wxT("/usr/bin/blkid"))) BLKID = wxT("/usr/bin/blkid");
      else
       { wxArrayString output, errors;long ans;
-        if (wxGetOsDescription().Contains(wxT("kFreeBSD"))) // The kFreeBSD forkpty hangs
+        if (wxGetOsDescription().Contains(wxT("FreeBSD"))) // FreeBSD's forkpty() hangs
           ans = wxExecute(wxT("which blkid"), output, errors);
          else
           ans = ExecuteInPty(wxT("which blkid"), output, errors);
@@ -1371,7 +1371,7 @@ if (!wxFileExists(LSBLK))
     if (wxFileExists(wxT("/sbin/lsblk"))) LSBLK = wxT("/sbin/lsblk");
      else
       { wxArrayString output, errors; long ans;
-        if (wxGetOsDescription().Contains(wxT("kFreeBSD")))
+        if (wxGetOsDescription().Contains(wxT("FreeBSD")))
           ans = wxExecute(wxT("which lsblk"), output, errors);
          else
           ans = ExecuteInPty(wxT("which lsblk"), output, errors);
@@ -1590,14 +1590,22 @@ bool DeviceAndMountManager::Checkmtab(wxString& mountp
   return DeviceAndMountManager::GnuCheckmtab(mountpoint, device);
 #endif
 
+#ifdef __linux__
 struct mntent* mnt = NULL;
 
 FILE* fmp = setmntent (_PATH_MOUNTED, "r");                // Get a file* to (probably) /etc/mtab
 if (fmp==NULL) return false;
+#else
+struct statfs* fslist;
 
+int numfs = getmntinfo(&fslist, MNT_NOWAIT);
+if (numfs < 1) return false;
+#endif
+
 wxString mountpt(mountpoint); FileData mp(mountpt);
 if (mp.IsSymlink()) mountpt = mp.GetUltimateDestination(); // Cope with a symlink
 
+#ifdef __linux__
 while (1)                                                  // For every mtab entry
   { mnt = getmntent(fmp);                                  // Get a struct representing a mounted partition
     if (mnt == NULL)
@@ -1605,14 +1613,24 @@ while (1)                                             
 
     wxString mntdir(mnt->mnt_dir, wxConvUTF8);
     wxString type(mnt->mnt_type, wxConvUTF8); type.MakeLower();
+#else
+for (int i = 0; i < numfs; ++i)
+  { wxString mntdir(fslist[i].f_mntonname, wxConvUTF8);
+    wxString type(fslist[i].f_fstypename, wxConvUTF8); type.MakeLower();
+#endif
     // Don't try to create a FileData if we're testing a network mount. It's less likely to be symlinked, and e.g. a stale nfs mount hangs lstat!
     if (!type.StartsWith(wxT("nfs")) && !type.Contains(wxT("sshfs")) && type != wxT("cifs") && type != wxT("smbfs"))
       { FileData mt(mntdir); if (mt.IsSymlink()) mntdir = mt.GetUltimateDestination(); } // Cope with a symlink
     if (mntdir == mountpt)                                 // This is the one we're looking for
+#ifdef __linux__
       { endmntent(fmp);
         if (device.IsEmpty()) return true;                 // If we don't care which device is mounted there
 
         wxString mntfsname(mnt->mnt_fsname, wxConvUTF8);   // in case we DO care
+#else
+      { if (device.IsEmpty()) return true;
+        wxString mntfsname(fslist[i].f_mntfromname, wxConvUTF8);
+#endif
         FileData dev(device); FileData mntfs(mntfsname);   // Cope with any symlinks
         if (dev.IsSymlink()) device = dev.GetUltimateDestination();
         if (mntfs.IsSymlink()) mntfsname = mntfs.GetUltimateDestination();
@@ -1649,6 +1667,7 @@ wxString DeviceAndMountManager::WhereIsDeviceMounted(w
 
 wxString DeviceAndMountManager::WhereIsDeviceMounted(wxString device, size_t type)
 {
+#ifdef __linux__
 struct mntent* mnt = NULL;
 
 FILE* fmp = setmntent (_PATH_MOUNTED, "r");             // Get a file* to (probably) /etc/mtab
@@ -1660,6 +1679,17 @@ while (1)                                             
     wxString mntfsname(mnt->mnt_fsname, wxConvUTF8);
     if (mntfsname == device)
       { endmntent(fmp); return wxString(mnt->mnt_dir, wxConvUTF8); }  // If it's the one we're looking for, return the associated mountpt
+#else
+struct statfs* fslist;
+
+int numfs = getmntinfo(&fslist, MNT_NOWAIT);
+if (numfs < 1) return wxEmptyString;
+
+for (int i = 0; i < numfs; ++i)
+  { wxString mntfsname(fslist[i].f_mntfromname, wxConvUTF8);
+    if (mntfsname == device)
+      return wxString(fslist[i].f_mntonname, wxConvUTF8);
+#endif
   }
 
             // If we're here, the device wasn't found.  See if it's actually a symlink for a different device  eg /dev/dvd -> /dev/hdc.  If so, try that
@@ -1678,17 +1708,27 @@ return wxEmptyString;                                 
 }
 
 //static
+#ifdef __linux__
 struct mntent* DeviceAndMountManager::ReadMtab(const wxString& partition, bool DvdRamFS /*=false*/)    // Is 'partition' currently mounted? Returns struct of data if it is, NULL if it isn't
 {
 struct mntent* mnt = NULL;
 
 FILE* fmp = setmntent (_PATH_MOUNTED, "r");           // Get a file* to (probably) /etc/mtab
 if (fmp==NULL) return mnt;
+#else
+struct statfs* DeviceAndMountManager::ReadMtab(const wxString& partition, bool DvdRamFS /*=false*/)
+{
+struct statfs* fslist;
 
+int numfs = getmntinfo(&fslist, MNT_NOWAIT);
+if (numfs < 1) return NULL;
+#endif
+
 wxString partitionwithsep(partition),  partitionwithout(partition); // Avoid the usual '/' issue
 if (partition.Right(1) == wxFILE_SEP_PATH) partitionwithout = partition.BeforeLast(wxFILE_SEP_PATH);
  else partitionwithsep << wxFILE_SEP_PATH;
 
+#ifdef __linux__
 while (1)                                             // For every mtab entry
   { mnt = getmntent(fmp);                             // Get a struct representing a mounted partition
     if (mnt == NULL)  break;                          // If it's null, we've run out of candidates.  Return null as flag
@@ -1706,6 +1746,22 @@ mnt = NULL; return mnt;                               
 if (stat.IsSymlink())   { wxString target = stat.GetSymlinkDestination(); return ReadMtab(target, DvdRamFS); }
 
 mnt = NULL; return mnt;                               // If we're here, it failed. Return null as flag
+#else
+for (int i = 0; i < numfs; ++i)
+  { wxString mntfsname(fslist[i].f_mntfromname, wxConvUTF8);
+    if (!mntfsname.empty() && ((mntfsname == partitionwithsep) || (mntfsname == partitionwithout)))
+      { if (!DvdRamFS) return &fslist[i];
+        wxString mnttype(fslist[i].f_fstypename, wxConvUTF8);
+        for (size_t n=0; n < RealFilesystemsArray.GetCount(); ++n)
+          if (mnttype.Left(3) == RealFilesystemsArray.Item(n).Left(3)) return &fslist[i];
+      }
+  }
+FileData stat(partition);
+if (stat.IsSymlink())
+  { wxString target = stat.GetSymlinkDestination();
+    return ReadMtab(target, DvdRamFS);
+  } else return NULL;
+#endif
 }
 
 
@@ -1887,14 +1943,25 @@ if (!FillPartitionArrayUsingLsblk(true))              
           { pstruct->mountpt = wxString(fs->fs_file, wxConvUTF8); // Store the mountpt
             pstruct->IsMounted = Checkmtab(pstruct->mountpt, pstruct->device);// & whether it's mounted.  Pass the device-name too, so that we only record if the mountpt contains THIS device
             if (!pstruct->IsMounted)                            // If it isn't mounted where it's supposed to be, look elsewhere in case it was su-mounted in the 'wrong' place
+#ifdef __linux__
               { struct mntent* mnt = ReadMtab(pstruct->device);
                 if (mnt != NULL) { pstruct->mountpt = wxString(mnt->mnt_dir, wxConvUTF8); pstruct->IsMounted = true; }
+#else
+              { struct statfs* mnt = ReadMtab(pstruct->device);
+                if (mnt != NULL) { pstruct->mountpt = wxString(mnt->f_mntonname, wxConvUTF8); pstruct->IsMounted = true; }
+#endif
               }
           }
          else                                                   // If we didn't find it in fstab, check mtab anyway, in case someone mounted it the hard way
+#ifdef __linux__
           { struct mntent* mnt = ReadMtab(pstruct->device);
             if (mnt != NULL)
               { pstruct->mountpt = wxString(mnt->mnt_dir, wxConvUTF8);  // Store the mountpt
+#else
+          { struct statfs* mnt = ReadMtab(pstruct->device);
+            if (mnt != NULL)
+              { pstruct->mountpt = wxString(mnt->f_mntonname, wxConvUTF8);
+#endif
                 pstruct->IsMounted = true;                      // It's mounted by definition:  it's in mtab
               }
              else pstruct->IsMounted = false;                   // Otherwise reset this bool, as it's otherwise undefined
@@ -2027,6 +2094,7 @@ void DeviceAndMountManager::FindMountedImages()  // Ad
 
 void DeviceAndMountManager::FindMountedImages()  // Add mounted iso-images from mtab to array
 {
+#ifdef __linux__
 FILE* fmp = setmntent (_PATH_MOUNTED, "r");                 // Get a file* to (probably) /etc/mtab
 if (fmp==NULL) return;
 
@@ -2036,12 +2104,26 @@ while (1)                                             
       { endmntent(fmp);  return; }                          // If it's null, we've finished mtab
     
     wxString device(mnt->mnt_fsname, wxConvUTF8);           // Make the 'device' into a wxString for convenience
+#else
+struct statfs* fslist;
+
+int numfs = getmntinfo(&fslist, MNT_NOWAIT);
+if (numfs < 1) return;
+
+for (int i = 0; i < numfs; ++i)
+  { wxString device(fslist[i].f_mntfromname, wxConvUTF8);
+#endif
     // If it starts with a '/dev/loop' or with a '/' but not with /dev/ or //  it's probably an iso-image
     if ((device.Left(9) == wxT("/dev/loop")) || (device.GetChar(0) == wxT('/') && 
                             !(device.Left(5) == wxT("/dev/") || device.Left(2) == wxT("//"))))
       { struct PartitionStruct* newmnt = new struct PartitionStruct;  // store in structarray
+#ifdef __linux__
         newmnt->device = wxString(mnt->mnt_fsname, wxConvUTF8);
         newmnt->mountpt = wxString(mnt->mnt_dir, wxConvUTF8);
+#else
+        newmnt->device = wxString(fslist[i].f_mntfromname, wxConvUTF8);
+        newmnt->mountpt = wxString(fslist[i].f_mntonname, wxConvUTF8);
+#endif
         newmnt->IsMounted = true;                           // By definition
         PartitionArray->Add(newmnt);                      
       }
@@ -2153,6 +2235,7 @@ for (size_t n=0; n < partitions.GetCount(); ++n)
 for (size_t n=0; n < partitions.GetCount(); ++n)
   { wxString item = partitions.Item(n);
     if (item == dev || item == symtarget)
+#ifdef __linux__
       { struct mntent* mnt = NULL;             // Found an entry.  Look for it in mtab
         FILE* fmp = setmntent (_PATH_MOUNTED, "r"); if (fmp==NULL) { endfsent(); return answerarray.GetCount() > 0; }
         while (1)                    
@@ -2166,6 +2249,16 @@ for (size_t n=0; n < partitions.GetCount(); ++n)
               if (wxString(mnt->mnt_dir,wxConvUTF8) == mountpts.Item(n))                                          //   but it's already mounted here
                   { endmntent(fmp);  break; }  // so look in 'partitions' array for another entry
           }
+#else
+      { struct statfs* fslist;
+        int numfs = getmntinfo(&fslist, MNT_NOWAIT);
+        if (numfs < 1) return answerarray.GetCount() > 0;
+        for (int i = 0; i < numfs; ++i)
+          if (wxString(fslist[i].f_mntfromname, wxConvUTF8) == dev || wxString(fslist[i].f_mntfromname, wxConvUTF8) == symtarget)
+            if (wxString(fslist[i].f_mntonname, wxConvUTF8) == mountpts.Item(n)) goto another;
+        answerarray.Add(mountpts.Item(n));
+another:;
+#endif
       }
   }
 
@@ -2921,8 +3014,13 @@ for (size_t n=0; n < allpartitions.GetCount(); ++n)
   { if (allpartitions[n].Left(len) == dev.Left(len))  // If the 1st 'len' letters of the NAME bit of this partition match dev  ie  /dev/sda1 matches /dev/sda
       { partitions.Add(allpartitions[n]);             //   store it in the real partition array
     
+#ifdef __linux__
         struct mntent* mnt = ReadMtab(allpartitions[n]); // Now see if this partition is currently mounted
         if (mnt != NULL)  mountpts.Add(wxString(mnt->mnt_dir, wxConvUTF8));  // If so, store the mountpt
+#else
+        struct statfs* mnt = ReadMtab(allpartitions[n]);
+        if (mnt != NULL) mountpts.Add(wxString(mnt->f_mntonname, wxConvUTF8));
+#endif
           else mountpts.Add(wxEmptyString);           // Otherwise store ""
       }
   }
@@ -2944,7 +3042,11 @@ wxTextFile file;                                    //
 void DeviceAndMountManager::CheckSupermountTab(wxArrayString& partitions, wxArrayString& mountpts,  wxString dev, bool SearchMtab)    // In Supermount systems, finds data for this device
 {
 wxTextFile file;                                    // Create a textfile
+#ifdef __linux__
 if (SearchMtab)  file.Create(wxT(_PATH_MOUNTED));   //  using mtab
+#else
+if (SearchMtab) return;
+#endif
  else  file.Create(wxT(_PATH_FSTAB));               //   or fstab
 if (!file.Exists())    return;
 file.Open(); if (!file.IsOpened())  return;
@@ -2971,17 +3073,27 @@ void DeviceAndMountManager::SearchMtab(wxArrayString& 
 
 void DeviceAndMountManager::SearchMtab(wxArrayString& partitions, wxArrayString& mountpts,  wxString dev /*=wxEmptyString*/)  // Loads arrays with data for the named device, or for all devices. NB Only finds mounted partitions
 {
+#ifdef __linux__
 struct mntent* mnt = NULL;
+#else
+struct statfs* fslist;
+#endif
 
 partitions.Empty(); mountpts.Empty();               // Empty the arrays of any old data:  we don't want to append!
 
+#ifdef __linux__
 FILE* fmp = setmntent (_PATH_MOUNTED, "r");         // Get a file* to (probably) /etc/mtab
 if (fmp==NULL) return;
+#else
+int numfs = getmntinfo(&fslist, MNT_NOWAIT);
+if (numfs < 1) return;
+#endif
 
 wxString mask;
 if (dev.IsEmpty()) mask = AUTOMOUNT_USB_PREFIX;     // We normally search for all AUTOMOUNT_USB_PREFIX devices, probably "/dev/sd"
   else mask = dev;                                  //   but if dev isn't empty, use this instead
 
+#ifdef __linux__
 while (1)                                           // For every mtab entry
   { mnt = getmntent(fmp);                           // Get a struct representing a mounted partition
     if (mnt == NULL) { endmntent(fmp); return; }    // If it's null, we've run out of candidates
@@ -2990,18 +3102,29 @@ while (1)                                           //
     if (wxString(mnt->mnt_fsname, wxConvUTF8).Left(mask.Len()) == mask)
       { partitions.Add(wxString(mnt->mnt_fsname, wxConvUTF8));  // If so, store the devnode and mountpt
         mountpts.Add(wxString(mnt->mnt_dir, wxConvUTF8));
+#else
+for (int i = 0; i < numfs; ++i)
+  { if (wxString(fslist[i].f_mntfromname, wxConvUTF8).Left(mask.Len()) == mask)
+      { partitions.Add(wxString(fslist[i].f_mntfromname, wxConvUTF8));
+        mountpts.Add(wxString(fslist[i].f_mntonname, wxConvUTF8));
+#endif
       }
   }
 }
 
 void DeviceAndMountManager::SearchMtabForStandardMounts(wxString& device, wxArrayString& mountpts)  // Finds ext2 etc mountpts for the device ie not subfs. Used for DVD-RAM
 {
+#ifdef __linux__
 struct mntent* mnt = NULL;
+#else
+struct statfs* fslist;
+#endif
 mountpts.Empty();                                   // Empty the array of any old data:  we don't want to append!
 
 wxString symtarget; FileData fd(device);            // Beware of the symlink
 if (fd.IsSymlink()) symtarget = fd.GetUltimateDestination();
 
+#ifdef __linux__
 FILE* fmp = setmntent (_PATH_MOUNTED, "r");         // Get a file* to (probably) /etc/mtab
 if (fmp==NULL) return;
 
@@ -3012,12 +3135,26 @@ while (1)                                           //
     bool found = false;
     if (wxString(mnt->mnt_fsname, wxConvUTF8).Left(device.Len()) == device)  found=true;   // See if this is a mount for the device we're interested in
      else if (!symtarget.IsEmpty() && wxString(mnt->mnt_fsname, wxConvUTF8).Left(symtarget.Len()) == symtarget)  found=true;   // Try again with any symlink target
+#else
+int numfs = getmntinfo(&fslist, MNT_NOWAIT);
+if (numfs < 1) return;
 
+for (int i = 0; i < numfs; ++i)
+  { bool found = false;
+    if (wxString(fslist[i].f_mntfromname, wxConvUTF8).Left(device.Len()) == device) found=true;
+    else if (!symtarget.IsEmpty() && wxString(fslist[i].f_mntfromname, wxConvUTF8).Left(symtarget.Len()) == symtarget) found=true;
+#endif
+
      if (!found) continue;                          // Wrong device
      
     for (size_t n=0; n < RealFilesystemsArray.GetCount(); ++n)  // For DVD-RAM, we're only interested in filesystems like ext2 not eg subfs
+#ifdef __linux__
       if (wxString(mnt->mnt_type, wxConvUTF8).Left(3) == RealFilesystemsArray.Item(n).Left(3))
           { mountpts.Add(wxString(mnt->mnt_dir, wxConvUTF8)); break; } // If the type is right,  this mountpt is one we want to store  
+#else
+      if (wxString(fslist[i].f_fstypename, wxConvUTF8).Left(3) == RealFilesystemsArray.Item(n).Left(3))
+          { mountpts.Add(wxString(fslist[i].f_mntonname, wxConvUTF8)); break; }
+#endif
     }
 }
 
