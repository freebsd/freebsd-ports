--- assp.pl.orig	Sun Jun 25 15:35:15 2006
+++ assp.pl	Sun Jun 25 15:43:20 2006
@@ -67,7 +67,7 @@
 loadConfig();
 
 sub loadConfig {
- print "loading config -- base='$base'\n";
+ # print "loading config -- base='$base'\n";
  @Config=(
 [0,0,0,'heading','Network Setup'],
  # except for the heading lines, all config lines have the following:
@@ -86,7 +86,7 @@
   'The address:port of your message handling system\'s smtp server. For example: 127.0.0.1:125'],
  [AsAService,'As a Service',0,checkbox,0,'(.*)',undef,
   'In Windows 2000 / NT you can run it as a service; requires <a href="http://www.roth.net/perl/Daemon/" rel="external">win32::daemon</a>. Requires start from the service control panel.'],
- [AsADaemon,'As a Daemon',0,checkbox,0,'(.*)',undef,
+ [AsADaemon,'As a Daemon',0,checkbox,1,'(.*)',undef,
  'In Linux/BSD/Unix/OSX fork and close file handles, kinda like "perl assp.pl &amp;" but better. Requires restart.'],
  [myName,'My Name',40,textinput,'ASSP.nospam','(\S+)',undef,
   'What the program calls itself in the email "received by" header. Usually ASSP.nospam.'],
@@ -811,7 +811,7 @@
   '<span class="negative"> 0 = no report, 1 = to user, 2 = to TO address, 3 = both</span>'],
 [EmailRedlistTo,'To Address for Redlist-Reports',40,textinput,'','(.+)',undef,
   'Email sent from ASSP acknowledging your submissions will be sent to this address. For example: admin@domain.com'],
- [EmailFrom,'From Address for Reports',40,textinput,'<>','(.+)',undef,
+ [EmailFrom,'From Address for Reports',40,textinput,'<postmaster@yourdomain.com>','(.+)',undef,
   'Email sent from ASSP acknowledging your submissions will be sent from this address.<br />
   Some mailers don\'t like the default setting. For example: ASSP &lt;&gt; or Mail Administrator
   &lt;mailadmin@mydomain.com&gt;
@@ -913,9 +913,9 @@
   '],
 
 [0,0,0,'heading','Security'],
- [runAsUser,'Run as UID',20,textinput,'','(\S*)',undef,
+ [runAsUser,'Run as UID',20,textinput,'nobody','(\S*)',undef,
   'The *nix user name to assume after startup: assp or nobody -- requires ASSP restart.'],
- [runAsGroup,'Run as GID',20,textinput,'','(\S*)',undef,
+ [runAsGroup,'Run as GID',20,textinput,'nobody','(\S*)',undef,
   'The *nix group to assume after startup: assp or nogroup -- requires ASSP restart.'],
  [ChangeRoot,'Change Root',40,textinput,'','(.*)',undef,
   'Non-blank means to run in chroot jail in *nix. You need an etc/protocols file to make this work<br />
@@ -7865,6 +7865,7 @@
  @PossibleOptionFiles2=();
  foreach (@Config) {
   if($_->[6] eq 'ConfigMakeRe') {
+   $silent=1 if($AsADaemon);
    ${$_->[0]}=optionList(${$_->[0]},$_->[0]);
    push(@PossibleOptionFiles,$_->[0]);
   } elsif($_->[6] eq 'ConfigCompileRe') {
