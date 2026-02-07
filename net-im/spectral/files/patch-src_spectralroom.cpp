Avoid compiler error.

These two events cause template substitution errors. Since the
effect of removing them is that we don't get a nice name for
the events (user-facing), it's not essential.


--- src/spectralroom.cpp.orig	2020-06-15 18:48:37 UTC
+++ src/spectralroom.cpp
@@ -354,11 +354,13 @@ QString SpectralRoom::eventToString(const RoomEvent& e
         return tr("has set room aliases on server %1 to: %2")
             .arg(e.stateKey(), QLocale().createSeparatedList(e.aliases()));
       },
+/*
       [](const RoomCanonicalAliasEvent& e) {
         return (e.alias().isEmpty())
                    ? tr("cleared the room main alias")
                    : tr("set the room main alias to: %1").arg(e.alias());
       },
+*/
       [](const RoomNameEvent& e) {
         return (e.name().isEmpty()) ? tr("cleared the room name")
                                     : tr("set the room name to: %1")
@@ -372,9 +374,11 @@ QString SpectralRoom::eventToString(const RoomEvent& e
                                           : e.topic());
       },
       [](const RoomAvatarEvent&) { return tr("changed the room avatar"); },
+/*
       [](const EncryptionEvent&) {
         return tr("activated End-to-End Encryption");
       },
+*/
       [](const RoomCreateEvent& e) {
         return (e.isUpgrade() ? tr("upgraded the room to version %1")
                               : tr("created the room, version %1"))
