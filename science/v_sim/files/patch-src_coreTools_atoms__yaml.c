--- src/coreTools/atoms_yaml.c.orig	2020-07-07 14:26:13 UTC
+++ src/coreTools/atoms_yaml.c
@@ -1270,19 +1270,7 @@ static int posinp_yaml_forces(yaml_parser_t *parser, P
 
   return done;
 }
-#if SYSTEM_X11 == 1
-static char* strdup(const char *src)
-{
-  char *dest;
-  size_t ln;
 
-  ln = strlen(src);
-  dest = malloc(sizeof(char) * (ln + 1));
-  memcpy(dest, src, sizeof(char) * ln);
-  dest[ln] = '\0';
-  return dest;
-}
-#endif
 static int posinp_yaml_external_potential(const PosinpDict *dict, PosinpAtoms *atoms, char **message)
 {
   int done;
