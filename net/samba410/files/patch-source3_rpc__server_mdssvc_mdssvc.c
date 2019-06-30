../source3/rpc_server/mdssvc/mdssvc.c:157:9: error: format specifies type 'unsigned long' but the argument has type 'size_t' (aka 'unsigned int') [-Werror,-Wformat]
                                    dalloc_size(dd));
                                    ^~~~~~~~~~~~~~~

--- source3/rpc_server/mdssvc/mdssvc.c.orig	2019-04-09 01:04:10 UTC
+++ source3/rpc_server/mdssvc/mdssvc.c
@@ -151,7 +151,7 @@ char *mds_dalloc_dump(DALLOC_CTX *dd, in
 	}
 
 	logstring = talloc_asprintf(dd,
-				    "%s%s(#%lu): {\n",
+				    "%s%s(#%zu): {\n",
 				    tab_string1,
 				    talloc_get_name(dd),
 				    dalloc_size(dd));
