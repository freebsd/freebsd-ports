--- assp.pl.orig	2008-08-02 22:00:47.000000000 -0400
+++ assp.pl	2008-08-02 22:03:58.000000000 -0400
@@ -1,4 +1,4 @@
-#!/usr/bin/perl --
+#!/usr/local/bin/perl
 #
 # perl antispam smtp proxy
 # (c) John Hanna, John Calvi, Robert Orso, AJ 2004 under the terms of the GPL
@@ -817,8 +817,8 @@
 ['ScanWL','Scan Whitelisted Senders',0,\&checkbox,0,'([01]?)',undef,''],
 ['ScanNP','Scan No Processing Senders',0,\&checkbox,0,'([01]?)',undef,''],
 ['ScanLocal','Scan Local Senders',0,\&checkbox,0,'([01]?)',undef,''],
-['AvClamdPort','Port or file socket for ClamAV',20,\&textinput,'/tmp/clamd','(\S+)',undef,
-  'A socket specified in the clamav.conf file - LocalSocket. For example /tmp/clamd. If the socket has been setup as a TCP/IP socket (see the TCPSocket option in the clamav.conf file), then specify the TCP socket. For example 3310 '],
+['AvClamdPort','Port or file socket for ClamAV',20,\&textinput,'/var/run/assp/clamd','(\S+)',undef,
+  'A socket specified in the clamav.conf file - LocalSocket. For example /var/run/assp/clamd. If the socket has been setup as a TCP/IP socket (see the TCPSocket option in the clamav.conf file), then specify the TCP socket. For example 3310 '],
 ['AvError','Reply Message to Refuse Infected E<!--get rid of google autofill-->mail',80,\&textinput,'554 5.7.1 Mail appears infected with \'$infection\'.','(5\d\d .*)',undef,
   'Reply message to refuse infected mail. The string $infection is replaced with the name of the detected virus.<br />
   For example: 554 5.7.1 Mail appears infected with \'$infection\' -- disinfect and resend.'],
@@ -973,7 +973,7 @@
   '<span class="negative"> 0 = no report, 1 = to SENDER, 2 = to TO address (below), 3 = BOTH</span>'],
 ['EmailRedlistTo','To Address for Redlist-Reports',40,\&textinput,'','(.+)',undef,
   'Email sent from ASSP acknowledging your submissions will be sent to this address. For example: admin@domain.com'],
-['EmailFrom','From Address for Reports',40,\&textinput,'<spammaster@yourdomain.com>','(.+)',undef,
+['EmailFrom','From Address for Reports',40,\&textinput,'<postmaster@yourdomain.com>','(.+)',undef,
   'Email sent from ASSP acknowledging your submissions will be sent from this address.'],
 ['NoHaiku','Legacy: Don\'t reply to messages to the Email Interface',0,\&checkbox,0,'([01]?)',undef,
   'Check this option to suppress email reports for spam and not-spam reports, whitelist and redlist additions/deletions via the email interface.<br /><hr />
@@ -1166,7 +1166,7 @@
 [0,0,0,'heading','Server Setup'],
 ['AsAService','Run ASSP as a Windows Service**',0,\&checkbox,0,'([01]?)',undef,
   'In Windows NT/2000/XP/2003 ASSP can be installed as a service. This setting tells ASSP that this has been done -- it does not install the Windows service for you. Installing ASSP as a service requires several steps which are detailed in the <a href="http://www.asspsmtp.org/wiki/Quick_Start_for_Win32">Quick Start for Win32</a> wiki page.'],
-['AsADaemon','Run ASSP as a Daemon**',0,\&checkbox,0,'([01]?)',undef,
+['AsADaemon','Run ASSP as a Daemon**',0,\&checkbox,1,'([01]?)',undef,
  'In Linux/BSD/Unix/OSX fork and close file handles. Similar to the command "perl assp.pl &amp;", but better.'],
 ['runAsUser','Run as UID**',20,\&textinput,'','(\S*)',undef,
   'The *nix user name to assume after startup (*nix only).<p><small><i>Examples:</i> assp, nobody</small></p>'],
