--- src/registry.cpp.old	Fri Dec 12 03:16:27 2003
+++ src/registry.cpp	Fri Dec 12 03:16:48 2003
@@ -79,7 +79,7 @@
 //=== Get String =========================================================
 // Return the value of key, if missed return default value
 //========================================================================
-char *Registry::getString(const char *property, const char *defaultValue = "") {
+char *Registry::getString(const char *property, const char *defaultValue) {
 	bool found = false;
 	char *ret = NULL;
 	FILE *f;
@@ -113,7 +113,7 @@
 //=== Get Int ============================================================
 // Return the value of key, if missed return default value
 //========================================================================
-int Registry::getInt(const char *property, const int defaultValue = 0) {
+int Registry::getInt(const char *property, const int defaultValue) {
 	int ret = defaultValue;
 	char *p;
 	p = getString(property);
@@ -141,7 +141,7 @@
 //=== Get Bool ===========================================================
 // Return the value of key, if missed return default value
 //========================================================================
-bool Registry::getBool(const char *property, const bool defaultValue = false) {
+bool Registry::getBool(const char *property, const bool defaultValue) {
 	bool ret = defaultValue;
 	char *p;
 	p = getString(property);
