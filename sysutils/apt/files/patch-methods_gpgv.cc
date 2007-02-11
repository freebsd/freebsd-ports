--- methods/gpgv.cc.orig	Tue Jul 25 04:19:02 2006
+++ methods/gpgv.cc	Tue Nov 14 21:18:00 2006
@@ -52,8 +52,8 @@
    FILE *pipein;
    int status;
    struct stat buff;
-   string gpgvpath = _config->Find("Dir::Bin::gpg", "/usr/bin/gpgv");
-   string pubringpath = _config->Find("APT::GPGV::TrustedKeyring", "/etc/apt/trusted.gpg");
+   string gpgvpath = _config->Find("Dir::Bin::gpg", "@LOCALBASE@/bin/gpgv");
+   string pubringpath = _config->Find("APT::GPGV::TrustedKeyring", "@PREFIX@/etc/apt/trusted.gpg");
    if (_config->FindB("Debug::Acquire::gpgv", false))
    {
       std::cerr << "gpgv path: " << gpgvpath << std::endl;
