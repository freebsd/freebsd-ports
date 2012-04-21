diff -pruN vdr-1.7.27-orig/channels.c vdr-1.7.27/channels.c
--- channels.c
+++ channels.c
@@ -955,7 +955,7 @@ int cChannels::MaxShortChannelNameLength
   if (!maxShortChannelNameLength) {
      for (cChannel *channel = First(); channel; channel = Next(channel)) {
          if (!channel->GroupSep())
-            maxShortChannelNameLength = max(Utf8StrLen(channel->ShortName()), maxShortChannelNameLength);
+            maxShortChannelNameLength = max(Utf8StrLen(channel->ShortName(true)), maxShortChannelNameLength);
          }
      }
   return maxShortChannelNameLength;
