--- lanbrowsing/kcmlisa/setupwizard.cpp.orig	Fri Jun 25 11:10:25 2004
+++ lanbrowsing/kcmlisa/setupwizard.cpp	Sun Aug 29 18:49:41 2004
@@ -349,11 +349,11 @@
    m_finalPage=new QVBox(this);
    QLabel *info=new QLabel(i18n("<br>Your LAN browsing has been successfully set up.<br><br>"
                                 "Make sure that the LISa server is started during the "
-                                "boot process. How this is done depends on your "
-                                "distribution and OS. Usually you have to insert it somewhere "
-                                "in a boot script under <code>/etc</code>.<br>"
-                                "Start the LISa server as root and without any command line options.<br>"
-                                "The config file will now be saved to <code>/etc/lisarc</code>.<br>"
+                                "boot process. The kdenetwork port has installed "
+                                "a startup-script (lisa.sh) into <code>/usr/local/etc/rc.d</code>. "
+                                "To activate lisa, put lisa_enable=\"YES\" into your rc.conf.<br> "
+                                "<br>"
+                                "The config file will now be saved to <code>/usr/local/etc/lisarc</code>.<br>"
                                 "To test the server, try <code>lan:/</code> in Konqueror.<br><br>"
                                 "If you have problems or suggestions, visit http://lisa-home.sourceforge.net."),m_finalPage);
    info->setTextFormat(Qt::RichText);
