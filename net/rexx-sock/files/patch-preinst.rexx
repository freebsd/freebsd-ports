--- preinst.rexx.orig	Tue Jan 27 12:01:19 2004
+++ preinst.rexx	Tue Jan 27 12:01:27 2004
@@ -5,6 +5,6 @@
 Call Lineout outfile, "#!" || rexx_exe
 Do While(Lines(infile) > 0)
    line = Linein(infile)
-   Call Lineout(outfile, line )
+   Call Lineout outfile, line
 End
 Return 0
