
$FreeBSD$

--- edit.py.orig	Fri May 11 16:44:12 2001
+++ edit.py	Fri May 11 21:01:18 2001
@@ -350,9 +350,9 @@
             for a in self.prefs.accounts.keys():
                 username, emailaddr, sigfile, replyaddr = self.prefs.accounts[a]
                 if emailaddr != '':
-                    ownaddrs.append(emailaddr)
+                    ownaddrs.append(emailaddr.lower())
                 if replyaddr != '':
-                    ownaddrs.append(replyaddr)
+                    ownaddrs.append(replyaddr.lower())
 
             # Get all the target addresses
             to = rfc822.AddressList(rt) + \
@@ -361,12 +361,12 @@
             tostr = []
 
             for i in to.addresslist:
-                if i[1] not in ownaddrs and i[1] != None:
+                if i[1].lower() not in ownaddrs and i[1] != None:
                     tostr.append(i[1])
             ccstr = []
 
             for i in cc.addresslist:
-                if i[1] not in ownaddrs and i[1] != None:
+                if i[1].lower() not in ownaddrs and i[1] != None:
                     ccstr.append(i[1])
                     
             self.e1.set_text(mimify.mime_decode_header(string.join(tostr, ', ')))
@@ -444,9 +444,8 @@
     ##
     ##
     def create_menu(self):
-        from prefix import PYGMY_PREFIX
+        from prefix import PYGMY_ICONDIR
         import os.path
-        icondir = os.path.join(PYGMY_PREFIX, "share/pixmaps/pygmy")
 
         file_menu = [
             UIINFO_ITEM_STOCK('Insert File', None, self.insert_file, STOCK_MENU_OPEN),
@@ -470,7 +469,7 @@
                               STOCK_MENU_TIMER),
             UIINFO_SEPARATOR,
             UIINFO_ITEM_STOCK('Security', None, self.privacy_dialog,
-                              icondir+"/encrypt.xpm"), 
+                              PYGMY_ICONDIR+"/encrypt.xpm"), 
             UIINFO_SEPARATOR,
             UIINFO_ITEM_STOCK('Add Signature', None, self.add_sig,
                               STOCK_MENU_BLANK), 
