--- gnomeosd/capplet.py.orig	Wed Aug 23 03:44:56 2006
+++ gnomeosd/capplet.py	Wed Aug 23 03:45:29 2006
@@ -150,7 +150,6 @@
 def main():
     gettext.install("gnome-osd", os.path.join(gnome_osd_conf.datadir, "locale"))
     locale.setlocale(locale.LC_ALL, '')
-    locale.bind_textdomain_codeset('gnome-osd','UTF-8')
     gettext.bind_textdomain_codeset('gnome-osd','UTF-8')
     gnome.program_init("gnome-osd-properties", gnome_osd_conf.VERSION)
 
