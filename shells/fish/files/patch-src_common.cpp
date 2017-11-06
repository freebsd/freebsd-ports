--- src/common.cpp.orig	2017-06-16 23:56:48 UTC
+++ src/common.cpp
@@ -1986,7 +1986,7 @@ void redirect_tty_output() {
 }
 
 /// Display a failed assertion message, dump a stack trace if possible, then die.
-[[noreturn]] void __assert(const char *msg, const char *file, size_t line, int error) {
+[[noreturn]] void __fish_assert(const char *msg, const char *file, size_t line, int error) {
     if (error) {
         debug(0, L"%s:%zu: failed assertion: %s: errno %d (%s)", file, line, msg, error,
               strerror(error));
