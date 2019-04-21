--- src/lib/libcmd/ls.c.orig	2017-11-30 22:35:04 UTC
+++ src/lib/libcmd/ls.c
@@ -1257,7 +1257,7 @@ ls(State_t* state, register FTSENT* ent)
 	if (!VISIBLE(state, ent))
 	{
 		fts_set(NiL, ent, FTS_SKIP);
-		return;
+		return 0;
 	}
 	switch (ent->fts_info)
 	{
@@ -1265,17 +1265,17 @@ ls(State_t* state, register FTSENT* ent)
 		if (ent->fts_parent->fts_info == FTS_DNX)
 			break;
 		error(2, "%s: not found", ent->fts_path);
-		return;
+		return 1;
 	case FTS_DC:
 		if (state->lsflags & LS_DIRECTORY)
 			break;
 		error(2, "%s: directory causes cycle", ent->fts_path);
-		return;
+		return 1;
 	case FTS_DNR:
 		if (state->lsflags & LS_DIRECTORY)
 			break;
 		error(2, "%s: cannot read directory", ent->fts_path);
-		return 0;
+		return 1;
 	case FTS_DOT:
 		#if 0
 		fts_set(NiL, ent, FTS_SKIP);
