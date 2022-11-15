--- Mounts.cpp.orig	2020-11-22 11:42:50 UTC
+++ Mounts.cpp
@@ -866,8 +866,13 @@ for (size_t n=0; n < parent->PartitionArray->GetCount(
   if (parent->PartitionArray->Item(n)->device == dev.BeforeFirst(' ')) // BeforeFirst in case of "/dev/sda1  $UUID/$LABEL"
     { if (GetDataFromMtab)    // If we're unmounting, we can't rely on the PartitionArray info:  the partition may not have been mounted where fstab intended
         { FstabMountptTxt->Clear();
+#ifdef __linux__
           struct mntent* mnt = parent->ReadMtab(dev.BeforeFirst(' ')); // So see where it really is
           if (mnt != NULL)   FstabMountptTxt->ChangeValue(wxString(mnt->mnt_dir, wxConvUTF8));
+#else
+          struct statfs* mnt = parent->ReadMtab(dev.BeforeFirst(' '));
+          if (mnt != NULL) FstabMountptTxt->ChangeValue(wxString(mnt->f_mntonname, wxConvUTF8));
+#endif
           return;
         }
        else
@@ -968,10 +973,18 @@ FstabMt = (InFstab ? wxString(fs->fs_file, wxConvUTF8)
 InFstab = (fs != NULL);                                       // Store or null the data according to the result
 FstabMt = (InFstab ? wxString(fs->fs_file, wxConvUTF8) : wxT(""));
 
+#ifdef __linux__
 struct mntent* mnt = DeviceAndMountManager::ReadMtab(Image);  // Now read mtab to see if the share's already mounted
+#else
+struct statfs* mnt = DeviceAndMountManager::ReadMtab(Image);
+#endif
 IsMounted = (mnt != NULL);
 AlreadyMounted->Show(IsMounted); GetSizer()->Layout();        // If it is mounted, expose the wxStaticTxt that says so (and Layout, else 2.8.0 displays it in top left corner!)
+#ifdef __linux__
 AtMountPt = (IsMounted ? wxString(mnt->mnt_dir, wxConvUTF8) : wxT(""));  // Store any mountpt, or delete any previous entry
+#else
+AtMountPt = (IsMounted ? wxString(mnt->f_mntonname, wxConvUTF8) : wxT(""));
+#endif
 if (IsMounted)
     MountptCombo->SetValue(AtMountPt);                        // Put any mountpt in the combobox
   else if (InFstab)
@@ -1209,11 +1222,19 @@ FstabMt = (InFstab ? wxString(fs->fs_file, wxConvUTF8)
 InFstab = (fs != NULL);                                                   // Store or null the data according to the result
 FstabMt = (InFstab ? wxString(fs->fs_file, wxConvUTF8) : wxT(""));
 
+#ifdef __linux__
 struct mntent* mnt = DeviceAndMountManager::ReadMtab(device1);            // Now read mtab to see if the share's already mounted
+#else
+struct statfs* mnt = DeviceAndMountManager::ReadMtab(device1);
+#endif
 if (mnt == NULL)  mnt = DeviceAndMountManager::ReadMtab(device2);         // Null means not found, so try again with the IP version
 IsMounted = (mnt != NULL);
 AlreadyMounted->Show(IsMounted); GetSizer()->Layout();                    // If it is mounted, expose the wxStaticTxt that says so (and Layout, else 2.8.0 displays it in top left corner!)
+#ifdef __linux__
 AtMountPt = (IsMounted ? wxString(mnt->mnt_dir, wxConvUTF8) : wxT(""));   // Store any mountpt, or delete any previous entry
+#else
+AtMountPt = (IsMounted ? wxString(mnt->f_mntonname, wxConvUTF8) : wxT(""));
+#endif
 if (IsMounted)
     MountptCombo->SetValue(AtMountPt);
   else if (InFstab)
@@ -1503,10 +1524,18 @@ FstabMt = (InFstab ? wxString(fs->fs_file, wxConvUTF8)
 InFstab = (fs != NULL);                                     // Store or null the data according to the result
 FstabMt = (InFstab ? wxString(fs->fs_file, wxConvUTF8) : wxT(""));
 
+#ifdef __linux__
 mntent* mnt = DeviceAndMountManager::ReadMtab(device);      // Now read mtab to see if the share's already mounted
+#else
+struct statfs* mnt = DeviceAndMountManager::ReadMtab(device);
+#endif
 IsMounted = (mnt != NULL);
 AlreadyMounted->Show(IsMounted); GetSizer()->Layout();      // If it is mounted, expose the wxStaticTxt that says so (and Layout, else 2.8.0 displays it in top left corner!)
+#ifdef __linux__
 AtMountPt = (IsMounted ? wxString(mnt->mnt_dir, wxConvUTF8) : wxT(""));  // Store any mountpt, or delete any previous entry
+#else
+AtMountPt = (IsMounted ? wxString(mnt->f_mntonname, wxConvUTF8) : wxT(""));
+#endif
 
 if (IsMounted)
     MountptCombo->SetValue(AtMountPt);
@@ -1736,6 +1765,7 @@ void UnMountSambaDialog::SearchForNetworkMounts()  // 
 
 void UnMountSambaDialog::SearchForNetworkMounts()  // Scans mtab for established NFS & samba mounts
 {
+#ifdef __linux__
 FILE* fmp = setmntent (_PATH_MOUNTED, "r");                   // Get a file* to (probably) /etc/mtab
 if (fmp==NULL) return;
 
@@ -1749,6 +1779,19 @@ while (1)                                             
       { struct PartitionStruct* newmnt = new struct PartitionStruct;
         newmnt->device = wxString(mnt->mnt_fsname, wxConvUTF8);
         newmnt->mountpt = wxString(mnt->mnt_dir, wxConvUTF8);
+#else
+struct statfs *fslist;
+
+int numfs = getmntinfo(&fslist, MNT_NOWAIT);
+if (numfs < 1) return;
+
+for (int i = 0; i < numfs; ++i)
+  { wxString type(fslist[i].f_fstypename, wxConvUTF8);
+    if (ParseNetworkFstype(type) != MT_invalid)
+      { struct PartitionStruct* newmnt = new struct PartitionStruct;
+        newmnt->device = wxString(fslist[i].f_mntfromname, wxConvUTF8);
+        newmnt->mountpt = wxString(fslist[i].f_mntonname, wxConvUTF8);
+#endif
         newmnt->type = type;
         Mntarray.Add(newmnt);                      
       }
