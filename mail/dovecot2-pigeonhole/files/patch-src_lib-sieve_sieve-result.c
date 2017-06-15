From 3e1a17a286ab0e084577fc267a442cb12aed1cbc Mon Sep 17 00:00:00 2001
From: Stephan Bosch <stephan.bosch@dovecot.fi>
Date: Fri, 28 Apr 2017 00:02:39 +0200
Subject: [PATCH] lib-sieve: Fixed bug in handling of deferred implicit keep
 with implicit side-effects.

Upon continuing the deferred implicit keep, the implicit side-effects (such as imap flags) were not applied.
---
 src/lib-sieve/sieve-result.c | 12 +++++++-----
 1 file changed, 7 insertions(+), 5 deletions(-)

diff --git a/src/lib-sieve/sieve-result.c b/src/lib-sieve/sieve-result.c
index 3c896f2..fc75063 100644
--- src/lib-sieve/sieve-result.c
+++ src/lib-sieve/sieve-result.c
@@ -969,7 +969,14 @@ static int _sieve_result_implicit_keep
 
 			rac = rac->next;
 		}
+	} else if ( !rollback ) {
+		act_keep.location = kac->action.location;
+		act_keep.mail = kac->action.mail;
+		if ( kac->seffects != NULL )
+			rsef_first = kac->seffects->first_effect;
+	}
 
+	if (rsef_first == NULL) {
 		/* Apply any implicit side effects if applicable */
 		if ( !rollback && hash_table_is_created(result->action_contexts) ) {
 			struct sieve_result_action_context *actctx;
@@ -980,11 +987,6 @@ static int _sieve_result_implicit_keep
 			if ( actctx != NULL && actctx->seffects != NULL )
 				rsef_first = actctx->seffects->first_effect;
 		}
-	} else if ( !rollback ) {
-		act_keep.location = kac->action.location;
-		act_keep.mail = kac->action.mail;
-		if ( kac->seffects != NULL )
-			rsef_first = kac->seffects->first_effect;
 	}
 
 	/* Start keep action */
