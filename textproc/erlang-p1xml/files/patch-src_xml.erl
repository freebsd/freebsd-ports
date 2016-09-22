--- src/xml.erl.orig	2016-08-23 11:33:47 UTC
+++ src/xml.erl
@@ -98,21 +98,11 @@ terminate(_Reason, _State) ->
     ok.
 
 %%
--spec(element_to_binary/1 ::
-(
-  El :: xmlel() | cdata())
-    -> binary()
-).
 
 element_to_binary(El) ->
     iolist_to_binary(element_to_string(El)).
 
 %%
--spec(element_to_string/1 ::
-(
-  El :: xmlel() | cdata())
-    -> string()
-).
 
 element_to_string(El) ->
     case catch element_to_string_nocatch(El) of
@@ -120,12 +110,6 @@ element_to_string(El) ->
       Result -> Result
     end.
 
--spec(element_to_string_nocatch/1 ::
-(
-  El :: xmlel() | cdata())
-    -> iolist()
-).
-
 element_to_string_nocatch(El) ->
     case El of
       #xmlel{name = Name, attrs = Attrs, children = Els} ->
@@ -157,11 +141,6 @@ crypt(S) ->
        || <<C>> <= S >>.
 
 %%
--spec(make_text_node/1 ::
-(
-  CData :: binary())
-    -> binary()
-).
 
 make_text_node(CData) ->
     case cdata_need_escape(CData) of
@@ -221,34 +200,17 @@ escape_cdata(CData, Index, [Pos | Positi
 		 [CDATA2, Part, CDATA1 | Acc]).
 
 %%
--spec(remove_cdata_p/1 ::
-(
-  El :: xmlel() | cdata())
-    -> boolean()
-).
 
 remove_cdata_p(#xmlel{}) -> true;
 remove_cdata_p(_) -> false.
 
 %%
--spec(remove_cdata/1 ::
-(
-  L :: [xmlel() | cdata()])
-    -> [xmlel()]
-).
 
 remove_cdata(L) -> [E || E <- L, remove_cdata_p(E)].
 
 %% This function is intended to remove subtags based on a name and an
 %% attribute, usually an xmlns attribute for a specific XMPP
 %% extension.
--spec(remove_subtags/3 ::
-(
-  Xmlel :: xmlel(),
-  Name  :: binary(),
-  Attr  :: attr())
-    -> Xmlel :: xmlel()
-).
 
 remove_subtags(#xmlel{name = TagName, attrs = TagAttrs, children = Els},
   Name, Attr) ->
@@ -256,14 +218,6 @@ remove_subtags(#xmlel{name = TagName, at
         children = remove_subtags1(Els, [], Name, Attr)}.
 
 %%
--spec(remove_subtags1/4 ::
-(
-  Els    :: [xmlel() | cdata()],
-  NewEls :: [xmlel()],
-  Name   :: binary(),
-  Attr   :: attr())
-    -> NewEls :: [xmlel()]
-).
 
 remove_subtags1([], NewEls, _Name, _Attr) ->
     lists:reverse(NewEls);
@@ -281,43 +235,17 @@ remove_subtags1([El | Els], NewEls, Name
       _ -> remove_subtags1(Els, [El | NewEls], Name, Attr)
     end.
 
--spec(get_cdata/1 ::
-(
-  L :: [xmlel() | cdata()])
-    -> binary()
-).
-
 get_cdata(L) ->
     (iolist_to_binary(get_cdata(L, <<"">>))).
 
--spec(get_cdata/2 ::
-(
-  L :: [xmlel() | cdata()],
-  S :: binary() | iolist())
-    -> binary() | iolist()
-).
-
 get_cdata([{xmlcdata, CData} | L], S) ->
      get_cdata(L, [S, CData]);
 get_cdata([_ | L], S) -> get_cdata(L, S);
 get_cdata([], S) -> S.
 
--spec(get_tag_cdata/1 ::
-(
-  Xmlel :: xmlel())
-    -> binary()
-).
-
 get_tag_cdata(#xmlel{children = Els}) -> get_cdata(Els).
 
 %%
--spec(get_attr/2 ::
-(
-  AttrName :: binary(),
-  Attrs    :: [attr()])
-    -> {value, binary()}
-     | false
-).
 
 get_attr(AttrName, Attrs) ->
     case lists:keysearch(AttrName, 1, Attrs) of
@@ -326,12 +254,6 @@ get_attr(AttrName, Attrs) ->
     end.
 
 %%
--spec(get_attr_s/2 ::
-(
-  AttrName :: binary(),
-  Attrs    :: [attr()])
-    -> Val :: binary()
-).
 
 get_attr_s(AttrName, Attrs) ->
     case lists:keysearch(AttrName, 1, Attrs) of
@@ -340,46 +262,21 @@ get_attr_s(AttrName, Attrs) ->
     end.
 
 %%
--spec(get_tag_attr/2 ::
-(
-  AttrName :: binary(),
-  Xmlel    :: xmlel())
-    -> {value, binary()}
-     | false
-).
 
 get_tag_attr(AttrName, #xmlel{attrs = Attrs}) ->
     get_attr(AttrName, Attrs).
 
 %%
--spec(get_tag_attr_s/2 ::
-(
-  AttrName :: binary(),
-  Xmlel    :: xmlel())
-    -> binary()
-).
 
 get_tag_attr_s(AttrName, #xmlel{attrs = Attrs}) ->
     get_attr_s(AttrName, Attrs).
 
 %%
--spec(get_subtag/2 ::
-(
-  Xmlel :: xmlel(),
-  Name  :: binary())
-    -> xmlel() | false
-).
 
 get_subtag(#xmlel{children = Els}, Name) ->
     get_subtag1(Els, Name).
 
 %%
--spec(get_subtag1/2 ::
-(
-  Els  :: [xmlel() | cdata()],
-  Name :: binary())
-    -> xmlel() | false
-).
 
 get_subtag1( [El | Els], Name) ->
     case El of
@@ -388,13 +285,6 @@ get_subtag1( [El | Els], Name) ->
     end;
 get_subtag1([], _) -> false.
 
--spec(get_subtags/2 ::
-(
-  Xmlel :: xmlel(),
-  Name  :: binary())
-    -> [xmlel()]
-).
-
 get_subtags(#xmlel{children = Els}, Name) ->
     get_subtags1(Els, Name, []).
 
@@ -407,25 +297,11 @@ get_subtags1([El | Els], Name, Acc) ->
     end.
 
 %%
--spec(get_subtag_with_xmlns/3 ::
-(
-  Xmlel :: xmlel(),
-  Name  :: binary(),
-  XMLNS :: binary())
-    -> xmlel() | false
-).
 
 get_subtag_with_xmlns(#xmlel{children = Els}, Name, XMLNS) ->
     get_subtag_with_xmlns1(Els, Name, XMLNS).
 
 %%
--spec(get_subtag_with_xmlns1/3 ::
-(
-  Els  :: [xmlel() | cdata()],
-  Name :: binary(),
-  XMLNS :: binary())
-    -> xmlel() | false
-).
 
 get_subtag_with_xmlns1([El | Els], Name, XMLNS) ->
     case El of
@@ -442,14 +318,6 @@ get_subtag_with_xmlns1([El | Els], Name,
 get_subtag_with_xmlns1([], _, _) ->
     false.
 
--spec(get_subtags_with_xmlns/3 ::
-(
-  Xmlel :: xmlel(),
-  Name  :: binary(),
-  XMLNS :: binary())
-    -> [xmlel()]
-).
-
 get_subtags_with_xmlns(#xmlel{children = Els}, Name, XMLNS) ->
     get_subtags_with_xmlns1(Els, Name, XMLNS, []).
 
@@ -469,12 +337,6 @@ get_subtags_with_xmlns1([El | Els], Name
     end.
 
 %%
--spec(get_subtag_cdata/2 ::
-(
-  Tag  :: xmlel(),
-  Name :: binary())
-    -> binary()
-).
 
 get_subtag_cdata(Tag, Name) ->
     case get_subtag(Tag, Name) of
@@ -483,26 +345,11 @@ get_subtag_cdata(Tag, Name) ->
     end.
 
 %%
--spec(append_subtags/2 ::
-(
-  Xmlel    :: xmlel(),
-  SubTags2 :: [xmlel() | cdata()])
-    -> Xmlel :: xmlel()
-).
 
 append_subtags(#xmlel{name = Name, attrs = Attrs, children = SubTags1}, SubTags2) ->
     #xmlel{name = Name, attrs = Attrs, children = SubTags1 ++ SubTags2}.
 
 %%
--spec(get_path_s/2 ::
-(
-  El   :: xmlel(),
-  Path :: [{elem, Name::binary()}
-          |{attr, Name::binary()}
-          |cdata])
-    -> xmlel()
-     | binary()
-).
 
 get_path_s(El, []) -> El;
 get_path_s(El, [{elem, Name} | Path]) ->
@@ -515,35 +362,12 @@ get_path_s(El, [{attr, Name}]) ->
 get_path_s(El, [cdata]) -> get_tag_cdata(El).
 
 %%
--spec(replace_tag_attr/3 ::
-(
-  Name  :: binary(),
-  Value :: binary(),
-  Xmlel :: xmlel())
-    -> Xmlel :: #xmlel{
-           name     :: binary(),
-           attrs    :: [attr(),...],
-           children :: [xmlel() | cdata()]
-       }
-).
 
 replace_tag_attr(Name, Value, Xmlel) ->
     Xmlel#xmlel{
         attrs = [{Name, Value} | lists:keydelete(Name, 1, Xmlel#xmlel.attrs)]
     }.
 
-
--spec(replace_subtag/2 ::
-(
-  Tag   :: xmlel(),
-  Xmlel :: xmlel())
-    -> Xmlel :: #xmlel{
-           name     :: binary(),
-           attrs    :: [attr(),...],
-           children :: [xmlel() | cdata()]
-       }
-).
-
 replace_subtag(#xmlel{name = Name} = Tag, Xmlel) ->
     Xmlel#xmlel{
         children = [Tag | lists:keydelete(Name, #xmlel.name, Xmlel#xmlel.children)]
