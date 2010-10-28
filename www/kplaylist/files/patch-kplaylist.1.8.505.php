--- kplaylist.1.8.505.php.orig	2010-10-28 16:21:51.000000000 +0800
+++ kplaylist.1.8.505.php	2010-10-28 16:27:03.000000000 +0800
@@ -155,7 +155,7 @@
 $cfg['lamecmd'] = '/usr/local/bin/lame --silent --nores --nohist --mp3input -h -m s -b %bitrate% "%file%" -';
 
 // ogg command  (transcode)
-$cfg['oggcmd'] = '/usr/bin/oggdec -Q "%file%" -o - | /usr/bin/oggenc - --quiet --managed -b %bitrate% -o -';
+$cfg['oggcmd'] = '/usr/local/bin/oggdec -Q "%file%" -o - | /usr/local/bin/oggenc - --quiet --managed -b %bitrate% -o -';
 
 // enable ogg transcoding, look the line above for the command, check this before enabling
 $cfg['oggtranscode'] = false;
@@ -166,7 +166,7 @@
 // YOU MUST SUIT THESE ARCHIVERS TO YOUR OWN NEED. DO NOT USE THE DEFAULT BLINDLY.
 $archivers = array();
 
-$archivers[] = array(1,	'zip', '/usr/bin/zip -j -0 %D "%F"', 'application/zip', 'zip');
+$archivers[] = array(1,	'zip', '/usr/local/bin/zip -j -0 %D "%F"', 'application/zip', 'zip');
 $archivers[] = array(1, 'tar','/bin/tar cf %D --files-from "%LIST"', 'application/x-tar', 'tar');
 $archivers[] = array(0,	'rar', 'C:\Programfiler\WinRAR\rar.exe -m0 a %D "%F"', 'application/x-rar', 'rar');
 
