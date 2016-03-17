--- dbeacon.cpp.orig	2016-03-15 16:06:23.135551000 -0700
+++ dbeacon.cpp	2016-03-15 16:08:13.104873000 -0700
@@ -1498,7 +1498,7 @@
 			fprintf(fp, " contact=\"%s\"", adminContact.c_str());
 		if (!twoLetterCC.empty())
 			fprintf(fp, " country=\"%s\"", twoLetterCC.c_str());
-		fprintf(fp, " age=\"%llu\" lastupdate=\"0\" rxlocal=\"true\">\n", (now - startTime) / 1000);
+		fprintf(fp, " age=\"%lu\" lastupdate=\"0\" rxlocal=\"true\">\n", (now - startTime) / 1000);
 
 		for (uint32_t k = 0; k < KnownFlags; k++) {
 			if (flags & (1 << k)) {
@@ -1526,8 +1526,8 @@
 			if (!i->second.CC.empty())
 				fprintf(fp, " country=\"%s\"", i->second.CC.c_str());
 
-			fprintf(fp, " age=\"%llu\"", (now - i->second.creation) / 1000);
-			fprintf(fp, " lastupdate=\"%llu\">\n", (now - i->second.lastevent) / 1000);
+			fprintf(fp, " age=\"%lu\"", (now - i->second.creation) / 1000);
+			fprintf(fp, " lastupdate=\"%lu\">\n", (now - i->second.lastevent) / 1000);
 
 			if (i->second.ASM.s.valid)
 				dumpStats(fp, "asm", i->second.ASM.s, now, i->second.sttl, true);
@@ -1552,9 +1552,9 @@
 		}
 		i->first.print(tmp, sizeof(tmp));
 		fprintf(fp, " addr=\"%s\"", tmp);
-		fprintf(fp, " age=\"%llu\"", (now - i->second.creation) / 1000);
+		fprintf(fp, " age=\"%lu\"", (now - i->second.creation) / 1000);
 		fprintf(fp, " rxlocal=\"%s\"", i->second.rxlocal(now) ? "true" : "false");
-		fprintf(fp, " lastupdate=\"%llu\">\n", (now - i->second.lastevent) / 1000);
+		fprintf(fp, " lastupdate=\"%lu\">\n", (now - i->second.lastevent) / 1000);
 
 		for (uint32_t k = 0; k < KnownFlags; k++) {
 			if (i->second.Flags & (1 << k)) {
