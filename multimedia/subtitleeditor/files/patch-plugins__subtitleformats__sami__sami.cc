--- ./plugins/subtitleformats/sami/sami.cc.orig	2011-06-18 10:05:15.000000000 +0200
+++ ./plugins/subtitleformats/sami/sami.cc	2011-12-14 22:24:57.000000000 +0100
@@ -155,7 +155,7 @@
 		int state = 0;
 		Glib::ustring line;
 		Glib::ustring text;
-		Subtitle* curSt;
+		Subtitle curSt;
 		char tmptext[MAXBUF+1] = "";
 		char *p = NULL, *q = NULL;
 		if (!file.getline(line))
@@ -174,8 +174,8 @@
 					start_sync = utility::string_to_int(inptr + 6);
 
 					// Get a line from the current subtitle on memory
-					curSt = &subtitles.append();
-					curSt->set_start(start_sync);
+					curSt = subtitles.append();
+					curSt.set_start(start_sync);
 
 					state = SAMI_STATE_SYNC_START;
 					continue;
@@ -239,14 +239,14 @@
 					// Now we are sure that this line is the end sync.
 
 					end_sync = utility::string_to_int(q + 6);
-					curSt->set_end(end_sync);
+					curSt.set_end(end_sync);
 
 					*p = '\0';
 					trail_space(tmptext);
 
 					// finalize the end sync of current line
 					if (tmptext[0] != '\0')
-						curSt->set_text(tmptext);
+						curSt.set_text(tmptext);
 
 					// an important check if this is end sync.
 					// Is there any delimiter "&nbsp;" in this line?
@@ -276,14 +276,14 @@
 				else
 				{
 					end_sync = SAMISYNC_MAXVAL;
-					curSt->set_end(end_sync);
+					curSt.set_end(end_sync);
 
 					*p = '\0';
 					trail_space(tmptext);
 
 					// finalize the end sync of current line
 					if (tmptext[0] != '\0')
-						curSt->set_text(tmptext);
+						curSt.set_text(tmptext);
 
 					state = SAMI_STATE_FORCE_QUIT;
 					break;
