--- assp.pl.orig	Tue Mar 15 06:41:24 2005
+++ assp.pl	Wed May 18 11:33:35 2005
@@ -58,7 +58,7 @@
   'The address:port of your message handling system\'s smtp server. For example: 127.0.0.1:125'],
  [AsAService,'As a Service',0,checkbox,'','(\S*)',undef,
   'In Windows 2000 / NT you can run it as a service; requires <a href="http://www.roth.net/perl/Daemon/" rel="external">win32::daemon</a>. Requires start from the service control panel.'],
- [AsADaemon,'As a Daemon',0,checkbox,'','(\S*)',undef,
+ [AsADaemon,'As a Daemon',0,checkbox,1,'(\S*)',undef,
  'In Linux/BSD/Unix/OSX fork and close file handles, kinda like "perl assp.pl &amp;" but better. Requires restart.'],
  [myName,'My Name',20,textinput,'ASSP-nospam','(\S+)',undef,
   'What the program calls itself in the email "received by" header. Usually ASSP-nospam.'],
@@ -355,7 +355,7 @@
   No mail is delivered! For example: assp-notspam'],
  [EmailWhitelist,'Add to Whitelist Address',20,textinput,'assp-white','(.*)',undef,
   'Any mail sent by local/authenticated users to this username will be interpreted as a request to add addresses to the whitelist.<br /> No mail is delivered! For example: assp-white'],
- [EmailFrom,'From Address for Email',20,textinput,'ASSP <>','(.+)',undef,
+ [EmailFrom,'From Address for Email',20,textinput,'ASSP <postmaster@yourdomain.com>','(.+)',undef,
   'Email sent from ASSP acknowledging your submissions will be sent from this address.<br />
   Some mailers don\'t like the default setting. For example: ASSP &lt;&gt; or Mail Administrator
   &lt;mailadmin@mydomain.com&gt;'],
@@ -423,9 +423,9 @@
 'ASSP closes and renames the log file after this number of days. Decimals are ok. For example: 14 or 0.5'],
 
 [0,0,0,heading,'Security'],
- [runAsUser,'Run as UID',20,textinput,'','(\S*)',undef,
+ [runAsUser,'Run as UID',20,textinput,'nobody','(\S*)',undef,
   'The *nix user name to assume after startup: assp or nobody -- requires ASSP restart.'],
- [runAsGroup,'Run as GID',20,textinput,'','(\S*)',undef,
+ [runAsGroup,'Run as GID',20,textinput,'nobody','(\S*)',undef,
   'The *nix group to assume after startup: assp or nogroup -- requires ASSP restart.'],
  [ChangeRoot,'Change Root',60,textinput,'','(.*)',undef,
   'Non-blank means to run in chroot jail in *nix. You need an etc/protocols file to make this work<br />
@@ -4462,4 +4462,4 @@
        dynablock.njabl.org
     );
 }
-1;
\ No newline at end of file
+1;
