--- src/main.c.orig	Wed Oct 15 06:33:06 2003
+++ src/main.c	Wed Oct 15 06:33:46 2003
@@ -37,42 +37,42 @@
 
 void usage(FILE *fout) {
   fprintf(fout, "\
-"NAME" "VERSION". Secure encryption and decryption of files and streams.
-
-Usage: "NAME" [mode] [options] [file...]
-       "NAMEENCRYPT" [options] [file...]
-       "NAMEDECRYPT" [options] [file...]
-       "NAMECAT" [options] file...
-
-Modes:
-    -e, --encrypt          encrypt
-    -d, --decrypt          decrypt
-    -c, --cat              cat; decrypt files to stdout
-    -x, --keychange        change key
-    -u, --unixcrypt        decrypt old unix crypt files
-
-Options:
-    -h, --help             print this help message and exit
-    -V, --version          print version info and exit
-    -L, --license          print license info and exit
-    -v, --verbose          print progress information to stderr
-    -q, --quiet            run quietly; suppress warnings
-    -f, --force            overwrite existing files without asking
-    -m, --mismatch         allow decryption with non-matching key
-    -E, --envvar var       read keyword from environment variable (unsafe)
-    -K, --key key          give keyword on command line (unsafe)
-    -k, --keyfile file     read keyword(s) as first line(s) from file
-    -P, --prompt prompt    use this prompt instead of default
-    -S, --suffix .suf      use suffix .suf instead of default "SUF"
-    -s, --strictsuffix     refuse to encrypt files which already have suffix
-    -F, --envvar2 var      as -E for second keyword (for keychange mode)
-    -H, --key2 key         as -H for second keyword (for keychange mode)
-    -Q, --prompt2 prompt   as -P for second keyword (for keychange mode)
-    -t, --timid            prompt twice for destructive encryption keys
-    -r, --recursive        recurse through directories
-    -R, --rec-symlinks     follow symbolic links as subdirectories
-    -l, --symlinks         dereference symbolic links
-    --                     end of options, filenames follow
+"NAME" "VERSION". Secure encryption and decryption of files and streams. \n\
+ \n\
+Usage: "NAME" [mode] [options] [file...] \n\
+       "NAMEENCRYPT" [options] [file...] \n\
+       "NAMEDECRYPT" [options] [file...] \n\
+       "NAMECAT" [options] file... \n\
+ \n\
+Modes: \n\
+    -e, --encrypt          encrypt \n\
+    -d, --decrypt          decrypt \n\
+    -c, --cat              cat; decrypt files to stdout \n\
+    -x, --keychange        change key \n\
+    -u, --unixcrypt        decrypt old unix crypt files \n\
+\n\
+Options:\n\
+    -h, --help             print this help message and exit\n\
+    -V, --version          print version info and exit\n\
+    -L, --license          print license info and exit\n\
+    -v, --verbose          print progress information to stderr\n\
+    -q, --quiet            run quietly; suppress warnings\n\
+    -f, --force            overwrite existing files without asking\n\
+    -m, --mismatch         allow decryption with non-matching key\n\
+    -E, --envvar var       read keyword from environment variable (unsafe)\n\
+    -K, --key key          give keyword on command line (unsafe)\n\
+    -k, --keyfile file     read keyword(s) as first line(s) from file\n\
+    -P, --prompt prompt    use this prompt instead of default\n\
+    -S, --suffix .suf      use suffix .suf instead of default "SUF"\n\
+    -s, --strictsuffix     refuse to encrypt files which already have suffix\n\
+    -F, --envvar2 var      as -E for second keyword (for keychange mode)\n\
+    -H, --key2 key         as -H for second keyword (for keychange mode)\n\
+    -Q, --prompt2 prompt   as -P for second keyword (for keychange mode)\n\
+    -t, --timid            prompt twice for destructive encryption keys\n\
+    -r, --recursive        recurse through directories\n\
+    -R, --rec-symlinks     follow symbolic links as subdirectories\n\
+    -l, --symlinks         dereference symbolic links\n\
+    --                     end of options, filenames follow\n\
 ");
 }
 
