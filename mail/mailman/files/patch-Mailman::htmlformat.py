--- Mailman/htmlformat.py.orig	Wed Apr  3 00:28:59 2002
+++ Mailman/htmlformat.py	Thu Apr  4 11:28:51 2002
@@ -503,15 +503,17 @@
 # These are the URLs which the image logos link to.  The Mailman home page now
 # points at the gnu.org site instead of the www.list.org mirror.
 #
-from mm_cfg import MAILMAN_URL
+from mm_cfg import MAILMAN_URL, LOGO_OS
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
@@ -525,12 +527,21 @@
                  logo(PYTHON_POWERED)
         gnulink = '<img src="%s" alt="GNU\'s Not Unix" border=0>' % \
                   logo(GNU_HEAD)
-        t.AddRow([mmlink, pylink, gnulink])
+        freebsdlink = '<img src="%s" alt="Powered by FreeBSD" border=0>' % \
+                      logo(FREEBSD_POWERED)
+        if LOGO_OS == 'FreeBSD':
+	    t.AddRow([mmlink, pylink, freebsdlink])
+        else:
+	    t.AddRow([mmlink, pylink, gnulink])
     else:
         # use only textual links
         mmlink = Link(MAILMAN_URL,
                       'Delivered by Mailman<br>version %s' % mm_cfg.VERSION)
         pylink = Link(PYTHON_URL, 'Python Powered')
         gnulink = Link(GNU_URL, "Gnu's Not Unix")
-        t.AddRow([mmlink, pylink, gnulink])
+        freebsdlink = Link(FREEBSD_URL, "Powered by FreeBSD")
+        if LOGO_OS == 'FreeBSD':
+            t.AddRow([mmlink, pylink, freebsdlink])
+        else:
+            t.AddRow([mmlink, pylink, gnulink])
     return t
