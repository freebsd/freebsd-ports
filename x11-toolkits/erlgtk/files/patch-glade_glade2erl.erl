
$FreeBSD$

--- glade/glade2erl.erl.orig	Thu May  2 08:42:20 2002
+++ glade/glade2erl.erl	Sat Jul 19 12:19:25 2003
@@ -1335,7 +1335,7 @@
 			     fmt_args(Ps++[{raw,fmt_flags(OffBits,FSpec)}])])
 	    end,
 	    emit_spec(C,Ps,Name,T,As);
-	{cond,Type,Then,Else} ->
+	{conditional,Type,Then,Else} ->
 	    case eval_cond(Type,As) of
 		true -> 
 		    emit_spec(C,Ps,Name,Then, As),
@@ -1437,12 +1437,12 @@
 %%
 %% ChildrenSpec = none | box | container | notebook ...
 %% 
-%% {create,{Mod,Fun},Args}    unconditional call returning a new widget
-%% {call,{Mod,Fun},Args}      unconditional call
-%% {def,{Mod,Fun},Args}       optional call (ignore if default value on args)
+%% {create,{Mod,Fun},Args}      unconditional call returning a new widget
+%% {call,{Mod,Fun},Args}        unconditional call
+%% {def,{Mod,Fun},Args}         optional call (ignore if default value on args)
 %% {flags,SetF,UnsetF,Default,Flags}  
-%%                            special call for setting flag arguments
-%% {cond,Cond,Then,Else}      conditional 
+%%                              special call for setting flag arguments
+%% {conditional,Cond,Then,Else} conditional 
 %%
 widget_spec(DefaultFlags) ->
     [
@@ -1474,7 +1474,7 @@
       [{"selection_mode",genum,'GTK_SELECTION_SINGLE'}]},
      {def,{gtk,clist_set_shadow_type},
       [{"shadow_type",genum,'GTK_SHADOW_IN'}]},
-     {cond, {value,"show_titles",false},
+     {conditional, {value,"show_titles",false},
       [{call,{gtk,clist_column_titles_show},[]}],
       [{call,{gtk,clist_column_titles_hide},[]}]}
      | container_spec(?GTK_CAN_FOCUS bor Flags)].
@@ -1827,7 +1827,7 @@
 
 	"GtkButton" ->
 	    S = [
-		 {cond,  {member,"stock_button"},
+		 {conditional,  {member,"stock_button"},
 		  [{create,{gnome_stock,button},
 		    [{"stock_button", {gmacro,Type}, "Button"}]}],
 		  [{create,{gtk,button_new_with_label},
@@ -1976,7 +1976,7 @@
 	    S = [
 		 {create,{gtk,menu_item_new_with_label},
 		  [{"label", gstring, Name}]},
-		 {cond, {value,"right_justify",false},
+		 {conditional, {value,"right_justify",false},
 		  [{call,{gtk,menu_item_right_justify},[]}],
 		  []} | container_spec(0)],
 	    {S, menuitem};
@@ -2086,7 +2086,7 @@
 		    ex(UnSetF, Ps++[OffBits])
 	    end,
 	    exec_spec(Ps,T,As);
-	{cond,Type,Then,Else} ->
+	{conditional,Type,Then,Else} ->
 	    case eval_cond(Type,As) of
 		true -> 
 		    exec_spec(Ps, Then++T, As);
