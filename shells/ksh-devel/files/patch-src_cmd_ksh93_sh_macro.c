diff --git src/cmd/ksh93/sh/macro.c.orig src/cmd/ksh93/sh/macro.c
index aba6f9d..0d60219 100644
--- src/cmd/ksh93/sh/macro.c.orig
+++ src/cmd/ksh93/sh/macro.c
@@ -2582,7 +2582,7 @@ static void endfield(Mac_t *mp,int split)
 		mp->atmode = 0;
 		if(mp->patfound)
 		{
-			int musttrim = mp->wasexpan && !mp->noextpat && strchr(argp->argval,'\\');
+			int musttrim = mp->wasexpan && !mp->quoted && !mp->noextpat && strchr(argp->argval,'\\');
 			sh.argaddr = 0;
 #if SHOPT_BRACEPAT
 			/* in POSIX mode, disallow brace expansion for unquoted expansions */
