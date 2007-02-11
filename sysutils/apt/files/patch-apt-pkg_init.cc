--- apt-pkg/init.cc.orig	Thu Mar  2 06:27:13 2006
+++ apt-pkg/init.cc	Thu Nov  2 13:36:53 2006
@@ -43,26 +43,19 @@
    Cnf.Set("Dir","/");
    
    // State   
-   Cnf.Set("Dir::State","var/lib/apt/");
+   Cnf.Set("Dir::State","@APTDIR@/state");
    
-   /* Just in case something goes horribly wrong, we can fall back to the
-      old /var/state paths.. */
-   struct stat St;   
-   if (stat("/var/lib/apt/.",&St) != 0 &&
-       stat("/var/state/apt/.",&St) == 0)
-      Cnf.Set("Dir::State","var/state/apt/");
-       
    Cnf.Set("Dir::State::lists","lists/");
    Cnf.Set("Dir::State::cdroms","cdroms.list");
    
    // Cache
-   Cnf.Set("Dir::Cache","var/cache/apt/");
+   Cnf.Set("Dir::Cache","@APTDIR@/cache");
    Cnf.Set("Dir::Cache::archives","archives/");
    Cnf.Set("Dir::Cache::srcpkgcache","srcpkgcache.bin");
    Cnf.Set("Dir::Cache::pkgcache","pkgcache.bin");
    
    // Configuration
-   Cnf.Set("Dir::Etc","etc/apt/");
+   Cnf.Set("Dir::Etc","@PREFIX@/etc/apt/");
    Cnf.Set("Dir::Etc::sourcelist","sources.list");
    Cnf.Set("Dir::Etc::sourceparts","sources.list.d");
    Cnf.Set("Dir::Etc::vendorlist","vendors.list");
@@ -70,7 +63,7 @@
    Cnf.Set("Dir::Etc::main","apt.conf");
    Cnf.Set("Dir::Etc::parts","apt.conf.d");
    Cnf.Set("Dir::Etc::preferences","preferences");
-   Cnf.Set("Dir::Bin::methods","/usr/lib/apt/methods");
+   Cnf.Set("Dir::Bin::methods","@PREFIX@/libexec/apt/methods");
    
    bool Res = true;
    
