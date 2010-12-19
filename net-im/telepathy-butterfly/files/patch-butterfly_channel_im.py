--- butterfly/channel/im.py.orig	2010-12-19 03:27:02.000000000 -0500
+++ butterfly/channel/im.py	2010-12-19 03:27:16.000000000 -0500
@@ -30,7 +30,7 @@ import papyon.event
 
 from butterfly.channel.text import ButterflyTextChannel
 
-from butterfly.Channel_Interface_Conference import CHANNEL_INTERFACE_CONFERENCE
+#from butterfly.Channel_Interface_Conference import CHANNEL_INTERFACE_CONFERENCE
 
 __all__ = ['ButterflyImChannel']
 
@@ -144,8 +144,8 @@ class ButterflyImChannel(ButterflyTextCh
         props = {
             telepathy.CHANNEL + '.ChannelType': dbus.String(telepathy.CHANNEL_TYPE_TEXT),
             telepathy.CHANNEL + '.TargetHandleType': dbus.UInt32(telepathy.HANDLE_TYPE_NONE),
-            CHANNEL_INTERFACE_CONFERENCE + '.InitialChannels': dbus.Array([self._object_path], signature='o'),
-            CHANNEL_INTERFACE_CONFERENCE + '.InitialInviteeIDs': dbus.Array([dbus.String(handle.get_name())], signature='s'),
+            telepathy.CHANNEL_INTERFACE_CONFERENCE + '.InitialChannels': dbus.Array([self._object_path], signature='o'),
+            telepathy.CHANNEL_INTERFACE_CONFERENCE + '.InitialInviteeIDs': dbus.Array([dbus.String(handle.get_name())], signature='s'),
             telepathy.CHANNEL + '.Requested': dbus.Boolean(False)
             }
 
