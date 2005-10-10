--- lib/AmphetaDesk/MyChannels.pm.orig	Sun Oct  9 22:43:13 2005
+++ lib/AmphetaDesk/MyChannels.pm	Sun Oct  9 22:47:00 2005
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
