GDB installs gcore(1) shell script on Linux:

gcore(1):
    -o filename
       write core file to filename instead of core.pid

gcore(1) is disabled in the devel/gdb port, and FreeBSD's
gcore(1) provides a different command line option

gcore(1):
    -c      Write the core file to the specified file instead of
            "core.<pid>".

--- superlance/httpok.py.orig	2017-10-25 04:36:10 UTC
+++ superlance/httpok.py
@@ -351,7 +351,7 @@ def main(argv=sys.argv):
     programs = []
     any = False
     sendmail = '/usr/sbin/sendmail -t -i'
-    gcore = '/usr/bin/gcore -o'
+    gcore = '/usr/bin/gcore -c'
     coredir = None
     eager = True
     email = None
