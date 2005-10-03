--- src/Language.pm.orig	Thu Aug 11 14:49:48 2005
+++ src/Language.pm	Mon Oct  3 10:05:04 2005
@@ -1,5 +1,5 @@
 # Language.pm - This module does just the initial setup for the international messages
-# RCS Identication ; $Revision: 1.40.2.4 $ ; $Date: 2005/08/11 12:49:48 $ 
+# RCS Identication ; $Revision: 1.40.2.5 $ ; $Date: 2005/09/23 15:39:34 $ 
 #
 # Sympa - SYsteme de Multi-Postage Automatique
 # Copyright (c) 1997, 1998, 1999, 2000, 2001 Comite Reseau des Universites
@@ -126,7 +126,7 @@
     }
    
     &Locale::Messages::textdomain("sympa");
-    &Locale::Messages::bindtextdomain('sympa','--DIR--/locale');
+    &Locale::Messages::bindtextdomain('sympa','--DIR--/share/locale');
     &Locale::Messages::bind_textdomain_codeset('sympa',$recode) if $recode;
     #bind_textdomain_codeset sympa => 'iso-8859-1';
 
@@ -134,16 +134,20 @@
     unless (setlocale(&POSIX::LC_ALL, $locale)) {
 	unless (setlocale(&POSIX::LC_ALL, $lang)) {
 	    unless (setlocale(&POSIX::LC_ALL, $locale.'.'.$locale2charset{$locale})) {
-		&do_log('err','Failed to setlocale(%s) ; you either have a problem with the catalogue .mo files or you should extend available locales in  your /etc/locale.gen (or /etc/sysconfig/i18n) file', $locale.'.'.$locale2charset{$locale});
-		return undef;
+		unless (setlocale(&POSIX::LC_ALL, $locale.'.'.uc($locale2charset{$locale}))) { ## UpperCase required for FreeBSD
+		    &do_log('err','Failed to setlocale(%s) ; you either have a problem with the catalogue .mo files or you should extend available locales in  your /etc/locale.gen (or /etc/sysconfig/i18n) file', $locale.'.'.uc($locale2charset{$locale}));
+		    return undef;
+		}
 	    }
 	}
     }
 
-    unless (setlocale(&POSIX::LC_TIME, $locale)) {
-	&do_log('err','Failed to setlocale(LC_TIME,%s)', $locale.'.'.$locale2charset{$locale});
-	return undef;
-    }
+## Problem with this, isn't LC_ALL suffiscient ?
+#
+#    unless (setlocale(&POSIX::LC_TIME, $locale)) {
+#	&do_log('err','Failed to setlocale(LC_TIME,%s)', $locale);
+#	return undef;
+#    }
 
     $current_lang = $lang;
     $current_locale = $locale;
