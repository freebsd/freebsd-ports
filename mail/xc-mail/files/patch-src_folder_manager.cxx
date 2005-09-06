--- src/folder_manager.cxx.orig	Wed Aug 17 10:16:03 2005
+++ src/folder_manager.cxx	Wed Aug 17 10:18:45 2005
@@ -474,54 +474,54 @@
 	  bg->Center();
 	  bg->XDistance(4);
 	   html_gadget *helptxt=new html_gadget;
-	   helptxt->Text("<body>The folder management is divided in 2 areas:
-<ul><li>the folder controller
-<li>the folder editor
-</ul>
-<p>
-The <b>folder controllers</b> allows to create, rename, delete, move and copy
-real folders from one IO to another. IOs are the different places for
-folders - like your home directory (~/Mail), the folder archive (~/Mail/ARCHIVE).<p>
-Each IO normally allows only unique folder names - ie they are stored in files. But 
-different IOs may have the same folder names.
-<p>
-<b>To move mail from a folder (eg received) into the folder archiv do this:</b>
-<ol>
-<li>select your mail directory in the left popup list (..../Mail/)
-<li>select the ARCHIV directory in the right popup list (..../Mail/ARCHIV/)
-<li>select the folder you want to archiv in the left listbox (eg received)
-<li>press one of the buttons 'Copy' to copy the folder, 'Move' to copy the folder and remove the source or 'Move mail' to copy the folder and clear the source (the best choice here)
-</ol>
-<p>
-The <b>folder editor</b> handles the so called 'virtual folders' or
-vfolders. To use this you have to enable the 'advanced vfolder concept'
-in the main preferences.
-<p>
-Every real folder  belongs to one or more virtual folders
-and every vertiual folder has one or more real folders in it.<p>
-The idea is to have only a handfull visible folders in the mail window (this only 
-shows the virtual folders) but they belong to different IOs - eg. all your
-POP3 servers may write their mails in different real folders but you will see 
-all mails in one vfolder - but you can still access the real folders of each 
-POP3 server if you also create a virtual folders for this.<p>
-
-An image that might help you:
-<pre>
-  +--------+             +--------+            +--------+
-  |vfolder1|             |vfolder2|      +-----|vfolder3|
-  +--------+             +--------+     /      +--------+
-       |                      |        /           |  
-  +---------+     +--------------------+    +-------------+
-  |~/Mail/f1|     |/var/spool/mail/user|    |.../ARCHIV/f2|
-  +---------+     +--------------------+    +-------------+
-</pre>
-<dl>
-<dd>vfolder1 uses ~/Mail/f1,
-<dd>vfolder2 uses /var/spool/mail/user and
-<dd>vfolder3 uses /var/spool/mail/user AND .../ARCHIV/f2.
-</dl>
-<p>
-</body>");
+	   helptxt->Text("<body>The folder management is divided in 2 areas:"
+"<ul><li>the folder controller"
+"<li>the folder editor"
+"</ul>"
+"<p>"
+"The <b>folder controllers</b> allows to create, rename, delete, move and copy"
+"real folders from one IO to another. IOs are the different places for"
+"folders - like your home directory (~/Mail), the folder archive (~/Mail/ARCHIVE).<p>"
+"Each IO normally allows only unique folder names - ie they are stored in files. But "
+"different IOs may have the same folder names."
+"<p>"
+"<b>To move mail from a folder (eg received) into the folder archiv do this:</b>"
+"<ol>"
+"<li>select your mail directory in the left popup list (..../Mail/)"
+"<li>select the ARCHIV directory in the right popup list (..../Mail/ARCHIV/)"
+"<li>select the folder you want to archiv in the left listbox (eg received)"
+"<li>press one of the buttons 'Copy' to copy the folder, 'Move' to copy the folder and remove the source or 'Move mail' to copy the folder and clear the source (the best choice here)"
+"</ol>"
+"<p>"
+"The <b>folder editor</b> handles the so called 'virtual folders' or"
+"vfolders. To use this you have to enable the 'advanced vfolder concept'"
+"in the main preferences."
+"<p>"
+"Every real folder  belongs to one or more virtual folders"
+"and every vertiual folder has one or more real folders in it.<p>"
+"The idea is to have only a handfull visible folders in the mail window (this only "
+"shows the virtual folders) but they belong to different IOs - eg. all your"
+"POP3 servers may write their mails in different real folders but you will see "
+"all mails in one vfolder - but you can still access the real folders of each "
+"POP3 server if you also create a virtual folders for this.<p>"
+""
+"An image that might help you:"
+"<pre>"
+"  +--------+             +--------+            +--------+"
+"  |vfolder1|             |vfolder2|      +-----|vfolder3|"
+"  +--------+             +--------+     /      +--------+"
+"       |                      |        /           |  "
+"  +---------+     +--------------------+    +-------------+"
+"  |~/Mail/f1|     |/var/spool/mail/user|    |.../ARCHIV/f2|"
+"  +---------+     +--------------------+    +-------------+"
+"</pre>"
+"<dl>"
+"<dd>vfolder1 uses ~/Mail/f1,"
+"<dd>vfolder2 uses /var/spool/mail/user and"
+"<dd>vfolder3 uses /var/spool/mail/user AND .../ARCHIV/f2."
+"</dl>"
+"<p>"
+"</body>");
 	  bg->Add(helptxt);
 	 cd->Add("Information/Short help",bg);
 
