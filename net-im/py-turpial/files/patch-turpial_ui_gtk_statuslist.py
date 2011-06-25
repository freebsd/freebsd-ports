--- turpial/ui/gtk/statuslist.py.orig	2011-05-08 05:01:09.000000000 +0200
+++ turpial/ui/gtk/statuslist.py	2011-06-12 19:55:15.000000000 +0200
@@ -5,6 +5,7 @@
 # Author: Wil Alvarez (aka Satanas)
 # Jun 25, 2009
 
+import sys
 import gtk
 import pango
 import gobject
@@ -81,14 +82,14 @@
         if len(hashtags) == 0: return text
         
         for h in hashtags:
-            torep = '%s' % h
+            torep = u'%s' % h
             try:
-                cad = '<span foreground="%s">%s</span>' % (
+                cad = u'<span foreground="%s">%s</span>' % (
                     self.mainwin.link_color, h
                 )
                 text = text.replace(torep, cad)
             except:
-                log.debug('Problemas para resaltar el hashtag: %s' % h)
+                log.debug(u'Problemas para resaltar el hashtag: %s' % h)
         return text
         
     def __highlight_groups(self, text):
@@ -99,14 +100,14 @@
         if len(groups) == 0: return text
         
         for h in groups:
-            torep = '%s' % h
+            torep = u'%s' % h
             try:
-                cad = '<span foreground="%s">%s</span>' % (
+                cad = u'<span foreground="%s">%s</span>' % (
                     self.mainwin.link_color, h
                 )
                 text = text.replace(torep, cad)
             except:
-                log.debug('Problemas para resaltar el grupo: %s' % h)
+                log.debug(u'Problemas para resaltar el grupo: %s' % h)
         return text
         
     def __highlight_mentions(self, text):
@@ -117,8 +118,8 @@
         for h in mentions:
             if len(h) == 1: 
                 continue
-            torep = '%s' % h
-            cad = '<span foreground="%s">%s</span>' % (
+            torep = u'%s' % h
+            cad = u'<span foreground="%s">%s</span>' % (
                 self.mainwin.link_color, h
             )
             text = text.replace(torep, cad)
@@ -128,7 +129,7 @@
         #if len(urls) == 0: return text
         
         for u in urls:
-            cad = '<span foreground="%s">%s</span>' % (
+            cad = u'<span foreground="%s">%s</span>' % (
                 self.mainwin.link_color, u
             )
             text = text.replace(u, cad)
@@ -180,8 +181,17 @@
         amarillo = gtk.gdk.Color(253 * 257, 255 * 257, 229 * 257)
         naranja = gtk.gdk.Color(255 * 257, 240 * 257, 229 * 257)
         '''
-        me = '@'+self.mainwin.me.lower()
-        mention = True if msg.lower().find(me) >= 0 else False
+        me = unichr(64) + self.mainwin.me.lower()
+        if sys.getfilesystemencoding() != 'UTF-8':
+            if msg.startswith(me):
+                mention = True
+            else:
+                mention = False 
+        else:
+            if msg.lower().startswith(me):
+                mention = True
+            else:
+                mention = False 
         
         if new:
             color = self.mainwin.get_gdk_color_from_base('unread')
@@ -206,15 +216,15 @@
         pango_twt = util.unescape_text(status.text)
         pango_twt = gobject.markup_escape_text(pango_twt)
         
-        user = '<span size="9000" foreground="%s"><b>%s</b></span> ' % (
+        user = u'<span size="9000" foreground="%s"><b>%s</b></span> ' % (
             self.mainwin.link_color, status.username
         )
-        pango_twt = '<span size="9000">%s</span>' % pango_twt
+        pango_twt = u'<span size="9000">%s</span>' % pango_twt
         pango_twt = self.__highlight_hashtags(pango_twt)
         pango_twt = self.__highlight_groups(pango_twt)
         pango_twt = self.__highlight_mentions(pango_twt)
         pango_twt = self.__highlight_urls(urls, pango_twt)
-        pango_twt += '<span size="2000">\n\n</span>'
+        pango_twt += u'<span size="2000">\n\n</span>'
         
         try:
             pango_twt = user + pango_twt
@@ -227,17 +237,17 @@
                 except UnicodeDecodeError:
                     invalid_chars.append(c)
                     clear_txt += '?'
-            log.debug('Problema con caracteres inválidos en un tweet: %s' % invalid_chars)
+            log.debug(u'Problema con caracteres inválidos en un tweet: %s' % invalid_chars)
             pango_twt = clear_txt
         
-        footer = '<span size="small" foreground="#999">%s' % status.datetime
+        footer = u'<span size="small" foreground="#999">%s' % status.datetime
         if status.source: 
-            footer += ' %s %s' % (_('from'), status.source)
+            footer += u' %s %s' % (_('from'), status.source)
         if status.in_reply_to_user:
-            footer += ' %s %s' % (_('in reply to'), status.in_reply_to_user)
+            footer += u' %s %s' % (_('in reply to'), status.in_reply_to_user)
         if status.retweet_by:
-            footer += '\n%s %s' % (_('Retweeted by'), status.retweet_by)
-        footer += '</span>'
+            footer += u'\n%s %s' % (_('Retweeted by'), status.retweet_by)
+        footer += u'</span>'
         pango_twt += footer
         
         return pango_twt
