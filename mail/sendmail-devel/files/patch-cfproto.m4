--- cf/m4/proto.m4.orig	2023-10-27 05:47:26 UTC
+++ cf/m4/proto.m4
@@ -2912,10 +2912,6 @@ R$* $| $#$*		$#$2
 R$* $| $*		$: $1', `dnl')
 ifdef(`_TLS_FAILURES_',`dnl
 R$*		$: $(macro {saved_verify} $@ $1 $) $1')
-ifdef(`_MTA_STS_', `dnl
-R$*			$: $1 $| $>"STS_secure" $1
-R$* $| $#$*		$#$2
-R$* $| $*		$: $1', `dnl')
 ifdef(`_ACCESS_TABLE_', `dnl
 dnl store name of other side
 R$*		$: $(macro {TLS_Name} $@ $&{server_name} $) $1
@@ -2923,6 +2919,10 @@ R$*		$: $1 $| $>D <$&{server_name}> <?> <! TLS_SRV_TAG
 R$* $| <?>$*	$: $1 $| $>A <$&{server_addr}> <?> <! TLS_SRV_TAG> <>
 dnl do a default lookup: just TLS_SRV_TAG
 R$* $| <?>$*	$: $1 $| <$(access TLS_SRV_TAG`'_TAG_DELIM_ $: ? $)>
+ifdef(`_MTA_STS_', `dnl
+R$*			$: $1 $| $>"STS_secure" $1
+R$* $| $#$*		$#$2
+R$* $| $*		$: $1', `dnl')
 ifdef(`_ATMPF_', `dnl tempfail?
 R$* $| <$* _ATMPF_>	$#error $@ 4.3.0 $: _TMPFMSG_(`TS')', `dnl')
 R$*		$@ $>"TLS_connection" $1', `dnl
