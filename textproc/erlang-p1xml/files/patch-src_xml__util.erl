--- src/xml_util.erl.orig	2016-08-23 11:32:58 UTC
+++ src/xml_util.erl
@@ -29,58 +29,20 @@
 -export([binary_to_float/1, binary_to_integer/1, binary_to_integer/2,
 	 float_to_binary/1, integer_to_binary/1, integer_to_binary/2]).
 
--spec(binary_to_float/1 ::
-(
-  Binary :: binary())
-    -> float()
-).
-
 binary_to_float(Binary) ->
     list_to_float(binary_to_list(Binary)).
 
--spec(binary_to_integer/1 ::
-(
-  Binary :: binary())
-    -> integer()
-).
-
 binary_to_integer(Binary) ->
     list_to_integer(binary_to_list(Binary)).
 
--spec(binary_to_integer/2 ::
-(
-  Binary :: binary(),
-  Base   :: 2..36)
-    -> integer()
-).
-
 binary_to_integer(Binary, Base) ->
     list_to_integer(binary_to_list(Binary), Base).
 
--spec(float_to_binary/1 ::
-(
-  Float :: float())
-    -> binary()
-).
-
 float_to_binary(Float) ->
     list_to_binary(float_to_list(Float)).
 
--spec(integer_to_binary/1 ::
-(
-  Integer :: integer())
-    -> binary()
-).
-
 integer_to_binary(Integer) ->
     list_to_binary(integer_to_list(Integer)).
 
--spec(integer_to_binary/2 ::
-(
-  Integer :: integer(),
-  Base    :: 2..36)
-    -> binary()
-).
-
 integer_to_binary(Integer, Base) ->
     list_to_binary(integer_to_list(Integer, Base)).
