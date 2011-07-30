--- backends/telepathy/lib/tpf-persona-store.vala.orig	2011-07-22 14:19:09.000000000 +0200
+++ backends/telepathy/lib/tpf-persona-store.vala	2011-07-22 14:30:40.000000000 +0200
@@ -22,7 +22,6 @@
 using GLib;
 using Gee;
 using TelepathyGLib;
-using TelepathyGLib.ContactFeature;
 using Folks;
 
 /**
@@ -36,6 +35,15 @@ public class Tpf.PersonaStore : Folks.Pe
 {
   private string[] undisplayed_groups = { "publish", "stored", "subscribe" };
 
+  private static ContactFeature[] _contact_features =
+      {
+        ContactFeature.ALIAS,
+        ContactFeature.AVATAR_DATA,
+        ContactFeature.AVATAR_TOKEN,
+        ContactFeature.CAPABILITIES,
+        ContactFeature.PRESENCE
+      };
+
   private HashTable<string, Persona> _personas;
   /* universal, contact owner handles (not channel-specific) */
   private HashMap<uint, Persona> handle_persona_map;
@@ -407,7 +415,7 @@ public class Tpf.PersonaStore : Folks.Pe
       if (change_maps.size < 1)
         return;
 
-      foreach (var entry in change_maps)
+      foreach (var entry in change_maps.entries)
         {
           var changes = entry.key;
 
@@ -640,7 +648,7 @@ public class Tpf.PersonaStore : Folks.Pe
       /*
        * remove all persona-keyed entries
        */
-      foreach (var entry in this.channel_group_personas_map)
+      foreach (var entry in this.channel_group_personas_map.entries)
         {
           var channel = (Channel) entry.key;
           var members = this.channel_group_personas_map[channel];
@@ -648,9 +656,8 @@ public class Tpf.PersonaStore : Folks.Pe
             members.remove (persona);
         }
 
-      foreach (var entry in this.group_outgoing_adds)
+      foreach (var name in this.group_outgoing_adds.keys)
         {
-          var name = (string) entry.key;
           var members = this.group_outgoing_adds[name];
           if (members != null)
             members.remove (persona);
@@ -866,14 +873,6 @@ public class Tpf.PersonaStore : Folks.Pe
       Channel channel,
       Array<uint> channel_handles)
     {
-      ContactFeature[] features =
-        {
-          ALIAS,
-          AVATAR_DATA,
-          AVATAR_TOKEN,
-          PRESENCE
-        };
-
       uint[] contact_handles = {};
       for (var i = 0; i < channel_handles.length; i++)
         {
@@ -891,7 +890,7 @@ public class Tpf.PersonaStore : Folks.Pe
 
           GLib.List<TelepathyGLib.Contact> contacts =
               yield this.ll.connection_get_contacts_by_handle_async (
-                  this.conn, contact_handles, (uint[]) features);
+                  this.conn, contact_handles, (uint[]) _contact_features);
 
           if (contacts == null || contacts.length () < 1)
             return;
@@ -918,19 +917,11 @@ public class Tpf.PersonaStore : Folks.Pe
   private async GLib.List<Tpf.Persona>? create_personas_from_contact_ids (
       string[] contact_ids) throws GLib.Error
     {
-      ContactFeature[] features =
-        {
-          ALIAS,
-          AVATAR_DATA,
-          AVATAR_TOKEN,
-          PRESENCE
-        };
-
       if (contact_ids.length > 0)
         {
           GLib.List<TelepathyGLib.Contact> contacts =
               yield this.ll.connection_get_contacts_by_id_async (
-                  this.conn, contact_ids, (uint[]) features);
+                  this.conn, contact_ids, (uint[]) _contact_features);
 
           GLib.List<Persona> personas = new GLib.List<Persona> ();
           uint err_count = 0;
@@ -1027,7 +1018,7 @@ public class Tpf.PersonaStore : Folks.Pe
 
   private void channel_groups_add_new_personas ()
     {
-      foreach (var entry in this.channel_group_incoming_adds)
+      foreach (var entry in this.channel_group_incoming_adds.entries)
         {
           var channel = (Channel) entry.key;
           var members_added = new GLib.List<Persona> ();
