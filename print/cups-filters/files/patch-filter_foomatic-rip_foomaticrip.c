--- filter/foomatic-rip/foomaticrip.c.orig	2015-10-20 14:59:20 UTC
+++ filter/foomatic-rip/foomaticrip.c
@@ -656,6 +656,7 @@ int print_file(const char *filename, int
                     rip_die(EXIT_PRNERR_NORETRY_BAD_SETTINGS,
                             "Couldn't dup stdout of pdf-to-ps\n");
 
+                clearerr(stdin);
                 ret = print_file("<STDIN>", 0);
 
                 wait_for_process(renderer_pid);
