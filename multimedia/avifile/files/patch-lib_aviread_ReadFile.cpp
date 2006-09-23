--- lib/aviread/ReadFile.cpp.orig	Sat Sep 23 14:17:45 2006
+++ lib/aviread/ReadFile.cpp	Sat Sep 23 14:23:49 2006
@@ -8,7 +8,7 @@
 
 AVM_BEGIN_NAMESPACE;
 
-avm::IReadFile::~IReadFile() {}
+IReadFile::~IReadFile() {}
 
 class ReadFile: public IReadFile
 {
@@ -125,7 +125,7 @@
 };
 
 
-avm::IReadFile* avm::CreateReadFile(const char* name, unsigned int flags)
+IReadFile* CreateReadFile(const char* name, unsigned int flags)
 {
     ReadFile* r = new ReadFile(name, flags);
     return r;
