Index: src/nat.c
===================================================================
--- src/nat.c	(revision 2445)
+++ src/nat.c	(revision 2446)
@@ -192,7 +192,7 @@ NatSetCommand(Context ctx, int ac, const char *const a
 	  if (!inet_aton (av[5], &r_addr))
 	    Error("bad remote IP address \"%s\"", av[5]);
 	  rp = atoi(av[6]);
-	  if (rp <= 0 || rp > 65535)
+	  if (rp < 0 || rp > 65535)
 	    Error("Incorrect remote port number \"%s\"", av[6]);
 	}
 	/* OK */
