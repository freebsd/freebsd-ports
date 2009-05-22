--- assp.pl.orig	2009-03-17 00:48:11.000000000 -0400
+++ assp.pl	2009-03-17 11:11:45.000000000 -0400
@@ -1,4 +1,4 @@
-#!/usr/bin/perl --
+#!/usr/local/bin/perl --
 #use lib 'path/to/my/perlmods';
 # anti spam smtp proxy
 # (c) John Hanna, John Calvi, Robert Orso, AJ 2004 under the terms of the GPL
@@ -1537,7 +1537,7 @@
 
 [0,0,0,'heading','Server Setup'],
 ['AsAService','Run ASSP as a Windows Service',0,\&checkbox,'','(.*)',undef,'In Windows NT/2000/XP/2003 ASSP can be installed as a service. This setting tells ASSP that this has been done -- it does not install the Windows service for you. Installing ASSP as a service requires several steps which are detailed in the <a href="http://apps.sourceforge.net/mediawiki/assp/index.php?title=Win32">Quick Start for Win32</a> doku page.<br /> <span class="negative"> requires ASSP restart</span>'],
-['AsADaemon','Run ASSP as a Daemon',0,\&checkbox,'','(.*)',undef,'In Linux/BSD/Unix/OSX fork and close file handles. Similar to the command "perl assp.pl &amp;", but better.<br />
+['AsADaemon','Run ASSP as a Daemon',0,\&checkbox,1,'(.*)',undef,'In Linux/BSD/Unix/OSX fork and close file handles. Similar to the command "perl assp.pl &amp;", but better.<br />
   <span class="negative"> requires ASSP restart</span>'],
 ['runAsUser','Run as UID',20,\&textinput,'','(\S*)',undef,'The *nix user name to assume after startup (*nix only).<p><small><i>Examples:</i> assp, nobody</small></p>
   <span class="negative"> requires ASSP restart</span>'],
