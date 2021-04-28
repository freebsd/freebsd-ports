--- README.md.orig	2021-04-26 14:05:27 UTC
+++ README.md
@@ -11,9 +11,9 @@ Features include color, bar graphs, and smart formatti
 gigabytes, or terabytes). Or choose your own size, along with specifying the
 number of decimal places you'd like to see.
 
-To configure Discus on a system-wide basis, edit the **/etc/discusrc** file.
+To configure Discus on a system-wide basis, edit the **/usr/local/etc/discusrc** file.
 But you should probably change things just for yourself, by copying
-**/etc/discusrc** to **~/.discusrc** and editing that.
+**/usr/local/etc/discusrc** to **~/.discusrc** and editing that.
 
 The source code is contained in the discus.py file itself, as it is a Python
 code encapsulated in a shell script.
@@ -52,13 +52,14 @@ for more information.
 ## Installation
 
 ```
-cp discus.py /usr/local/bin
-chmod a+rx /usr/local/bin/discus
-cp discusrc /etc
-chmod a+r /etc/discusrc
-gzip -9 discus.1
-cp discus.1.gz /usr/local/man/man1
-chmod a+r /usr/local/man/man1/discus.1.gz
+pkg install discus
+```
+
+or
+
+```
+cd /usr/ports/sysutils/discus
+make install; make clean
 ```
 
 ## Test
