--- iso9660.h.orig	Wed Oct 15 15:37:41 2003
+++ iso9660.h	Wed Oct 15 15:41:13 2003
@@ -13,98 +13,98 @@
 #define ISO9660_r 1
 #define ISO9660_T 1
 
-static char *app_help = "{Specifies  a  text string that will be written into the
-volume header.  This should describe the application
-that will be on the disc.  There is space on the disc
+static char *app_help = "{Specifies  a  text string that will be written into the\n\
+volume header.  This should describe the application\n\
+that will be on the disc.  There is space on the disc\n\
 for 128 characters of  information.}";
-static char *vol_help =  "{Specifies the volume ID to be written into the master 
-block.There is space on the disc for 32 characters of
+static char *vol_help =  "{Specifies the volume ID to be written into the master \n\
+block.There is space on the disc for 32 characters of\n\
 information.}";
-static char *prep_help = "{Specifies  a  text string that will be written into
-the volume header.  This should describe  the  preparer
-of the CDROM, usually with a mailing address
-and phone number.  There is space on the  disc  for
+static char *prep_help = "{Specifies  a  text string that will be written into\n\
+the volume header.  This should describe  the  preparer\n\
+of the CDROM, usually with a mailing address\n\
+and phone number.  There is space on the  disc  for\n\
 128  characters of information.}";
-static char *pub_help = "{Specifies a text string that will be  written  into
-the  volume  header.  This should describe the 
-publisher of the CDROM, usually with a mailing address
-and  phone  number.  There is space on the disc for
+static char *pub_help = "{Specifies a text string that will be  written  into\n\
+the  volume  header.  This should describe the \n\
+publisher of the CDROM, usually with a mailing address\n\
+and  phone  number.  There is space on the disc for\n\
 128 characters of information.}";
-static char *a_help = "{Normally  files that contain the characters '~' or '#'
-will not be included (these  are  typically  backup
+static char *a_help = "{Normally  files that contain the characters '~' or '#'\n\
+will not be included (these  are  typically  backup\n\
 files for editors under unix).}";
-static char *b_help = "{Specifies  the  path and filename of the boot image
-to be used when making an \"El Torito\"  bootable  CD.
-This option is required to  make a bootable CD.  The
-boot image must be exactly the size of either a 1.2,
-1.44,  or a  2.88  meg floppy,  and mkisofs will use
-this size when creating the output iso9660 filesystem.
-It is assumed that  the first 512 byte sector should
-be  read  from the  boot image  (it  is  essentially
+static char *b_help = "{Specifies  the  path and filename of the boot image\n\
+to be used when making an \"El Torito\"  bootable  CD.\n\
+This option is required to  make a bootable CD.  The\n\
+boot image must be exactly the size of either a 1.2,\n\
+1.44,  or a  2.88  meg floppy,  and mkisofs will use\n\
+this size when creating the output iso9660 filesystem.\n\
+It is assumed that  the first 512 byte sector should\n\
+be  read  from the  boot image  (it  is  essentially\n\
 emulating a  normal floppy drive).}";
-static char *c_help = "{Specifies the path and filename of the boot catalog
-to  be used when making an \"El Torito\" bootable CD.
-This option is required to make a bootable CD. This
-file  will be  created  by mkisofs  in  the  source
-filesystem,  so be sure the specified filename does
-not conflict with an existing  file,  as it will be
-quietly overwritten! 
+static char *c_help = "{Specifies the path and filename of the boot catalog\n\
+to  be used when making an \"El Torito\" bootable CD.\n\
+This option is required to make a bootable CD. This\n\
+file  will be  created  by mkisofs  in  the  source\n\
+filesystem,  so be sure the specified filename does\n\
+not conflict with an existing  file,  as it will be\n\
+quietly overwritten! \n\
 Usually a name like \"boot.catalog\" is chosen.}";
-static char *d_help = "{Omit  trailing period from files that do not have a
-period.  This violates the ISO9660 standard, but it
+static char *d_help = "{Omit  trailing period from files that do not have a\n\
+period.  This violates the ISO9660 standard, but it\n\
 happens to work on many systems.  Use with caution.}";
-static char *D_help = "{Do not use deep directory relocation,  and  instead
-just  pack  them in the way we see them.  This violates
-the ISO9660 standard, but it  works  on  many
+static char *D_help = "{Do not use deep directory relocation,  and  instead\n\
+just  pack  them in the way we see them.  This violates\n\
+the ISO9660 standard, but it  works  on  many\n\
 systems.  Use with caution.}";
-static char *f_help = "{Follow  symbolic links when generating the filesystem.
-When this option  is  not  in  use,  symbolic links
-will be entered using Rock Ridge if enabled, otherwise
+static char *f_help = "{Follow  symbolic links when generating the filesystem.\n\
+When this option  is  not  in  use,  symbolic links\n\
+will be entered using Rock Ridge if enabled, otherwise\n\
 the file will be ignored.}";
-static char *l_help = "{Allow full 32 character  filenames.   Normally  the
-ISO9660  filename will be in an 8.3 format which is
-compatible with MS-DOS,  even  though  the  ISO9660
-standard  allows  filenames of up to 32 characters.
-If you use this option, the disc may  be  difficult
-to  use on a MS-DOS system, but this comes in handy
-on some other systems (such  as  the  Amiga).   Use
+static char *l_help = "{Allow full 32 character  filenames.   Normally  the\n\
+ISO9660  filename will be in an 8.3 format which is\n\
+compatible with MS-DOS,  even  though  the  ISO9660\n\
+standard  allows  filenames of up to 32 characters.\n\
+If you use this option, the disc may  be  difficult\n\
+to  use on a MS-DOS system, but this comes in handy\n\
+on some other systems (such  as  the  Amiga).   Use\n\
 with caution.}";
-static char *L_help = "{Allow filenames to begin with a period.  Usually, a
-leading dot is replaced with an underscore in order
+static char *L_help = "{Allow filenames to begin with a period.  Usually, a\n\
+leading dot is replaced with an underscore in order\n\
 to maintain MS-DOS compatibility.}";
-static char *m_help = "{Exclude  glob from being written to CDROM.  glob is
-a shell wild-card-style  pattern  that  must  match
+static char *m_help = "{Exclude  glob from being written to CDROM.  glob is\n\
+a shell wild-card-style  pattern  that  must  match\n\
 part  of  the filename.}";
-static char *N_help = "{Omit version numbers from ISO9660 file names.  This
-may violate the ISO9660 standard, but no one really
+static char *N_help = "{Omit version numbers from ISO9660 file names.  This\n\
+may violate the ISO9660 standard, but no one really\n\
 uses the version numbers anyway.  Use with caution.}";
-static char *R_help = "{Generate SUSP and RR records using the  Rock  Ridge
-protocol  to  further  describe  the  files  on the
+static char *R_help = "{Generate SUSP and RR records using the  Rock  Ridge\n\
+protocol  to  further  describe  the  files  on the\n\
 iso9660 filesystem.}";
-static char *r_help = "{The uid and gid of files are set to zero,  all the 
-file  read bits are  set  true,  so that files  and
-directories are globally readable on the client. If
-any execute bit  is  set for a file, set all of the
-execute  bits,  so  that executables  are  globally
-executable on the client. If any search  bit is set
-for a  directory,  set all of the search  bits,  so
-that  directories  are  globally searchable on  the
-client.   All  write  bits are cleared, because the
-CD-Rom will be  mounted  readonly  in any case.  If
-any of the  special mode  bits are set, clear them,
-because file locks  are  not useful  on a read-only
-file system,  and set-id bits are not desirable for
+static char *r_help = "{The uid and gid of files are set to zero,  all the \n\
+file  read bits are  set  true,  so that files  and\n\
+directories are globally readable on the client. If\n\
+any execute bit  is  set for a file, set all of the\n\
+execute  bits,  so  that executables  are  globally\n\
+executable on the client. If any search  bit is set\n\
+for a  directory,  set all of the search  bits,  so\n\
+that  directories  are  globally searchable on  the\n\
+client.   All  write  bits are cleared, because the\n\
+CD-Rom will be  mounted  readonly  in any case.  If\n\
+any of the  special mode  bits are set, clear them,\n\
+because file locks  are  not useful  on a read-only\n\
+file system,  and set-id bits are not desirable for\n\
 uid 0 or gid 0.}";
-static char *T_help = "{Generate a file TRANS.TBL in each directory on  the
-CDROM,  which can be used on non-Rock Ridge capable
-systems to help establish the correct  file  names.
-There  is also information present in the file that
-indicates the major and minor numbers for block and
-character devices, and each symlink has the name of
+static char *T_help = "{Generate a file TRANS.TBL in each directory on  the\n\
+CDROM,  which can be used on non-Rock Ridge capable\n\
+systems to help establish the correct  file  names.\n\
+There  is also information present in the file that\n\
+indicates the major and minor numbers for block and\n\
+character devices, and each symlink has the name of\n\
 the link file given.}";
-static char *x_help = "{Exclude path from being  written  to  CDROM.   path
-must  be  the  complete  pathname that results from
-concatenating the pathname given  as  command  line
-argument  and  the path relative to this directory.
+static char *x_help = "{Exclude path from being  written  to  CDROM.   path\n\
+must  be  the  complete  pathname that results from\n\
+concatenating the pathname given  as  command  line\n\
+argument  and  the path relative to this directory.\n\
 Multiple paths may be excluded (up to 1000).}";
 
