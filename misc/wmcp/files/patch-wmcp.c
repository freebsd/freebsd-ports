--- wmcp.c.orig	Sat Jan  3 17:14:42 2004
+++ wmcp.c	Sat Jan  3 17:15:43 2004
@@ -806,38 +806,38 @@
 void show_usage()
 {
 
-fprintf(stderr,"
-
-%s
-This software is GPL -- do as you wish with it.
-
-Origional Author:
-   Ben Cohen <buddog@aztec.asu.edu>
-
-Contributors:
-   Thomas Nemeth <tnemeth@multimania.com>
-   Craig Maloney <craig@ic.net>
-   Gert Beumer <Gert@scintilla.utwente.nl>
-
-
-
-usage: wmcp [-g geometry] [-d dpy] [-n workspaces] [-a alt key] [-v]
-            [-c] [-w i/n/w] [-s y/n] [-x #] [-y #] [-h]
-
-
--g    geometry:    ie: 64x64+10+10
--d    dpy:         Display. ie: 127.0.0.1:0.0
--n    workspaces:  How many buttons to start with.
--a    alt key:     integer 1-4 defining ModXMask (default 1 Mod1Mask).
--w    i/n/w:       Window State: Iconic, Normal, Withdrawn (default Withdrawn)
--s    y/n:         Shaped window: yes or no (default y)
--c                 Sends CTRL + ALT + Key (default only sends ALT + key)
--v                 Verbose. 0=off, 1=on (default 0)
--x                 Number of buttons on the x-direction (1,2,3, or 4)
--y                 Number of buttons in the y-direction (1,2,3, or 4)
--h                 Help. This screen.
-
-
+fprintf(stderr,"\n\
+\n\
+%s\n\
+This software is GPL -- do as you wish with it.\n\
+\n\
+Origional Author:\n\
+   Ben Cohen <buddog@aztec.asu.edu>\n\
+\n\
+Contributors:\n\
+   Thomas Nemeth <tnemeth@multimania.com>\n\
+   Craig Maloney <craig@ic.net>\n\
+   Gert Beumer <Gert@scintilla.utwente.nl>\n\
+\n\
+\n\
+\n\
+usage: wmcp [-g geometry] [-d dpy] [-n workspaces] [-a alt key] [-v]\n\
+            [-c] [-w i/n/w] [-s y/n] [-x #] [-y #] [-h]\n\
+\n\
+\n\
+-g    geometry:    ie: 64x64+10+10\n\
+-d    dpy:         Display. ie: 127.0.0.1:0.0\n\
+-n    workspaces:  How many buttons to start with.\n\
+-a    alt key:     integer 1-4 defining ModXMask (default 1 Mod1Mask).\n\
+-w    i/n/w:       Window State: Iconic, Normal, Withdrawn (default Withdrawn)\n\
+-s    y/n:         Shaped window: yes or no (default y)\n\
+-c                 Sends CTRL + ALT + Key (default only sends ALT + key)\n\
+-v                 Verbose. 0=off, 1=on (default 0)\n\
+-x                 Number of buttons on the x-direction (1,2,3, or 4)\n\
+-y                 Number of buttons in the y-direction (1,2,3, or 4)\n\
+-h                 Help. This screen.\n\
+\n\
+\n\
 ",VERSION);
 
 exit(-1);
