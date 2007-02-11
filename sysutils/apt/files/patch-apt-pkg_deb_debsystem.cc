--- apt-pkg/deb/debsystem.cc.orig	Thu Mar  2 06:11:39 2006
+++ apt-pkg/deb/debsystem.cc	Wed Oct 25 15:09:29 2006
@@ -162,8 +162,8 @@
       which is yet to be determined. The functions in pkgcachegen should
       be the only users of these */
    Cnf.CndSet("Dir::State::userstatus","status.user"); // Defunct
-   Cnf.CndSet("Dir::State::status","/var/lib/dpkg/status");
-   Cnf.CndSet("Dir::Bin::dpkg","/usr/bin/dpkg");
+   Cnf.CndSet("Dir::State::status","@DPKGDIR@/status");
+   Cnf.CndSet("Dir::Bin::dpkg","@LOCALBASE@/bin/dpkg");
 
    if (StatusFile) {
      delete StatusFile;
@@ -191,9 +191,9 @@
 signed debSystem::Score(Configuration const &Cnf)
 {
    signed Score = 0;
-   if (FileExists(Cnf.FindFile("Dir::State::status","/var/lib/dpkg/status")) == true)
+   if (FileExists(Cnf.FindFile("Dir::State::status","@DPKGDIR@/status")) == true)
        Score += 10;
-   if (FileExists(Cnf.FindFile("Dir::Bin::dpkg","/usr/bin/dpkg")) == true)
+   if (FileExists(Cnf.FindFile("Dir::Bin::dpkg","@LOCALBASE@/bin/dpkg")) == true)
       Score += 10;
    if (FileExists("/etc/debian_version") == true)
       Score += 10;
