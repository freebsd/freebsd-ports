*** adcomplain.pl.orig	Mon Feb 21 03:23:03 2000
--- adcomplain.pl	Mon Feb 21 03:24:27 2000
***************
*** 1,3 ****
--- 1,4 ----
+ #!%PERL5%
  #! /bin/sh -- # -*- perl -*-
  # first line invokes sh.  Some systems may need to refer to perl directly, i.e.:
  
***************
*** 7,14 ****
  # allows perl to be _anywhere_ in the user's path.  The intent is to reduce
  # the need to edit this file.
  
! eval 'exec perl $0 ${1+"$@"}'
! if 0;  # tee hee! This is on a separate line, so /bin/sh never sees it.
  
  # use strict;
  
--- 8,15 ----
  # allows perl to be _anywhere_ in the user's path.  The intent is to reduce
  # the need to edit this file.
  
! #eval 'exec perl $0 ${1+"$@"}'
! #if 0;  # tee hee! This is on a separate line, so /bin/sh never sees it.
  
  # use strict;
  
***************
*** 533,538 ****
--- 534,540 ----
    $quiet, 		# control flag, limits interaction and output
    %rematch_aliases,	# heuristic list, resets priority of another header
    $response, 		# text of letter we will send
+   @rusu_3level,         # 3rd level .RU/.SU exceptions
    $site, 		# site we will send the complaint to
    @site_exceptions,	# sites that have irregular syntactic form
    $subject, 		# subject header of the ad
***************
*** 2520,2526 ****
    ($site2 = $host) =~ s/.*\.(.*\..*)/$1/;
    ($site3 = $host) =~ s/.*\.(.*\..*\..*)/$1/;
    ($junk = $host) =~ s/.*\.(.*)/$1/;
!   if (length($junk) >= 3) {
      ($junk = $site3) =~ s/(\W)/\\$1/g;	# remove special characters
  
      if (grep(/^$junk$/, @site_exceptions) != 0) {
--- 2522,2538 ----
    ($site2 = $host) =~ s/.*\.(.*\..*)/$1/;
    ($site3 = $host) =~ s/.*\.(.*\..*\..*)/$1/;
    ($junk = $host) =~ s/.*\.(.*)/$1/;
!   if ($junk eq "ru" || $junk eq "su") {
!     ($junk = $site2) =~ s/(\W)/\\$1/g;	# remove special characters
! 
!     if (grep(/^$junk$/, @rusu_3level) != 0) {
!       $site = $site3;
!       }
!     else {
!       $site = $site2;
!       }
!   }
!   elsif (length($junk) >= 3) {
      ($junk = $site3) =~ s/(\W)/\\$1/g;	# remove special characters
  
      if (grep(/^$junk$/, @site_exceptions) != 0) {
***************
*** 2618,2623 ****
--- 2630,2636 ----
    # Pick the alias with the _most_ dots
    local($alias);
    foreach $alias (split(' ', $aliases)) {
+     $alias =~ s/\.$//;    # this adcomplain cannot deal with "foo.bar.com."
      $cd = ($alias =~ tr/././);
      if ($cd > $nd) {
        $result = $alias;
***************
*** 3077,3082 ****
--- 3090,3337 ----
  	'xs4all.nl',
  	);
      @site_exceptions = sort @site_exceptions; # needed for bsearch to work
+ 
+     @rusu_3level = (
+ 	'abkhazia.su',
+ 	'adygeya.ru',
+ 	'adygeya.su',
+ 	'aktyubinsk.su',
+ 	'alma-ata.su',
+ 	'altai.ru',
+ 	'altai.su',
+ 	'amur.ru',
+ 	'amur.su',
+ 	'amursk.ru',
+ 	'arkhangelsk.ru',
+ 	'arkhangelsk.su',
+ 	'armenia.su',
+ 	'ashgabad.su',
+ 	'astrakhan.ru',
+ 	'astrakhan.su',
+ 	'azerbaijan.su',
+ 	'baikal.ru',
+ 	'balashov.su',
+ 	'bashkiria.ru',
+ 	'bashkiria.su',
+ 	'belgorod.ru',
+ 	'belgorod.su',
+ 	'bir.ru',
+ 	'bishkek.su',
+ 	'bryansk.ru',
+ 	'bryansk.su',
+ 	'bukhara.su',
+ 	'buriatia.su',
+ 	'buryatia.ru',
+ 	'cbg.ru',
+ 	'chel.ru',
+ 	'chel.su',
+ 	'chelyabinsk.ru',
+ 	'chimkent.su',
+ 	'chita.ru',
+ 	'chita.su',
+ 	'chukotka.ru',
+ 	'chuvashia.ru',
+ 	'chuvashia.su',
+ 	'cmw.ru',
+ 	'com.ru',
+ 	'dagestan.ru',
+ 	'dagestan.su',
+ 	'dubna.su',
+ 	'dudinka.ru',
+ 	'e-burg.ru',
+ 	'e-burg.su',
+ 	'east-kazakhstan.su',
+ 	'engels.su',
+ 	'fareast.ru',
+ 	'georgia.su',
+ 	'grozny.ru',
+ 	'grozny.su',
+ 	'irkutsk.ru',
+ 	'irkutsk.su',
+ 	'ivanovo.ru',
+ 	'ivanovo.su',
+ 	'izhevsk.ru',
+ 	'jamal.ru',
+ 	'jambyl.su',
+ 	'jar.ru',
+ 	'joshkar-ola.ru',
+ 	'k-uralsk.ru',
+ 	'kalmykia.ru',
+ 	'kalmykia.su',
+ 	'kaluga.ru',
+ 	'kaluga.su',
+ 	'kamchatka.ru',
+ 	'kamchatka.su',
+ 	'karacol.su',
+ 	'karaganda.su',
+ 	'karakol.su',
+ 	'karelia.ru',
+ 	'karelia.su',
+ 	'kazan.ru',
+ 	'kazan.su',
+ 	'kchr.ru',
+ 	'kemerovo.ru',
+ 	'kemerovo.su',
+ 	'khabarovsk.ru',
+ 	'khabarovsk.su',
+ 	'khakassia.ru',
+ 	'khakassia.su',
+ 	'khv.ru',
+ 	'kirov.ru',
+ 	'kms.ru',
+ 	'koenig.ru',
+ 	'koenig.su',
+ 	'komi.ru',
+ 	'komi.su',
+ 	'kostroma.ru',
+ 	'kostroma.su',
+ 	'krasnodar.su',
+ 	'krasnoyarsk.ru',
+ 	'krasnoyarsk.su',
+ 	'kuban.ru',
+ 	'kuban.su',
+ 	'kurgan.ru',
+ 	'kurgan.su',
+ 	'kursk.ru',
+ 	'kursk.su',
+ 	'kustanai.ru',
+ 	'kustanai.su',
+ 	'kuzbass.ru',
+ 	'lipetsk.ru',
+ 	'lipetsk.su',
+ 	'magadan.ru',
+ 	'magadan.su',
+ 	'magnitka.ru',
+ 	'mangyshlak.su',
+ 	'mari-el.ru',
+ 	'mari.ru',
+ 	'mari.su',
+ 	'marine.ru',
+ 	'marine.su',
+ 	'moldova.su',
+ 	'mordovia.ru',
+ 	'mordovia.su',
+ 	'mosreg.ru',
+ 	'msk.ru',
+ 	'msk.su',
+ 	'murmansk.ru',
+ 	'murmansk.su',
+ 	'mytis.ru',
+ 	'nakhodka.ru',
+ 	'nalchik.ru',
+ 	'nalchik.su',
+ 	'naryn.su',
+ 	'navoi.su',
+ 	'net.ru',
+ 	'nkz.ru',
+ 	'nnov.ru',
+ 	'nnov.su',
+ 	'norilsk.ru',
+ 	'north-kazakhstan.su',
+ 	'nov.ru',
+ 	'nov.su',
+ 	'novosibirsk.ru',
+ 	'nsk.ru',
+ 	'nsk.su',
+ 	'obninsk.su',
+ 	'omsk.ru',
+ 	'omsk.su',
+ 	'orenburg.ru',
+ 	'orenburg.su',
+ 	'org.ru',
+ 	'oryol.ru',
+ 	'oryol.su',
+ 	'osh.su',
+ 	'oskol.ru',
+ 	'palana.ru',
+ 	'pavlodar.su',
+ 	'penza.ru',
+ 	'penza.su',
+ 	'perm.ru',
+ 	'perm.su',
+ 	'pokrovsk.su',
+ 	'pp.ru',
+ 	'pskov.ru',
+ 	'pskov.su',
+ 	'ptz.ru',
+ 	'pyatigorsk.ru',
+ 	'pyatigorsk.su',
+ 	'rnd.ru',
+ 	'rostov-na-donu.su',
+ 	'rubtsovsk.ru',
+ 	'ryazan.ru',
+ 	'ryazan.su',
+ 	'sakhalin.ru',
+ 	'sakhalin.su',
+ 	'samara.ru',
+ 	'samara.su',
+ 	'saratov.ru',
+ 	'saratov.su',
+ 	'semsk.su',
+ 	'serpukhov.su',
+ 	'simbirsk.ru',
+ 	'simbirsk.su',
+ 	'smolensk.ru',
+ 	'smolensk.su',
+ 	'sochi.su',
+ 	'spb.ru',
+ 	'spb.su',
+ 	'stavropol.ru',
+ 	'stavropol.su',
+ 	'stv.ru',
+ 	'surgut.ru',
+ 	'surgut.su',
+ 	'syzran.ru',
+ 	'tambov.ru',
+ 	'tambov.su',
+ 	'tashkent.su',
+ 	'tatarstan.ru',
+ 	'termez.su',
+ 	'togliatti.su',
+ 	'tom.ru',
+ 	'tomsk.ru',
+ 	'tomsk.su',
+ 	'troitsk.su',
+ 	'tsaritsyn.ru',
+ 	'tsaritsyn.su',
+ 	'tselinograd.su',
+ 	'tsk.ru',
+ 	'tula.ru',
+ 	'tula.su',
+ 	'tuva.ru',
+ 	'tuva.su',
+ 	'tver.ru',
+ 	'tver.su',
+ 	'tyumen.ru',
+ 	'tyumen.su',
+ 	'udm.ru',
+ 	'udmurtia.ru',
+ 	'udmurtia.su',
+ 	'ulan-ude.ru',
+ 	'vdonsk.ru',
+ 	'vladikavkaz.ru',
+ 	'vladikavkaz.su',
+ 	'vladimir.ru',
+ 	'vladimir.su',
+ 	'vladivostok.ru',
+ 	'volgograd.ru',
+ 	'vologda.ru',
+ 	'vologda.su',
+ 	'voronezh.ru',
+ 	'voronezh.su',
+ 	'vrn.ru',
+ 	'vyatka.ru',
+ 	'vyatka.su',
+ 	'yakutia.ru',
+ 	'yakutia.su',
+ 	'yamal.ru',
+ 	'yaroslavl.ru',
+ 	'yaroslavl.su',
+ 	'yekaterinburg.ru',
+ 	'yuzhno-sakhalinsk.ru',
+ 	'zgrad.ru',
+ 	'zgrad.su',
+     );
  
      %rematch_aliases = (
      'nonexistent.com',  'X-NNTP-Posting-Host:',
