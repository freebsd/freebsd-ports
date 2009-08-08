--- assp.pl.orig	2009-05-22 03:05:20.000000000 -0400
+++ assp.pl	2009-08-06 11:44:01.000000000 -0400
@@ -1,4 +1,4 @@
-#!/usr/bin/perl --
+#!/usr/local/bin/perl --
 #use lib 'path/to/my/perlmods';
 # anti spam smtp proxy
 # (c) John Hanna, John Calvi, Robert Orso, AJ 2004 under the terms of the GPL
@@ -1016,8 +1016,7 @@
 ['ScanNP','Scan NoProcessing Messages',0,\&checkbox,'','(.*)',undef,''],
 ['ScanLocal','Scan Local Senders',0,\&checkbox,'','(.*)',undef,''],
 ['ScanCC','Scan Copied Spam Mails',0,\&checkbox,'','(.*)',undef,''],
-['AvError','Reply Code to Refuse Infected Messages',80,\&textinput,'554
-5.7.1 Mail appears infected with INFECTION.','([25]\d\d .*)',undef,'Reply
+['AvError','Reply Code to Refuse Infected Messages',80,\&textinput,'554 5.7.1 Mail appears infected with INFECTION.','([25]\d\d .*)',undef,'Reply
 code to refuse infected messages. The string $infection is replaced with
 the name of the detected virus.<br />  For example: 554 5.7.1 Mail appears
 infected with INFECTION -- disinfect and resend.'],
@@ -1654,11 +1653,11 @@
 
 [0,0,0,'heading','Server Setup'],
 ['AsAService','Run ASSP as a Windows Service',0,\&checkbox,'','(.*)',undef,'In Windows NT/2000/XP/2003 ASSP can be installed as a service. This setting tells ASSP that this has been done -- it does not install the Windows service for you. Installing ASSP as a service requires several steps which are detailed in the <a href="http://apps.sourceforge.net/mediawiki/assp/index.php?title=Win32">Quick Start for Win32</a> doku page.<br /> <span class="negative"> requires ASSP restart</span>'],
-['AsADaemon','Run ASSP as a Daemon',0,\&checkbox,'','(.*)',undef,'In Linux/BSD/Unix/OSX fork and close file handles. Similar to the command "perl assp.pl &amp;", but better.<br />
+['AsADaemon','Run ASSP as a Daemon',0,\&checkbox,1,'(.*)',undef,'In Linux/BSD/Unix/OSX fork and close file handles. Similar to the command "perl assp.pl &amp;", but better.<br />
   <span class="negative"> requires ASSP restart</span>'],
-['runAsUser','Run as UID',20,\&textinput,'','(\S*)',undef,'The *nix user name to assume after startup (*nix only).<p><small><i>Examples:</i> assp, nobody</small></p>
+['runAsUser','Run as UID',20,\&textinput,'assp','(\S*)',undef,'The *nix user name to assume after startup (*nix only).<p><small><i>Examples:</i> assp, nobody</small></p>
   <span class="negative"> requires ASSP restart</span>'],
-['runAsGroup','Run as GID',20,\&textinput,'','(\S*)',undef,'The *nix group to assume after startup (*nix only).<p><small><i>Examples:</i> assp, nobody</small></p>
+['runAsGroup','Run as GID',20,\&textinput,'assp','(\S*)',undef,'The *nix group to assume after startup (*nix only).<p><small><i>Examples:</i> assp, nobody</small></p>
   <span class="negative"> requires ASSP restart</span>'],
 ['ChangeRoot','Change Root',40,\&textinput,'','(.*)',undef,'The new root directory to which ASSP should chroot (*nix only). If blank, no chroot jail will be used. Note: if you use this feature, be sure to copy or link the etc/protocols file in your chroot jail.<br />
   <span class="negative"> requires ASSP restart</span>'],
