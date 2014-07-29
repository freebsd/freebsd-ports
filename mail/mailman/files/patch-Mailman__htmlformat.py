--- Mailman/htmlformat.py.orig	Sun Apr 21 17:27:02 2002
+++ Mailman/htmlformat.py	Fri Sep 27 16:17:48 2002
@@ -600,12 +600,14 @@
 from mm_cfg import MAILMAN_URL
 PYTHON_URL  = 'http://www.python.org/'
 GNU_URL     = 'http://www.gnu.org/'
+FREEBSD_URL = 'http://www.freebsd.org/'
 
 # The names of the image logo files.  These are concatentated onto
 # mm_cfg.IMAGE_LOGOS (not urljoined).
 DELIVERED_BY = 'mailman.jpg'
 PYTHON_POWERED = 'PythonPowered.png'
 GNU_HEAD = 'gnu-head-tiny.jpg'
+FREEBSD_POWERED = 'powerlogo.gif'
 
 
 def MailmanLogo():
@@ -617,17 +619,17 @@
                  '<br>version %s' % (logo(DELIVERED_BY), mm_cfg.VERSION)
         pylink = '<img src="%s" alt="Python Powered" border=0>' % \
                  logo(PYTHON_POWERED)
-        gnulink = '<img src="%s" alt="GNU\'s Not Unix" border=0>' % \
-                  logo(GNU_HEAD)
-        t.AddRow([mmlink, pylink, gnulink])
+        freebsdlink = '<img src="%s" alt="Powered by FreeBSD" border=0>' % \
+                 logo(FREEBSD_POWERED)
+        t.AddRow([mmlink, pylink, freebsdlink])
     else:
         # use only textual links
         version = mm_cfg.VERSION
         mmlink = Link(MAILMAN_URL,
                       _('Delivered by Mailman<br>version %(version)s'))
         pylink = Link(PYTHON_URL, _('Python Powered'))
-        gnulink = Link(GNU_URL, _("Gnu's Not Unix"))
-        t.AddRow([mmlink, pylink, gnulink])
+        freebsdlink = Link(FREEBSD_URL, "Powered by FreeBSD")
+        t.AddRow([mmlink, pylink, freebsdlink])
     return t
 
 
