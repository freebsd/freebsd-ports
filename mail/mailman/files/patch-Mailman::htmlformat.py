--- Mailman/htmlformat.py.orig	Tue Sep 12 06:02:36 2000
+++ Mailman/htmlformat.py	Tue Feb 19 17:12:53 2002
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
@@ -529,18 +531,34 @@
         gnulink = Link(GNU_URL,
                        '<img src="%s" alt="GNU\'s Not Unix" border=0>' %
                        logo(GNU_HEAD))
-        text = Container(Link(MAILMAN_URL, 'Mailman home page'),
-                         '<br>',
-                         Link(PYTHON_URL, 'Python home page'),
-                         '<br>',
-                         Link(GNU_URL, 'GNU home page'),
-                         )
-        t.AddRow([mmlink, pylink, gnulink, text])
+        freebsdlink = Link(FREEBSD_URL,
+                           '<img src="%s" alt="Powered by FreeBSD" border=0>' %
+                           logo(FREEBSD_POWERED))
+        if LOGO_OS == 'FreeBSD':
+            text = Container(Link(MAILMAN_URL, 'Mailman home page'),
+                             '<br>',
+                             Link(PYTHON_URL, 'Python home page'),
+                             '<br>',
+                             Link(FREEBSD_URL, 'FreeBSD home page'),
+                             )
+            t.AddRow([mmlink, pylink, freebsdlink, text])
+        else:
+            text = Container(Link(MAILMAN_URL, 'Mailman home page'),
+                             '<br>',
+                             Link(PYTHON_URL, 'Python home page'),
+                             '<br>',
+                             Link(GNU_URL, 'GNU home page'),
+                             )
+            t.AddRow([mmlink, pylink, gnulink, text])
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
