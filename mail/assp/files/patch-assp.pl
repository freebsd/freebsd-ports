--- assp.pl.orig	2013-08-12 14:12:11.000000000 -0500
+++ assp.pl	2013-08-12 14:15:10.000000000 -0500
@@ -2758,15 +2758,15 @@
  'Set the characterset/codepage for the maillog output to your local needs. Best on non Windows systems is "utf8" if available or "System Default" - no conversion. On Windows systems set it to your local codepage or UTF-8 (chcp 65001). To display nonASCII characters in the subject line and maillog files names setup decodeMIME2UTF8 .'],
 ['decodeMIME2UTF8','Decode MIME Words To UTF-8',1,\&checkbox,'1','(.*)',undef,'If selected, ASSP decodes MIME encoded words to UTF8. This enables support for national languages to be used in Bombs , Scripts , Spamdb , Logging. If not selected, only US-ASCII characters will be used for this functions. This requires an installed Email::MIME module in PERL.'],
 ['AsAService','Run ASSP as a Windows Service',0,\&checkbox,'','(.*)',undef,'In Windows NT/2000/XP/2003 ASSP can be installed as a service. This setting tells ASSP that this has been done -- it does not install the Windows service for you. Installing ASSP as a service requires several steps which are detailed in the <a href="http://apps.sourceforge.net/mediawiki/assp/index.php?title=Win32">Quick Start for Win32</a> doku page.<br /> Information about the Win32::Daemon module which which is necessary can be found here: <a href="http://www.roth.net/perl/Daemon/">The Official Win32::Daemon Home Page</a><br /><span class="negative"> requires ASSP restart</span>'],
-['AsADaemon','Run ASSP as a Daemon','0:No|1:Yes - externaly controlled|2:Yes - run AutoRestartCmd on restart and wait|3:Yes - run AutoRestartCmd on restart and exit',\&listbox,'0','(.*)',undef,'In Linux/BSD/Unix/OSX fork and close file handles. <br />
+['AsADaemon','Run ASSP as a Daemon','0:No|1:Yes - externaly controlled|2:Yes - run AutoRestartCmd on restart and wait|3:Yes - run AutoRestartCmd on restart and exit',\&listbox,'1','(.*)',undef,'In Linux/BSD/Unix/OSX fork and close file handles. <br />
  Similar to the command "perl assp.pl &amp;", but better.<br />
  If "externaly controlled" is selected, ASSP simply ends and you have to restart assp from your daemon or watchdog script<br />
  If "run AutoRestartCmd on restart and wait" is selected, assp starts the OS command defined in AutoRestartCmd - assp will <b>NOT !</b> automaticaly terminate - the started command has to terminate/kill and to (re)start assp - like "service assp restart"!<br />
  If "run AutoRestartCmd on restart and exit" is selected, assp starts the OS command defined in AutoRestartCmd and terminates immediatly!<br />
   <span class="negative"> requires ASSP restart</span>',undef,undef,'msg007440','msg007441'],
-['runAsUser','Run as UID',20,\&textinput,'','(\S*)',undef,'The *nix user name to assume after startup (*nix only).<p><small><i>Examples:</i> assp, nobody</small></p>
+['runAsUser','Run as UID',20,\&textinput,'assp','(\S*)',undef,'The *nix user name to assume after startup (*nix only).<p><small><i>Examples:</i> assp, nobody</small></p>
   <span class="negative"> Changing this requires a restart of ASSP.</span>'],
-['runAsGroup','Run as GID',20,\&textinput,'','(\S*)',undef,'The *nix group to assume after startup (*nix only).<p><small><i>Examples:</i> assp, nobody</small></p>
+['runAsGroup','Run as GID',20,\&textinput,'assp','(\S*)',undef,'The *nix group to assume after startup (*nix only).<p><small><i>Examples:</i> assp, nobody</small></p>
   <span class="negative"> Changing this requires a restart of ASSP.</span>'],
 ['ChangeRoot','Change Root',40,\&textinput,'','(.*)',undef,'The new root directory to which ASSP should chroot (*nix only). If blank, no chroot jail will be used. Note: if you use this feature, be sure to copy or link the etc/protocols file in your chroot jail.<br />
   <span class="negative"> Changing this requires a restart of ASSP.</span>'],
