Source: https://github.com/potatosalad/erlang-jose/commit/833f81666a0f9fc31e7a3c2403d72e168a4a3209.patch

--- deps/jose/src/jose_server.erl.orig	2018-12-31 15:47:40 UTC
+++ deps/jose/src/jose_server.erl
@@ -162,9 +162,7 @@ support_check() ->
 
 %% @private
 check_ec_key_mode(_Fallback, Entries) ->
-	ECPEMEntry = {
-		'ECPrivateKey',
-		<<
+	PEMBin = <<
 			48,119,2,1,1,4,32,104,152,88,12,19,82,251,156,171,31,222,207,
 			0,76,115,88,210,229,36,106,137,192,81,153,154,254,226,38,247,
 			70,226,157,160,10,6,8,42,134,72,206,61,3,1,7,161,68,3,66,0,4,
@@ -173,13 +171,23 @@ check_ec_key_mode(_Fallback, Entries) ->
 			36,225,0,90,21,186,235,132,152,229,13,189,196,121,64,84,64,
 			229,173,12,24,23,127,175,67,247,29,139,91
 		>>,
-		not_encrypted
-	},
-	case public_key:pem_entry_decode(ECPEMEntry) of
-		#'ECPrivateKey'{ privateKey = PrivateKey, publicKey = PublicKey } when is_list(PrivateKey) andalso is_tuple(PublicKey) ->
-			[{ec_key_mode, list} | Entries];
-		#'ECPrivateKey'{ privateKey = PrivateKey, publicKey = PublicKey } when is_binary(PrivateKey) andalso is_binary(PublicKey) ->
-			[{ec_key_mode, binary} | Entries]
+	PEMEntry = {'ECPrivateKey', PEMBin, not_encrypted},
+	%% Erlang 24 changes 'ECPrivateKey' record in a way that makes record matching fail
+	%% when this module is compiled on Erlang 23 (or earlier) but runs on 24.
+	%% So we destructure tuples, as ugly as it may be.
+	%%
+	%% See erlang-jose#113 for details.
+	PrivateKey = case list_to_integer(erlang:system_info(otp_release)) >= 24 of
+		true ->
+			{'ECPrivateKey', _Version, PrivKey0, _Params, _PubKey0, _Attributes} = public_key:pem_entry_decode(PEMEntry),
+			PrivKey0;
+		false ->
+			{'ECPrivateKey', _Version, PrivKey0, _Params, _PubKey0} = public_key:pem_entry_decode(PEMEntry),
+			PrivKey0
+	end,
+	case is_binary(PrivateKey) of
+		true -> [{ec_key_mode, binary} | Entries];
+		_    -> [{ec_key_mode, list} | Entries]
 	end.
 
 %% @private
