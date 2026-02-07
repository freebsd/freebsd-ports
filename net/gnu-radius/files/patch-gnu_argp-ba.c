--- gnu/argp-ba.c.orig	2008-12-15 08:05:24 UTC
+++ gnu/argp-ba.c
@@ -23,4 +23,4 @@
    the ARGP_HELP_BUG_ADDR flag is set (as it is by various standard help
    messages), embedded in a sentence that says something like `Report bugs to
    ADDR.'.  */
-const char *argp_program_bug_address;
+extern const char *argp_program_bug_address;
