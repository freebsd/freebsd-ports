--- src/settings_wizzard.cxx.orig	Wed Aug 17 10:23:12 2005
+++ src/settings_wizzard.cxx	Wed Aug 17 10:24:36 2005
@@ -768,51 +768,51 @@
 	 txt->Text(PROGRAMNAME" note\n");
 	ogp->Add(txt);
 	 html_gadget *helptxt=new html_gadget;
-	 helptxt->Text("<body>
-XCmail has a special kind of mail folder management which
-allows more flexibility:<p>
-<center>Virtual folders</center><p>
-A virtual folder (vfolder) may contain one or more real folders.
-Real folders are for example the files on your hard disk (as you
-might know it from other mail programs).<p>
-
-Normally easy vfolder has only one real folder in it which has the same
-name (filename) and you don't worry about it (if you want to use vfolders
-you have to enable this function in the general preferences).<p>
-
-However XCmail offers different places where and how to store folders
-and you might hide this behind a vfolder. This different places are for
-example:
-<dl>
-<dd>the Inbox
-<dd>a POP3 Inbox
-<dd>a 'normal' folder
-<dd>a compressed folder
-</dl><p>
-This places are called IOs. A vfolder may contain as many real folders
-from every IO as you want. But a typicall usage could be:
-<dl>
-<dd>a vfolder with all POP3 inboxes - so every POP3 server has an own
-real folder where to story the mail but one vfolder for the user to
-read and manage it
-<dd>a vfolder with a normal folder and an archived compressed folder
-</dl><p>
-Finally there are different type of vfolders:
-<ul>
-<li>Inbox: XCmail checks this folders for new mail and will alert you
-<li>Outbox: Sent mails could be stored in an outbox vfolder (which one
-has to be setup in the network and transfer prefs) and if you open an
-Outbox vfolder the recipient not the sender is shown in the mail list
-<li>Trash: deleted mail is moved into the trash vfolder before it is
-really removed - the first trash vfolder of each IO is used
-<li>Received: this is not a really special vfolder - if you have enabled
-to move mail into the received folder (general prefs/misc) the first
-found received vfolder of each IO is used
-<li>Folder: a 'normal' vfolder
-</ul><p>
-For more details on vfolders read the manual and check the folder manager
-window ('Special' pull down menu).
-</body>");
+	 helptxt->Text("<body>"
+"XCmail has a special kind of mail folder management which"
+"allows more flexibility:<p>"
+"<center>Virtual folders</center><p>"
+"A virtual folder (vfolder) may contain one or more real folders."
+"Real folders are for example the files on your hard disk (as you"
+"might know it from other mail programs).<p>"
+""
+"Normally easy vfolder has only one real folder in it which has the same"
+"name (filename) and you don't worry about it (if you want to use vfolders"
+"you have to enable this function in the general preferences).<p>"
+""
+"However XCmail offers different places where and how to store folders"
+"and you might hide this behind a vfolder. This different places are for"
+"example:"
+"<dl>"
+"<dd>the Inbox"
+"<dd>a POP3 Inbox"
+"<dd>a 'normal' folder"
+"<dd>a compressed folder"
+"</dl><p>"
+"This places are called IOs. A vfolder may contain as many real folders"
+"from every IO as you want. But a typicall usage could be:"
+"<dl>"
+"<dd>a vfolder with all POP3 inboxes - so every POP3 server has an own"
+"real folder where to story the mail but one vfolder for the user to"
+"read and manage it"
+"<dd>a vfolder with a normal folder and an archived compressed folder"
+"</dl><p>"
+"Finally there are different type of vfolders:"
+"<ul>"
+"<li>Inbox: XCmail checks this folders for new mail and will alert you"
+"<li>Outbox: Sent mails could be stored in an outbox vfolder (which one"
+"has to be setup in the network and transfer prefs) and if you open an"
+"Outbox vfolder the recipient not the sender is shown in the mail list"
+"<li>Trash: deleted mail is moved into the trash vfolder before it is"
+"really removed - the first trash vfolder of each IO is used"
+"<li>Received: this is not a really special vfolder - if you have enabled"
+"to move mail into the received folder (general prefs/misc) the first"
+"found received vfolder of each IO is used"
+"<li>Folder: a 'normal' vfolder"
+"</ul><p>"
+"For more details on vfolders read the manual and check the folder manager"
+"window ('Special' pull down menu)."
+"</body>");
 	ogp->Add(helptxt);
 
 
