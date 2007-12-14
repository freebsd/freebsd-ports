--- assp.pl.orig	Thu Nov  1 16:37:53 2007
+++ assp.pl	Thu Nov  1 16:40:38 2007
@@ -1,4 +1,4 @@
-#!/usr/bin/perl
+#!/usr/local/bin/perl
 
 use File::Copy;
 use Encode;
@@ -844,8 +844,8 @@
 [ScanWL,'Scan Whitelisted Senders',0,checkbox,0,'([01]?)',undef,''],
 [ScanNP,'Scan No Processing Senders',0,checkbox,0,'([01]?)',undef,''],
 [ScanLocal,'Scan Local Senders',0,checkbox,0,'([01]?)',undef,''],
-[AvClamdPort,'Port or file socket for ClamAV',20,textinput,'/tmp/clamd','(\S+)',undef,
-  'A socket specified in the clamav.conf file - LocalSocket. For example /tmp/clamd. If the socket has been setup as a TCP/IP socket (see the TCPSocket option in the clamav.conf file), then specify the TCP socket. For example 3310 '],
+[AvClamdPort,'Port or file socket for ClamAV',20,textinput,'/var/run/clamav/clamd','(\S+)',undef,
+  'A socket specified in the clamav.conf file - LocalSocket. For example /var/run/clamav/clamd. If the socket has been setup as a TCP/IP socket (see the TCPSocket option in the clamav.conf file), then specify the TCP socket. For example 3310 '],
 [AvError,'Reply Message to Refuse Infected E<!--get rid of google autofill-->mail',80,textinput,'554 5.7.1 Mail appears infected with \'$infection\'.','(5\d\d .*)',undef,
   'Reply message to refuse infected mail. The string $infection is replaced with the name of the detected virus.<br />
   For example: 554 5.7.1 Mail appears infected with \'$infection\' -- disinfect and resend.'],
@@ -1003,7 +1003,7 @@
   '<span class="negative"> 0 = no report, 1 = to SENDER, 2 = to TO address (below), 3 = BOTH</span>'],
 [EmailRedlistTo,'To Address for Redlist-Reports',40,textinput,'','(.+)',undef,
   'Email sent from ASSP acknowledging your submissions will be sent to this address. For example: admin@domain.com'],
-[EmailFrom,'From Address for Reports',40,textinput,'<spammaster@yourdomain.com>','(.+)',undef,
+[EmailFrom,'From Address for Reports',40,textinput,'<postmaster@yourdomain.com>','(.+)',undef,
   'Email sent from ASSP acknowledging your submissions will be sent from this address.'],
 
 
@@ -1214,7 +1214,7 @@
 [0,0,0,'heading','Server Setup'],
 [AsAService,'Run ASSP as a Windows Service**',0,checkbox,0,'([01]?)',undef,
   'In Windows NT/2000/XP/2003 ASSP can be installed as a service. This setting tells ASSP that this has been done -- it does not install the Windows service for you. Installing ASSP as a service requires several steps which are detailed in the <a href="http://www.asspsmtp.org/wiki/Quick_Start_for_Win32">Quick Start for Win32</a> wiki page.'],
-[AsADaemon,'Run ASSP as a Daemon**',0,checkbox,0,'([01]?)',undef,
+[AsADaemon,'Run ASSP as a Daemon**',0,checkbox,1,'([01]?)',undef,
  'In Linux/BSD/Unix/OSX fork and close file handles. Similar to the command "perl assp.pl &amp;", but better.'],
 [runAsUser,'Run as UID**',20,textinput,'','(\S*)',undef,
   'The *nix user name to assume after startup (*nix only).<p><small><i>Examples:</i> assp, nobody</small></p>'],
