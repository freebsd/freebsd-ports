--- xbmc/linux/LinuxTimezone.cpp	(revision 35637)
+++ xbmc/linux/LinuxTimezone.cpp	(working copy)
@@ -27,6 +27,12 @@
 #include "OSXGNUReplacements.h"
 #endif
 
+#if defined(__FreeBSD__)
+#include "FreeBSDGNUReplacements.h" // getdelim
+#include <sys/types.h>
+#include <dirent.h>
+#endif
+
 #include "Util.h"
 
 using namespace std;
@@ -89,7 +95,11 @@
    }
 
    // Load countries
+#if defined(__FreeBSD__)
+   fp = fopen("/usr/share/misc/iso3166", "r");
+#else
    fp = fopen("/usr/share/zoneinfo/iso3166.tab", "r");
+#endif   
    if (fp)
    {
       CStdString countryCode;
@@ -109,7 +119,14 @@
          // Search for the first non space from the 2nd character and on
          int i = 2;
          while (s[i] == ' ' || s[i] == '\t') i++;
-
+#if defined(__FreeBSD__)
+         // skip three 
+         while (s[i] != ' ' && s[i] != '\t') i++;
+         while (s[i] == ' ' || s[i] == '\t') i++;
+         // skip number
+         while (s[i] != ' ' && s[i] != '\t') i++;
+         while (s[i] == ' ' || s[i] == '\t') i++;
+#endif
          countryCode = s.Left(2);
          countryName = s.Mid(i);
 
@@ -144,7 +161,10 @@
 
 void CLinuxTimezone::SetTimezone(CStdString timezoneName)
 {
-#ifndef __APPLE__
+#if defined(__FreeBSD__)
+   setenv("TZ", timezoneName.c_str(), 1);
+   tzset();
+#elif !defined(__APPLE__)
    static char env_var[255];
    sprintf(env_var, "TZ=:%s", timezoneName.c_str());
    putenv(env_var);
@@ -152,8 +172,125 @@
 #endif
 }
 
+#if defined(__FreeBSD__)
+/*
+* Scans the specified directory and its subdirectories to find a
+* zoneinfo file which has the same content as /etc/localtime given in
+* 'buf'. Returns a zone ID if found, otherwise, NULL is returned.
+*/
+static char *
+findZoneinfoFile(char *buf, size_t size, const char *dir)
+{
+   DIR *dirp = NULL;
+   struct stat statbuf;
+   struct dirent entry;
+   struct dirent *dp;
+   char *pathname = NULL;
+   int fd = -1;
+   char *dbuf = NULL;
+   char *tz = NULL;
+   char *p;
+
+   dirp = opendir(dir);
+   if (dirp == NULL)
+      return NULL;
+
+   while (readdir_r(dirp, &entry, &dp) == 0 && dp != NULL) {
+      if (dp->d_name[0] == '.')
+         continue;
+
+      if (strcmp(dp->d_name, "zone.tab") == 0)
+         continue;
+
+      p = (char *)malloc(strlen(dir) + strlen(dp->d_name) + 2);
+	  if (p == NULL)
+         break;
+
+      pathname = strcat(strcat(strcpy(p, dir), "/"), dp->d_name);
+      if (pathname == NULL)
+         break;
+
+      if (stat(pathname, &statbuf) == -1)
+         break;
+
+      if (S_ISDIR(statbuf.st_mode)) {
+         tz = findZoneinfoFile(buf, size, pathname);
+         if (tz != NULL)
+            break;
+      } else if (S_ISREG(statbuf.st_mode) && (size_t)statbuf.st_size == size) {
+         dbuf = (char *)malloc(size);
+         if (dbuf == NULL)
+            break;
+         if ((fd = open(pathname, O_RDONLY)) == -1) {
+            fd = 0;
+            break;
+         }
+         if (read(fd, dbuf, size) != (ssize_t)size)
+            break;
+         if (memcmp(buf, dbuf, size) == 0) {
+			p = strstr(pathname, "zoneinfo/");
+			if (p == NULL)
+				break;
+			p += strlen("zoneinfo/");	
+            tz = strdup(p);
+            break;
+         }
+         free(dbuf);
+         dbuf = NULL;
+         (void)close(fd);
+         fd = 0;
+      }
+      free(pathname);
+      pathname = NULL;
+   }
+
+   if (dirp != NULL)
+      (void)closedir(dirp);
+   if (pathname != NULL)
+      free(pathname);
+   if (fd != 0)
+      (void)close(fd);
+   if (dbuf != NULL)
+      free(dbuf);
+
+   return tz;
+}
+#endif
+
 CStdString CLinuxTimezone::GetOSConfiguredTimezone()
 {
+#if defined(__FreeBSD__)
+   const char * timezonefile = "/etc/localtime";
+   struct stat statbuf;
+   int fd;
+   char *buf;
+   char *tz;
+   size_t size;
+
+   if (lstat(timezonefile, &statbuf) == -1)
+      return "";   
+   if (!S_ISREG(statbuf.st_mode))
+      return "";   
+	  
+   size = (size_t)statbuf.st_size;
+   buf = (char *)malloc(size);
+
+   if ((fd = open(timezonefile, O_RDONLY)) == -1) {
+      free(buf);
+      return "";
+   }
+
+   if (read(fd, buf, size) != (ssize_t) size) {
+      (void)close(fd);
+	  free(buf);
+	  return "";
+   }
+   (void)close(fd);
+
+   tz = findZoneinfoFile(buf, size, "/usr/share/zoneinfo");
+   free(buf);
+   return tz;
+#else
    char timezoneName[255];
    timezoneName[0] = 0;
    FILE* fp = fopen("/etc/timezone", "r");
@@ -165,6 +302,7 @@
    }
 
    return timezoneName;
+#endif   
 }
 
 CLinuxTimezone g_timezone;
