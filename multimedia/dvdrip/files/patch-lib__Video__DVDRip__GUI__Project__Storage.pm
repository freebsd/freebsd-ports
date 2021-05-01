--- lib/Video/DVDRip/GUI/Project/Storage.pm.orig	Sat Sep 23 16:06:43 2006
+++ lib/Video/DVDRip/GUI/Project/Storage.pm	Sat Sep 23 16:15:30 2006
@@ -144,6 +144,12 @@
                                             ."Either it's the filename of a physical DVD "
                                             ."device or the path of a full DVD image copy."
                             ),
+                            Gtk2::Ex::FormFactory::Label->new(
+                                label =>
+				    __"Important: On FreeBSD, please mount your DVD disc first\n"
+				     ."(eg 'mount /cdrom'), and then specify the mountpoint above\n"
+				     ."(click \"Choose DVD image directory\" and select '/cdrom').\n"
+                            ),
                         ],
                     ),
                 ],
