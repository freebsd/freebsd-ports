--- src/FXFile.cpp.orig	Sat Feb  5 13:10:50 2005
+++ src/FXFile.cpp	Wed Feb  9 17:40:15 2005
@@ -102,7 +102,7 @@
 // Get current user name
 FXString FXFile::getCurrentUserName(){
 #ifndef WIN32
-#ifdef FOX_THREAD_SAFE
+#if defined(FOX_THREAD_SAFE) && !defined(__FreeBSD__)
   struct passwd pwdresult,*pwd;
   char buffer[1024];
   if(getpwuid_r(geteuid(),&pwdresult,buffer,sizeof(buffer),&pwd)==0 && pwd) return pwd->pw_name;
@@ -180,7 +180,7 @@
 // Get home directory for a given user
 FXString FXFile::getUserDirectory(const FXString& user){
 #ifndef WIN32
-#ifdef FOX_THREAD_SAFE
+#if defined(FOX_THREAD_SAFE) && !defined(__FreeBSD__)
   struct passwd pwdresult,*pwd;
   char buffer[1024];
   if(user.empty()){
@@ -1059,7 +1059,7 @@
 FXString FXFile::owner(FXuint uid){
   FXchar result[64];
 #ifndef WIN32
-#ifdef FOX_THREAD_SAFE
+#if defined(FOX_THREAD_SAFE) && !defined(__FreeBSD__)
   struct passwd pwdresult,*pwd;
   char buffer[1024];
   if(getpwuid_r(uid,&pwdresult,buffer,sizeof(buffer),&pwd)==0 && pwd) return pwd->pw_name;
@@ -1077,7 +1077,7 @@
 FXString FXFile::group(FXuint gid){
   FXchar result[64];
 #ifndef WIN32
-#ifdef FOX_THREAD_SAFE
+#if defined(FOX_THREAD_SAFE) && !defined(__FreeBSD__)
   ::group grpresult;
   ::group *grp;
   char buffer[1024];
@@ -1435,7 +1435,7 @@
 // Convert file time to string as per strftime format
 FXString FXFile::time(const FXchar *format,FXTime filetime){
 #ifndef WIN32
-#ifdef FOX_THREAD_SAFE
+#if defined(FOX_THREAD_SAFE) && !defined(__FreeBSD__)
   time_t tmp=(time_t)FXMAX(filetime,0);
   struct tm tmresult;
   FXchar buffer[512];
