--- rpcc/parse.yy.orig	Sat Jan 27 03:43:23 2001
+++ rpcc/parse.yy	Sun Dec  1 23:45:34 2002
@@ -1,4 +1,4 @@
-/* $Id: parse.yy,v 1.10 1999/05/14 00:16:01 dm Exp $ */
+/* $Id: parse.yy,v 1.11 2002/10/23 21:02:33 dm Exp $ */
 
 /*
  *
@@ -23,6 +23,7 @@
 
 %{
 #include "rpcc.h"
+#define YYSTYPE YYSTYPE
 
 static int proc_compare (const void *, const void *);
 static int vers_compare (const void *, const void *);
@@ -97,6 +98,7 @@
 	  s->sconst->id = $2;
 	  s->sconst->val = $4;
 	}
+	;
 
 def_enum: T_ENUM newid '{'
 	{
@@ -129,6 +131,7 @@
 	  s->sunion->tagid = $6;
 	}
 	union_taglist '}' ';'
+	;
 
 def_program: T_PROGRAM newid '{'
 	{
@@ -143,6 +146,7 @@
 	  qsort (s->sprogram->vers.base (), s->sprogram->vers.size (),
 		 sizeof (rpc_vers), vers_compare);
 	}
+	;
 
 version_list: version_decl | version_list version_decl
 	;
@@ -224,15 +228,19 @@
 
 struct_decl: declaration
 	{ symlist.back ().sstruct->decls.push_back ($1); }
+	;
 
 enum_taglist: enum_tag {}
 	| enum_taglist ',' enum_tag {}
+	;
 
 enum_tag: enum_cnstag
 	{ symlist.back ().senum->tags.push_back ($1); }
+	;
 
 enum_cnstag: newid '=' value { $$.id = $1; $$.val = $3; }
-	| newid { $$.id = $1; };
+	| newid { $$.id = $1; }
+	;
 
 declaration: type T_ID ';'
 	 { $$.id = $2; $$.type = $1; $$.qual = rpc_decl::SCALAR; }
