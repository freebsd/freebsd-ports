--- src/translator.cpp.orig	Sat Aug  9 19:24:42 2003
+++ src/translator.cpp	Sat Aug  9 19:26:11 2003
@@ -119,7 +119,7 @@
 // Real construcor
 // Call the same method of Database, and return same result
 //========================================================================
-bool Translator::createDictionary(const char *fileName, const int dictionary, const long fixedLastWordPointer = 0) {
+bool Translator::createDictionary(const char *fileName, const int dictionary, const long fixedLastWordPointer) {
 	bool ret = false;
 	switch (dictionary) {
 		case ENG_BUL:
@@ -275,7 +275,7 @@
 // Return true if passed word is legal bulgarian word as LATIN_INPUT
 // Return pointer to new word that is legal dictionary word
 //========================================================================
-bool Translator::isLatinInput(const char *word, char *buf, const bool ignoreSpace = false) {
+bool Translator::isLatinInput(const char *word, char *buf, const bool ignoreSpace ) {
 	int i = 0;
 	char *p;
 	while (word[i] != '\0') {
@@ -304,7 +304,7 @@
 // to a normal latin output
 // Change buffer and return pointer to new word
 //========================================================================
-char *Translator::toLatin(const char *word, char *buf, const bool legalLatinInput = true) {
+char *Translator::toLatin(const char *word, char *buf, const bool legalLatinInput ) {
 	int i = 0;
 	int j = 0;
 	char *p;
@@ -348,7 +348,7 @@
 // Call the same method of Database, and return same result
 // But perform some operations
 //========================================================================
-char *Translator::getWord(const bool lowerCase = true, const bool legalLatinInput = true) {
+char *Translator::getWord(const bool lowerCase, const bool legalLatinInput ) {
 	char *ret = NULL;
 	switch (currentDictionary) {
 		case ENG_BUL:
