--- cf/m4/proto.m4.orig	2023-02-09 18:24:38 UTC
+++ cf/m4/proto.m4
@@ -2888,10 +2888,6 @@ R$*		$: $(macro {saved_verify} $@ $1 $) $1')
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
@@ -2899,6 +2895,10 @@ R$* $| <?>$*	$: $1 $| <$(access TLS_SRV_TAG`'_TAG_DELI
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
