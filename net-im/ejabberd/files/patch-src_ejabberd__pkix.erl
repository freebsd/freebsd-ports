Source: https://github.com/processone/ejabberd/commit/e31f6409a657fedde63460ddee9fbd2e5c8a1eb2

--- src/ejabberd_pkix.erl.orig	2017-11-20 12:14:44 UTC
+++ src/ejabberd_pkix.erl
@@ -273,7 +273,7 @@ get_certfiles_from_config_options(State)
 		 undefined ->
 		     [];
 		 Paths ->
-		     lists:flatmap(fun filelib:wildcard/1, Paths)
+		     lists:flatmap(fun wildcard/1, Paths)
 	     end,
     Local = lists:flatmap(
 	      fun(OptHost) ->
@@ -527,7 +527,7 @@ certs_dir() ->
 -spec clean_dir(file:filename_all()) -> ok.
 clean_dir(Dir) ->
     ?DEBUG("Cleaning directory ~s", [Dir]),
-    Files = filelib:wildcard(filename:join(Dir, "*")),
+    Files = wildcard(filename:join(Dir, "*")),
     lists:foreach(
       fun(Path) ->
 	      case filelib:is_file(Path) of
@@ -540,7 +540,7 @@ clean_dir(Dir) ->
 
 -spec check_ca_dir() -> ok.
 check_ca_dir() ->
-    case filelib:wildcard(filename:join(ca_dir(), "*.0")) of
+    case wildcard(filename:join(ca_dir(), "*.0")) of
 	[] ->
 	    Hint = "configuring 'ca_path' option might help",
 	    case file:list_dir(ca_dir()) of
@@ -723,3 +723,8 @@ start_fs() ->
 		       [Reason]),
 	    false
     end.
+
+wildcard(Path) when is_binary(Path) ->
+    wildcard(binary_to_list(Path));
+wildcard(Path) ->
+    filelib:wildcard(Path).
