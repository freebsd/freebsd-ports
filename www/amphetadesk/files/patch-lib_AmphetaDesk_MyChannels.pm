--- lib/AmphetaDesk/MyChannels.pm.orig	Tue Oct 29 03:17:50 2002
+++ lib/AmphetaDesk/MyChannels.pm	Tue Oct 11 18:41:38 2005
@@ -359,9 +359,11 @@
 
    # count 'em.
    my $total_count = count_my_channels;
+   if ($total_count) {
    note("There was a total of $total_count subscribed channels.");
    note("We dance a drunken jig of epic proportions! " . 
            "<shake> <jiggle> <keRAASH!>...") if $total_count > 100;
+   }
 
    # resave the channels list
    # with the latest dates.
@@ -558,50 +560,41 @@
           title           => "Disobey.com's AmphetaDesk - News and Updates",
           xmlurl          => "http://www.disobey.com/amphetadesk/news.xml"
         },
-        "http://www.moreover.com/cgi-local/page?index_naturalhealth+rss" => {
-          date_added      => "2002-03-01 00:00:00",
-          date_downloaded => "2002-03-01 00:00:00",
-          description     => "Consumer: top stories - news headlines from around the web, refreshed every 15 minutes.",
-          filename        => "consumernaturalhealt.xml",
-          htmlurl         => "http://www.moreover.com/",
-          title           => "Consumer: natural health news",
-          xmlurl          => "http://www.moreover.com/cgi-local/page?index_naturalhealth+rss"
-        },
-        "http://www.gamegrene.com/rss/gamegrene.xml" => {
-          date_added      => "2002-03-01 00:00:00",
-          date_downloaded => "2002-03-01 00:00:00",
-          description     => "Filled with unique and interesting computer, tabletop, card, and roleplaying game columns, as well as daily news from the gaming community, Gamegrene.com is the perfect choice for the gamer who's sick of the typical.",
-          filename        => "gamegrenecom.xml",
-          htmlurl         => "http://www.gamegrene.com/",
-          title           => "Game Green? Games Phobia? Gamegrene.com!",
-          xmlurl          => "http://www.gamegrene.com/rss/gamegrene.xml"
+        "http://www.freebsd.org/news/news.rdf" => {
+          date_added      => "2005-10-11 00:00:00",
+          date_downloaded => "2005-10-11 00:00:00",
+          description     => "News from the FreeBSD Project",
+          filename        => "freebsdprojectnews.xml",
+          htmlurl         => "http://www.FreeBSD.org/news/",
+          title           => "FreeBSD Project News",
+          xmlurl          => "http://www.freebsd.org/news/news.rdf"
         },
-        "http://www.lockergnome.com/lockergnome.xml" => {
-          date_added      => "2002-03-01 00:00:00",
-          date_downloaded => "2002-03-01 00:00:00",
-          description     => "Free Technology E-mail Newsletters - Packed with 32-bit downloads (freeware / shareware), MP3s, multimedia, fonts, updates, tips, tricks, computer news, and more! We cater to curious users.",
-          filename        => "lockergnome.xml",
-          htmlurl         => "http://www.lockergnome.com/",
-          title           => "Lockergnome",
-          xmlurl          => "http://www.lockergnome.com/lockergnome.xml"
+        "http://www.freshports.org/news.php" => {
+          date_added      => "2005-10-11 00:00:00",
+          date_downloaded => "2005-10-11 00:00:00",
+          description     => "he easiest place to find ports",
+          filename        => "freshportstheplacefo.xml",
+          htmlurl         => "http://www.FreshPorts.org/",
+          title           => "FreshPorts -- The Place For Ports",
+          xmlurl          => "http://www.freshports.org/news.php"
         },
-        "http://www.researchbuzz.com/researchbuzz.rss" => {
-          date_added      => "2002-03-01 00:00:00",
-          date_downloaded => "2002-03-01 00:00:00",
-          description     => "News and information on search engines and other Internet research resources.",
-          filename        => "researchbuzz.xml",
-          htmlurl         => "http://www.researchbuzz.com/",
-          title           => "ResearchBuzz",
-          xmlurl          => "http://www.researchbuzz.com/researchbuzz.rss"
+        "http://www.oreillynet.com/feeds/author/?x-au=73&amp;x-mimetype=application/rdf+xm" => {
+          date_added      => "2005-10-11 00:00:00",
+          date_downloaded => "2005-10-11 00:00:00",
+          description     => "Dru Lavigne's O'Reilly Network Items: Weblogs, Articles, Hacks and Books",
+          filename        => "drulavigneoreillynet.xml",
+          htmlurl         => "http://www.oreillynet.com/pub/au/73",
+          title           => "Dru Lavigne, O'Reilly Network",
+          xmlurl          => "http://www.oreillynet.com/feeds/author/?x-au=73&amp;x-mimetype=application/rdf+xm"
         },
-        "http://www.reutershealth.com/eline.rss" => {
-          date_added      => "2002-03-01 00:00:00",
-          date_downloaded => "2002-03-01 00:00:00",
-          description     => "A daily look at the top consumer-oriented health-related news stories.",
-          filename        => "reutershealtheline.xml",
-          htmlurl         => "http://www.reutershealth.com/",
-          title           => "Reuters Health eLine",
-          xmlurl          => "http://www.reutershealth.com/eline.rss"
+        "http://daily.daemonnews.org/ddn.rdf.php3" => {
+          date_added      => "2005-10-11 00:00:00",
+          date_downloaded => "2005-10-11 00:00:00",
+          description     => "Daemon News PHP News System",
+          filename        => "bsdnews.xml",
+          htmlurl         => "http://bsdnews.com",
+          title           => "BSD News",
+          xmlurl          => "http://daily.daemonnews.org/ddn.rdf.php3"
         }
       );
 
