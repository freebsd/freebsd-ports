--- src/FXFile.cpp.orig	Fri Apr 16 23:25:33 2004
+++ src/FXFile.cpp	Sat May 22 13:13:48 2004
@@ -159,7 +159,7 @@
 // Get home directory for a given user
 FXString FXFile::getUserDirectory(const FXString& user){
 #ifndef WIN32
-#ifdef FOX_THREAD_SAFE
+#if defined(FOX_THREAD_SAFE) && !defined(__FreeBSD__)
   struct passwd pwdresult,*pwd;
   char buffer[1024];
   if(user.empty()){
@@ -1032,7 +1032,7 @@
 FXString FXFile::owner(FXuint uid){
   FXchar result[64];
 #ifndef WIN32
-#ifdef FOX_THREAD_SAFE
+#if defined(FOX_THREAD_SAFE) && !defined(__FreeBSD__)
   struct passwd pwdresult,*pwd;
   char buffer[1024];
   if(getpwuid_r(uid,&pwdresult,buffer,sizeof(buffer),&pwd)==0 && pwd) return pwd->pw_name;
@@ -1050,7 +1050,7 @@
 FXString FXFile::group(FXuint gid){
   FXchar result[64];
 #ifndef WIN32
-#ifdef FOX_THREAD_SAFE
+#if defined(FOX_THREAD_SAFE) && !defined(__FreeBSD__)
   ::group grpresult;
   ::group *grp;
   char buffer[1024];
