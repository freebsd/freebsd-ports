--- src/io.c.orig	Fri Apr 11 16:58:15 2003
+++ src/io.c	Fri Apr 11 17:03:11 2003
@@ -130,12 +130,12 @@
     /* save only 'not root' mounts -> plain password */
     if ( (mount != NULL) && (mount->type != mem_mount_root) )
     {
-      string_ncopy(str, pref.v.smbmount_exe, MAXMACHNAMEL+MAXSHRNAMEL+PATH_LEN+19);
+      *str = 0;
       temp = str;
-      temp += strlen(str);
       merge_mount(&temp, mount, MAXMACHNAMEL+MAXSHRNAMEL+PATH_LEN+19 - strlen(str), 1);
       string_ncat(str, "\n", MAXMACHNAMEL+MAXSHRNAMEL+PATH_LEN+19);
-      fwrite(str, 1, strlen(str), fd);
+      if (*temp == ' ') ++temp;
+      fwrite(temp, 1, strlen(temp), fd);
     }
   }
 }
