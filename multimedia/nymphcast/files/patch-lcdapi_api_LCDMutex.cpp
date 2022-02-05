--- lcdapi/api/LCDMutex.cpp.orig	2022-02-05 21:50:30 UTC
+++ lcdapi/api/LCDMutex.cpp
@@ -22,7 +22,7 @@ namespace lcdapi {
 
 using namespace std;
 
-LCDMutex::LCDMutex() : _mutex(), _owner(static_cast<pthread_t>(-1)) {
+LCDMutex::LCDMutex() : _mutex(), _owner(nullptr) {
   ::pthread_mutex_init(&_mutex, 0);
 }
 
@@ -38,7 +38,7 @@ void LCDMutex::lock() {
 }
 
 void LCDMutex::unlock() {
-  _owner = static_cast<pthread_t>(-1);
+  _owner = nullptr;
   ::pthread_mutex_unlock(&_mutex);
 }
 
