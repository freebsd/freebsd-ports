--- src/cddb_fill.cc.orig
+++ src/cddb_fill.cc
@@ -30,6 +30,9 @@
 #include <string>
 #include <algorithm>
 #include <cdio/cdio.h>
+#if LIBCDIO_VERSION_NUM < 90
+#include <cdio/cdda.h>
+#endif
 #include <cdio/cdtext.h>
 
 using namespace std;
@@ -93,17 +96,39 @@
 	kprintf("device %p\n", cdio);
 
 	/* get disc artist and title */
+#if LIBCDIO_VERSION_NUM < 90
+	cdtext_t *cdtext = cdio_get_cdtext(cdio, 0);
+#else
 	cdtext_t *cdtext = cdio_get_cdtext(cdio);
+#endif
 	if (cdtext) {
+#if LIBCDIO_VERSION_NUM < 90
+		if (cdtext->field[CDTEXT_PERFORMER])
+			cd_info.artist = cdtext->field[CDTEXT_PERFORMER];
+		if (cdtext->field[CDTEXT_TITLE])
+			cd_info.cdname = cdtext->field[CDTEXT_TITLE];
+		if (cdtext->field[CDTEXT_DISCID])
+			cd_info.cddb_id =
+				strtoul(cdtext->field[CDTEXT_DISCID], NULL, 16);
+#else
 		cd_info.artist = cdtext_get(cdtext, CDTEXT_FIELD_PERFORMER, 0);
 		cd_info.cdname = cdtext_get(cdtext, CDTEXT_FIELD_TITLE, 0);
 		cd_info.cddb_id = strtoul(cdtext_get(cdtext, CDTEXT_FIELD_DISCID, 0), NULL, 16);
+#endif
 	}
 
 	for (int i = 1; i <= cd_info.ntracks; i++) {
+#if LIBCDIO_VERSION_NUM < 90
+		cdtext_t *cdtext = cdio_get_cdtext(cdio, i);
+#endif
 		trackinfo *blub = new trackinfo();
 		blub->track = i;
+#if LIBCDIO_VERSION_NUM < 90
+		if (cdtext->field[CDTEXT_TITLE])
+			blub->name = cdtext->field[CDTEXT_TITLE];
+#else
 		blub->name = cdtext_get(cdtext, CDTEXT_FIELD_TITLE, i);
+#endif
 		cd_info.tracks.push_back(blub);
 
 	}
