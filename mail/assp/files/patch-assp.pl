--- assp.pl.orig	2009-01-25 18:17:42.000000000 -0500
+++ assp.pl	2009-01-25 18:21:31.000000000 -0500
@@ -1,4 +1,4 @@
-#!/usr/bin/perl --
+#!/usr/local/bin/perl
 # perl antispam smtp proxy
 # (c) John Hanna, John Calvi, Robert Orso, AJ 2004 under the terms of the GPL
 # (c) Fritz Borgstedt 2006 under the terms of the GPL
@@ -978,8 +978,8 @@
 ['ScanNP','Scan No Processing Senders',0,\&checkbox,'','(.*)',undef,''],
 ['ScanLocal','Scan Local Senders',0,\&checkbox,'','(.*)',undef,''],
 ['ScanCC','Scan Copied Spam Mails',0,\&checkbox,'','(.*)',undef,''],
-['AvClamdPort','Port or file socket for ClamAV',30,\&textinput,'/tmp/clamd','(\S+)',undef,
- 'A socket specified in the clamav.conf file - LocalSocket. For example /tmp/clamd. If the socket has been setup as a TCP/IP socket (see the TCPSocket option in the clamav.conf file), then specify the TCP socket. For example: 3310 '],
+['AvClamdPort','Port or file socket for ClamAV',30,\&textinput,'/var/run/assp/clamd','(\S+)',undef,
+ 'A socket specified in the clamav.conf file - LocalSocket. For example /var/run/assp/clamd. If the socket has been setup as a TCP/IP socket (see the TCPSocket option in the clamav.conf file), then specify the TCP socket. For example: 3310 '],
 ['ClamAVBytes','ClamAV Bytes',8,\&textinput,60000,'(\d*)',undef,
   'The number of bytes per message that will be submitted for virus scanning. Values of 100000 or larger are not recommended.'],
 ['ClamAVtimeout','ClamAV Timeout',3,\&textinput,10,'(\d*)',undef, 'ClamAV will timeout after this many seconds.<br /> default: 10 seconds.'],
@@ -1159,7 +1159,7 @@
   'A copy of the Analyze-Report will be sent to this address. For example: admin@example.com'],
 ['DoAdditionalAnalyze','Spam and Ham Reports will trigger an additional Analyze Report ','0:NO ADDITIONAL REPORT|1:SEND TO SENDER|2:SEND TO EmailAnalyzeTo|3:SEND TO BOTH',\&listbox,0,'(.*)',undef,
   'Additional Analyze Report will be generated for Spam and Ham Reports. Setting the TO Address accordingly and choosing <b>EmailAnalyzeTo</b> will send the Analyze Report to the admin only.'],
-['EmailFrom','From Address for Reports',40,\&textinput,'<spammaster@yourdomain.com>','(.*@.*)?',undef,
+['EmailFrom','From Address for Reports',40,\&textinput,'<postmaster@yourdomain.com>','(.*@.*)?',undef,
   'Email sent from ASSP acknowledging your submissions will be sent from this address.'],
 ['EmailAllowEqual','Allow \'=\' in Addresses',0,\&checkbox,'1','(.*)',undef,
   'Allow \'=\' in addresses to be whitelisted or redlisted.'],
@@ -1404,7 +1404,7 @@
 
 [0,0,0,'heading','Server Setup'],
 ['AsAService','Run ASSP as a Windows Service',0,\&checkbox,'','(.*)',undef,'In Windows NT/2000/XP/2003 ASSP can be installed as a service. This setting tells ASSP that this has been done -- it does not install the Windows service for you. Installing ASSP as a service requires several steps which are detailed in the <a href="http://www.asspsmtp.org/wiki/Quick_Start_for_Win32">Quick Start for Win32</a> wiki page.<br /> <span class="negative"> requires ASSP restart</span>'],
-['AsADaemon','Run ASSP as a Daemon',0,\&checkbox,'','(.*)',undef,'In Linux/BSD/Unix/OSX fork and close file handles. Similar to the command "perl assp.pl &amp;", but better.<br />
+['AsADaemon','Run ASSP as a Daemon',0,\&checkbox,'1','(.*)',undef,'In Linux/BSD/Unix/OSX fork and close file handles. Similar to the command "perl assp.pl &amp;", but better.<br />
   <span class="negative"> requires ASSP restart</span>'],
 ['runAsUser','Run as UID',20,\&textinput,'','(\S*)',undef,'The *nix user name to assume after startup (*nix only).<p><small><i>Examples:</i> assp, nobody</small></p>
   <span class="negative"> requires ASSP restart</span>'],
